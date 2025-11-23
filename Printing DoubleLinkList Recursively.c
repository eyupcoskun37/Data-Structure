#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node node;

node* newDNode(int data) //Create a new node
{
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void printForward(node* head) // Recursive printing in forward direction
{
    if (head == NULL)
    {   
        return;
    }

    printf("%d ", head->data);
    printForward(head->next);
}

void printBackward(node* tail) // Recursive printing in reverse direction
{
    if (tail == NULL)
    {   
        return;
    }

    printf("%d ", tail->data);
    printBackward(tail->prev);
}

int main() {
    node* head = newDNode(10);
    node* n2 = newDNode(20);
    node* n3 = newDNode(30); // List : 10 <-> 20 <-> 30

    head->next = n2;
    n2->prev = head;
    n2->next = n3;
    n3->prev = n2;

    printf("Double Linked List forward: ");
    printForward(head);
    printf("\n");

    printf("Double Linked List backward: ");
    printBackward(n3);
    printf("\n");

    return 0;
}
