#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *next;
} Node;


void printList(Node *head) /* Printing the list */
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


void sortDescending(Node *head) /* Sort from largest to smallest */
{
    if (head == NULL)
        return;

    Node *i, *j;
    int temp;

    for (i = head; i->next != NULL; i = i->next) 
    {
        for (j = i->next; j != NULL; j = j->next) 
        {
            if (i->data < j->data) 
            { 
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main() 
{
    Node *head = NULL, *temp = NULL, *newNode = NULL;
    int n, val;

    printf("How many staff will you include? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);

        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) 
        {
            head = newNode;   
        } 
        
        else 
        {
            temp->next = newNode; 
        }
        temp = newNode;
    }

    printf("\nEntered list:\n");
    printList(head);

    sortDescending(head);

    printf("\nList sorted from largest to smallest:\n");
    printList(head);

    return 0;
}
