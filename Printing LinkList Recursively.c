#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
};

typedef struct node node;

node *createList(int n) // Create List
{
    node *head = NULL;
    node *iter = NULL;

    for (int i = 0; i < n; i++)
    {
        node *newNode = (node *)malloc(sizeof(node));
        printf("Enter %d. number: ", i + 1);
        scanf("%d", &newNode->number);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            iter = head;
        }
        else
        {
            iter->next = newNode;
            iter = iter->next;
        }
    }

    return head;
}

void recursivePrintSF(node *head) // Printing from beginning to end (recursive)
{
    if (head == NULL)
        return;
    printf("%d ", head->number);
    recursivePrintSF(head->next);
}

void recursivePrintFS(node *head) // Printing from end to beginning (recursive)
{
    if (head == NULL)
        return;
    recursivePrintFS(head->next);
    printf("%d ", head->number);
}

int main()
{
    node *head = NULL;
    int n;

    printf("How many numbers do you want to enter? ");
    scanf("%d", &n);

    head = createList(n);

    printf("\nPrinting from Start to Finish:\n");
    recursivePrintSF(head);

    printf("\nPrinting from Finish to Start:\n");
    recursivePrintFS(head);

    return 0;
}
