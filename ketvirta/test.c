#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "hellomake.h"


struct node *for_test = NULL;

void test_elements();
void test_file_input();
void test_element_merge_sort();

int main(){

    test_elements();
    test_file_input();
    test_element_merge_sort();

    fprintf(stderr, "\nTests compiled successfully.\n");
    fprintf(stderr, "Goodbye!\n");

    system("PAUSE");
    exit(0);
}

void test_elements(){

    // List is empty
    insert_at_head(&for_test, 1);
    assert(for_test -> data == 1);

    insert_at_head(&for_test, 100);

    insert_at_head(&for_test, 0);

    // Head won`t change
    insert_at_head(&for_test, -1);
    assert(for_test -> data == -1);

    clear(&for_test);
}

void test_file_input(){

    char empty[20] = "empty.txt";
    char test[20] = "test.txt";

    data_from_file(&for_test, empty);
    assert(for_test == NULL);

    int results[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    data_from_file(&for_test, test);

    for(int i = 9; i >= 0; i--){

        assert( (for_test -> data) == results[i]);
        for_test = for_test -> next;
    }

    clear(&for_test);
}

void test_element_merge_sort(){
    // Insert random elements in to list

    insert_at_head(&for_test, 17);
    insert_at_head(&for_test, 5);
    insert_at_head(&for_test, 28);
    insert_at_head(&for_test, -2);
    insert_at_head(&for_test, 1);
    insert_at_head(&for_test, 0);
    merge_sort(&for_test);
    
    assert((for_test -> data) == -2);

    // Cheking if numbers insert at begging of list

    insert_at_head(&for_test, 28);

    assert((for_test -> data) == 28);

    merge_sort(&for_test);

    assert((for_test -> data) == -2);

    
    clear(&for_test);
    assert(for_test == NULL);
}
