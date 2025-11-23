#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createCircularList() /* Creates a circular list (e.g. 5 elements) */
{
    Node *head = NULL, *temp = NULL, *newNode = NULL;

    for (int i = 1; i <= 5; i++)
    {
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = i;
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

    temp->next = head; // circular
    return head;
}

void printCircularList(Node *head) /* Print the elements in the circular list */
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;

    printf("Elements in a circular list:\n");

    do // since it is a circular list, do-while
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(came back to the first element)\n");
}

int main()
{
    Node *head = createCircularList();
    printCircularList(head);
    return 0;
}
