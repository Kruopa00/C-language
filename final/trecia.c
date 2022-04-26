#include <stddef.h>  // size_t
#include <stdlib.h>  // EXIT_SUCCESS, EXIT_FAILURE
#include <stdio.h>   // malloc(), realloc(), free(), fgets()
#include <string.h>  // strlen(), strcpy(), strcat()
#include "hellomake.h"

enum { BUFFER_SIZE = 255 };  // line length the input file to be + 1  for /0

void cleanup(size_t num_lines, char **lines, int result);

int main()
{   
    FILE *is = NULL;
    printf("Please Enter file you want to open: \n");

    // checking input file name
    while(1) {
        char filename[BUFFER_SIZE];
        fscanf(stdin,"%s", filename);
        strncat(filename, ".txt", 254);
        is = fopen(filename, "r");
        if (is)
            break;
        fprintf(stderr, "Couldn't open \"%s\" for reading :(\nPlease try again: \n", filename);
    }

    int result = EXIT_SUCCESS;  // assume a happy ending
    size_t num_lines = 0;
    char buffer[BUFFER_SIZE];
    char **lines = NULL;
    size_t line_length[BUFFER_SIZE];

    while (fgets(buffer, sizeof(buffer), is)) {
        ++num_lines;
        char **temp = realloc(lines, num_lines * sizeof(*lines));
        if (!temp) {
            fputs("Not enough memory :(\n\n", stderr);
            fclose(is);
            result = EXIT_FAILURE;
            cleanup(num_lines, lines, result);
        }

        lines = temp;

        size_t length = strlen(buffer);
        length = strlen(buffer);

        // remove a trailing newline if any:
        if (length && buffer[length - 1] == '\n')
            buffer[--length] = '\0';

        line_length[num_lines - 1] = length;
        lines[num_lines - 1] = malloc((length + 1) * sizeof(*lines));
        if (!lines[num_lines - 1]) {
            fputs("Not enough memory :(\n\n", stderr);
            fclose(is);
            result = EXIT_FAILURE;
            cleanup(num_lines, lines, result);
        }

        strcpy(lines[num_lines - 1], buffer);

        //read numbeers after {BUFFER_SIZE} and dont save anywhere.
        while (length == BUFFER_SIZE - 1 && fgets(buffer, sizeof(buffer), is)) { 
            length = strlen(buffer);

            // remove a trailing newline if any:
            if (length && buffer[length - 1] == '\n')
                buffer[--length] = '\0';

            char *temp = realloc(lines[num_lines - 1], line_length[num_lines - 1] + length + 1);
            if (!temp) {
                fputs("Not enough memory :(\n\n", stderr);
                fclose(is);
                result = EXIT_FAILURE;
                cleanup(num_lines, lines, result);
            }
        }
    }
    fclose(is);

    
    Moves_the_line(num_lines, lines);
    Output(num_lines, lines);

    fputs("Program compiled successfully, enter any character and press enter to close progarm:\n", stderr);
    fscanf(stdin, "%255s");

    cleanup(num_lines, lines, result);
}
void cleanup(size_t num_lines, char **lines, int result)
{
    for (size_t i = 0; i < num_lines; ++i)
        free(lines[i]);
    free(lines);
    result;
}