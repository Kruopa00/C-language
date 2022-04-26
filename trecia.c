#include <stddef.h>  // size_t
#include <stdlib.h>  // EXIT_SUCCESS, EXIT_FAILURE
#include <stdio.h>   // malloc(), realloc(), free(), fgets()
#include <string.h>  // strlen(), strcpy(), strcat()
//#include <hellomake.h>

enum { BUFFER_SIZE = 256 };  // line length the input file to be + 1  for /0


int main()
{   

    FILE *is = NULL;
    printf("Please Enter file you want to open: \n");

    // checking input file name
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
            goto cleanup;
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
            goto cleanup;
        }

        strcpy(lines[num_lines - 1], buffer);

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
                goto cleanup;
            }
            lines[num_lines - 1] = temp;
            strcpy(lines[num_lines - 1] + line_length[num_lines - 1], buffer);
            line_length[num_lines - 1] += length;
        }
    }
    fclose(is);

    FILE *fp;

    fputs("Please enter file name where output will be:\n", stderr);

    while(1) {
        char filename[BUFFER_SIZE];
        fscanf(stdin,"%255s", filename);
        strncat(filename, ".txt", 255);
        fp = fopen(filename, "w");
        if (fp)
            break;
        
        fputs("Please double check.\nA file name can`t contain any of following characters:\n", stderr);
        fputs("               / : * ? < > | \n", stderr);
        fputs("Please enter file name where output will be:\n", stderr);        
        }

        //void Moves_the_line(num_lines, lines);
        for(size_t i = 0; i < num_lines; ++i){
            size_t temp = strlen(lines[i]);

            if((lines[i][temp - 1] == '-') && (lines[i][temp - 2] != ' ') && (temp > 1) && (strlen(lines[i + 1]) > 1)){
                size_t number = 0;

                lines[i][temp - 1] = '\0';

                while((lines[i + 1][number] != ' ') && (lines[i + 1][number] != '\0')){
                    strncat(lines[i], &lines[i + 1][number], sizeof(lines[i + 1][number]));
                    number++;
                }
                for(size_t j = 0; j <= number; ++j)
                    strcpy(lines[i + 1], lines[i + 1] + 1);
            } 
        }

    for (size_t i = 0; i < num_lines - 1; ++i)
        fprintf(fp, "%s\n", lines[i]);
    fprintf(fp, "%s", lines[num_lines - 1]);
    fclose(fp);

cleanup:
    for (size_t i = 0; i < num_lines; ++i)
        free(lines[i]);
    free(lines);
    return result;
}
