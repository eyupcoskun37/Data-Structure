#include <stdio.h>

#define MAX 100

int arr[MAX];
int size = 0; // for empty array

/
void insertAtBeginning(int value) {
    for(int i = size; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = value;
    size++;
}

void insertAtEnd(int value) {
    arr[size] = value;
    size++;
}

void insertAtIndex(int index, int value) {
    if(index < 0 || index > size) {
        printf("Invalid index!\n");
        return;
    }
    for(int i = size; i > index; i--) {
        arr[i] = arr[i-1];
    }
    arr[index] = value;
    size++;
}

void deleteAtIndex(int index) {
    if(index < 0 || index >= size) {
        printf("Invalid index!\n");
        return;
    }
    for(int i = index; i < size-1; i++) {
        arr[i] = arr[i+1];
    }
    size--;
}


int search(int value) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == value)
            return i; // found, return index
    }
    return -1; // Not found
}

void printArray() {
    if(size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, value, index;

    while(1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at index\n");
        printf("4. Delete at index\n");
        printf("5. Search\n");
        printf("6. Print array\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter index and value to insert: ");
                scanf("%d %d", &index, &value);
                insertAtIndex(index, value);
                break;
            case 4:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                deleteAtIndex(index);
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                index = search(value);
                if(index != -1)
                    printf("Value found at index %d\n", index);
                else
                    printf("Value not found\n");
                break;
            case 6:
                printArray();
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
