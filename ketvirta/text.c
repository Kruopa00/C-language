#include <stdio.h>
#include "hellomake.h"

void text_to_screen()
{
    fprintf(stderr, "\nHello, this program creates a two-sided list that you can easily modify!\n");

    fprintf(stderr, "\nAll commands:\n");
    fprintf(stderr, "Number 0 - creates a list.\n");
    fprintf(stderr, "Number 1 - prints out a sorted list.\n");
    fprintf(stderr, "Number 2 - inserts the value you specify in the list.\n");
    fprintf(stderr, "Number 3 - about program and creator.\n");
    fprintf(stderr, "Number 4 - closes the program\n");

}

int get_user_menu_choice()
{ 
    int input;

    fprintf(stderr, "\nPlease enter number: ");
    while(1){
        while(scanf("%d", &input) != 2 && getchar() != '\n')
        {
            while(getchar() != '\n');

            fprintf(stderr, "\nWrong input!\n");
            fprintf(stderr, "Please try again: ");
        }

        if (0 <= input <= 4)
            break;

        fprintf(stderr, "\nYou entered wrong number!!\n");
        fprintf(stderr, "Please try again: ");
    }

    return input;
}

int value_to_insert()
{
    int number;

    printf("\n");
    fprintf(stderr, "Number you want to insert to the list: ");
    while(scanf("%d", &number) != 2 && getchar() != '\n'){
        while (getchar() != '\n');

        fprintf(stderr, "\nWrong input!! Please double check before you press enter!\n");
        fprintf(stderr, "please try again: ");
    }
    return number;
}

void about_me(){
    fprintf(stderr, "Hello, my name is Vytautas, my LSP: 2110582, I am SE student from VU.\n");
    fprintf(stderr, "This program was created for my programing lecture.\n");
    fprintf(stderr, "Program created: 2021/12/12\n");
    fprintf(stderr, "Last edit: 2021/12/20\n");
    fprintf(stderr, "Version 1.0.0\n");
}