#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *next;
} Node;


void deleteListRecursive(Node *head) /* Recursively deletes all nodes */
{
    if (head == NULL)
    {
        return;
    }

    deleteListRecursive(head->next);
    free(head);
}

void printList(Node *head) // Printing list
{
    if (head == NULL) 
    {
        printf("Liste bos.\n");
        return;
    }

    Node *temp = head;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() 
{
    // Create a list with 5 elements (1 -> 2 -> 3 -> 4 -> 5)
    Node *head = malloc(sizeof(Node));
    head->data = 1;
    head->next = malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 3;
    head->next->next->next = malloc(sizeof(Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = malloc(sizeof(Node));
    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = NULL;

    printf("List before deletion:\n");
    printList(head);
    
    deleteListRecursive(head); // Delete recursively
    head = NULL;

    printf("\nList after deletion:\n");
    printList(head);

    return 0;
}
