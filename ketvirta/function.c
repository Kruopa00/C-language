#include <stdio.h>   // malloc(), realloc(), free(), fgets()
#include <stdlib.h>  // NULL, size_t
#include <string.h>  // strlen(), strcpy(), strcat()
#include <ctype.h>   // isdigit()
#include "hellomake.h"

void data_from_file(struct node **head, char file_name[])
{

    FILE *input_file = NULL;
    input_file = fopen(file_name, "r");

    if(!input_file){

        fprintf(stderr, "Couldn't open \"%s\" for reading :(\nPlease check it and try again.\n", file_name);
        return;
    }

    fprintf(stderr, "File opened successfully. :))\n");

    int check_if_end = fgetc(input_file);

    if (check_if_end == EOF) {
        printf("File is empty\n");
	    return;
    }
     
    else
        ungetc(check_if_end, input_file);

    int input;

    while(!feof(input_file)){

        if(fscanf(input_file, "%d", &input) == 0){

            printf("Detected incorrect characters in file, check the file and try again");
            exit(1);
        }

        insert_at_head(head, input);
    }

    printf("List created!\n");
}


void insert_at_head(struct node **headRef, int number)
{ 
	struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node -> data = number;
    new_node -> last = NULL;
    new_node -> next = *headRef;

    // change `last` of the existing head node to point to the new node
    if (*headRef != NULL) {
        (*headRef) -> last = new_node;
    }
 
    // update head pointer
    *headRef = new_node;
}


void output_to_screen(struct node *head)
{ 

	int element = 1;

	if (head == NULL)
    {
		printf("Your list is empty!\n");
	}

    else
	{    
        while (head != NULL)
        {
            printf("%d element: %d\n", element, head -> data);
            head = head -> next;
            element++;
        }
    }

}

void clear(struct node **head)
{

    struct node *remove = *head;

    while(*head != NULL){
        *head = (*head) -> next;

        free(remove);

        remove = *head;
    }
}