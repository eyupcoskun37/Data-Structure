#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[20];
    int number;
    struct Student *next;
};

typedef struct Student node;

node *Insertion(node *head)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    printf("name: ");
    scanf(" %[^\n]", newNode->name); // boşluklu isimler için

    printf("number: ");
    scanf("%d", &newNode->number);
    getchar(); // \n temizle

    newNode->next = head;
    head = newNode;

    return head;
}

node *Deletion(node *head, int value)
{
    node *iter = head;
    node *temp;

    if (head != NULL && head->number == value)
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("Student deleted.\n");
        return head;
    }

    while (iter->next != NULL && iter->next->number != value)
    {
        iter = iter->next;
    }

    if (iter->next == NULL)
    {
        printf("Student not found.\n");
        return head;
    }

    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    printf("Student deleted.\n");
    return head;
}

node *SearchOperation(node *head, int value)
{
    node *iter = head;

    while (iter != NULL)
    {
        if (iter->number == value)
        {
            printf("Wanted student found: %s\n", iter->name);
            return head;
        }
        iter = iter->next;
    }

    printf("There are no students wanted\n");
    return head;
}

void PrintList(node *head)
{
    node *iter = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    while (iter != NULL)
    {
        printf("Name: %s | Number: %d\n", iter->name, iter->number);
        iter = iter->next;
    }
}

int main()
{
    node *head = NULL;
    int choice, num;

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Add student\n");
        printf("2. Delete student\n");
        printf("3. Search student\n");
        printf("4. Show all students\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar(); // Enter temizle

        switch (choice)
        {
        case 1:
            head = Insertion(head);
            break;

        case 2:
            printf("Enter the student number to delete: ");
            scanf("%d", &num);
            head = Deletion(head, num);
            break;

        case 3:
            printf("Enter the student number to search: ");
            scanf("%d", &num);
            head = SearchOperation(head, num);
            break;

        case 4:
            PrintList(head);
            break;

        case 0:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }
}
