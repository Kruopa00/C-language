#include <stdio.h>
#include <stdlib.h>
#include "hellomake.h"

// Function to split nodes of the given doubly linked list into
// two halves using the fast/slow pointer strategy
void split(struct node *head, struct node **left, struct node **right)
{
    struct node *slow = head;
    struct node *fast = head -> next;

    // Advance `fast` by two nodes, and advance `slow` by a single node
    while (fast != NULL)
    {
        fast = fast -> next;
        if (fast != NULL)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    }

    *right = slow -> next;
    slow -> next = NULL;
}

// Recursive function to merge nodes of two sorted lists
// into a single sorted list
struct node *merge(struct node *left, struct node *right)
{
    // Base case
    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    // Pick either 'left' or 'right', and recur
    if (left -> data <= right -> data)
    {
        left -> next = merge(left -> next, right);
        left -> next -> last = left;
        left -> last = NULL;
        return left;
    }

    else
    {
        right -> next = merge(left, right -> next);
        right -> next -> last = right;
        right -> last = NULL;
        return right;
    }
}

// Function to sort a doubly-linked list using merge sort algorithm
void merge_sort(struct node **head)
{
    // Base case: 0 or 1 node
    if (*head == NULL || (*head) -> next == NULL)
        return;
    
    // Split head into left side and right side sublists
    struct node *left = *head;
    struct node *right = NULL;
    split(*head, &left, &right);

    // Recursively sort the sublists
    merge_sort(&left);
    merge_sort(&right);

    // Merge the two sorted lists
    *head = merge(left, right);
}