/*
Vytautas Krupavičius
LSP: 2110582
Užduotis 4, variantas 12
*/
#ifndef node_H
#define node_H

struct node
{
	int data; 
	// Pointer to next
	struct node *next;

	// Pointer to previous
	struct node *last; 
};

#endif

void data_from_file(struct node **head, char file_name[]);
void text_to_screen();
int get_user_menu_choice();
void insert_at_head(struct node **headRef, int number);
void split(struct node *head, struct node **left, struct node **right);
struct node *merge(struct node *left, struct node *right);
void merge_sort(struct node **head);
void output_to_screen(struct node *head);
int value_to_insert();
void clear(struct node **head);
void about_me();