#include <stddef.h>  // size_t
#include <stdlib.h>  // EXIT_SUCCESS, EXIT_FAILURE
#include <stdio.h>   // malloc(), realloc(), free(), fgets()
#include <string.h>  // strlen(), strcpy(), strcat()
//#include <conio.h>   // getch()

enum { BUFFER_SIZE = 256 };  // whatever line length you suspect the input file to be + 1

struct data{
    char buffer[BUFFER_SIZE];
};
//void find(size_t num_lines, char lines[]);

int main()
{   
    struct data data[BUFFER_SIZE];


    FILE *is = NULL;
    printf("Please Enter file you want to open: \n");


    while(1) {
        char filename[BUFFER_SIZE];
        fscanf(stdin,"%s", filename);
        strncat(filename, ".txt", 255);
        is = fopen(filename, "r");
        if (is)
            break;
        fprintf(stderr, "Couldn't open \"%s\" for reading :(\nPlease try again: \n", filename);
    }

    int result = EXIT_SUCCESS;  // assume a happy ending
    size_t num_lines = 0;
    char **lines = NULL;
    size_t line_length[BUFFER_SIZE];

    while (fgets(data[num_lines].buffer, sizeof(data[num_lines].buffer), is)) {
        ++num_lines;
        char **temp = realloc(lines, num_lines * sizeof(*lines));
        if (!temp) {
            fputs("Not enough memory :(\n\n", stderr);
            fclose(is);
            result = EXIT_FAILURE;
            goto cleanup;
        }

        lines = temp;

        size_t length = strlen(data[num_lines - 1].buffer);
        length = strlen(data[num_lines - 1].buffer);

        // remove a trailing newline if any:
        if (length && data[num_lines - 1].buffer[length - 1] == '\n')
            data[num_lines - 1].buffer[--length] = '\0';

        line_length[num_lines - 1] = length;
        lines[num_lines - 1] = malloc((length + 1) * sizeof(*lines));
        if (!lines[num_lines - 1]) {
            fputs("Not enough memory :(\n\n", stderr);
            fclose(is);
            result = EXIT_FAILURE;
            goto cleanup;
        }

        strcpy(lines[num_lines - 1], data[num_lines - 1].buffer);

        // as long as the buffer has been filled completely by the previous
        // call to fgets() and a next call to fgets() also succeeds:
        while (length == BUFFER_SIZE - 1 && fgets(data[num_lines - 1].buffer, sizeof(data[num_lines - 1].buffer), is)) {
            length = strlen(data[num_lines - 1].buffer);

            // remove a trailing newline if any:
            if (length && data[num_lines - 1].buffer[length - 1] == '\n')
                data[num_lines - 1].buffer[--length] = '\0';

            char *temp = realloc(lines[num_lines - 1], line_length[num_lines - 1] + length + 1);
            if (!temp) {
                fputs("Not enough memory :(\n\n", stderr);
                fclose(is);
                result = EXIT_FAILURE;
                goto cleanup;
            }
            lines[num_lines - 1] = temp;
            strcpy(lines[num_lines - 1] + line_length[num_lines - 1], data[num_lines - 1].buffer);
            line_length[num_lines - 1] += length;
        }

    }
    fclose(is);

                /*for(size_t i = 0; i < num_lines; ++i)
                {
                    for(size_t j = 0; j < strlen(lines[i]); ++j)
                    {
                        printf("%c ", data[i].buffer[j]);
                    }
                printf("\n\n");
                }*/
        
    // use lines:
    for (size_t i = 0; i < num_lines; ++i)
        puts(lines[i]);

cleanup:
    for (size_t i = 0; i < num_lines; ++i)
        free(lines[i]);
    free(lines);
    return result;
}
