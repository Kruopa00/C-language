#include <stddef.h>  // size_t
#include <stdlib.h>  // EXIT_SUCCESS, EXIT_FAILURE
#include <stdio.h>   // malloc(), realloc(), free(), fgets()
#include <string.h>  // strlen(), strcpy(), strcat()
#include "hellomake.h"

void Output(size_t num_lines, char **lines){
    FILE *fp;

    fputs("Please enter file name where output will be:\n", stderr);

    while(1) {
        char filename[256];
        fscanf(stdin,"%255s", filename);
        strncat(filename, ".txt", 255);
        fp = fopen(filename, "w");
        if (fp)
            break;
        
        fputs("Please double check.\nA file name can`t contain any of following characters:\n", stderr);
        fputs("               / : * ? < > | \n", stderr);
        fputs("Please enter file name where output will be:\n", stderr);        
        }

    for (size_t i = 0; i < num_lines - 1; ++i)
        fprintf(fp, "%s\n", lines[i]);
    fprintf(fp, "%s", lines[num_lines - 1]);
    fclose(fp);
    
    return;
}