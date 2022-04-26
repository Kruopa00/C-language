#include <stdio.h>   // malloc(), realloc(), free(), fgets()
#include <stdlib.h>  // NULL, size_t, system(), exit()
#include <string.h>  // strlen(), strcpy(), strcat()
#include <ctype.h>   // isdigit()
#include "hellomake.h"

struct node *head = NULL;

void close_program();

int main()
{

    char file_name[26] = "";

    text_to_screen();

    while (1)
    {
        int user_input = get_user_menu_choice();

        switch(user_input)
        {
            case 4:
                close_program();

            case 3:  
                about_me();
                break;

            case 2: 
                insert_at_head(&head, value_to_insert());
                break; 

            case 1: 
                merge_sort(&head);
                output_to_screen(head); 
                break;
                
            case 0:
                fprintf(stderr, "Please Enter file you want to open: \n");

                fscanf(stdin,"%s", file_name);
                strncat(file_name, ".txt", 21);

                data_from_file(&head, file_name);
                break;
        }
    }
    
    system("PAUSE");
    return 0;
}

void close_program()
{
    fprintf(stderr, "Program compiled successfully.\n");
    fprintf(stderr, "Goodbye!\n");

    system("PAUSE");
    exit(0);
}