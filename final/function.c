#include <stddef.h>  // size_t
#include <stdio.h>   // malloc(), realloc(), free(), fgets()
#include <string.h>  // strlen(), strcpy(), strcat()
#include "hellomake.h"


void Moves_the_line(size_t num_lines, char **lines)
{
    
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
    return;
}
