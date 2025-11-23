#include <stdio.h>

void Hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    Hanoi(n-1, from, aux, to);          
    printf("Move disk %d from %c to %c\n", n, from, to); 
    Hanoi(n-1, aux, to, from);          
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    
    printf("\nSteps to solve Towers of Hanoi:\n");
    Hanoi(n, 'A', 'C', 'B');
    
    return 0;
}

// Time Complexity: Function Hanoi(n-1) call 2 times = O(2^n)


/*   Hanoi(3, A, C, B)
    |
    |-- Hanoi(2, A, B, C)
    |   |
    |   |-- Hanoi(1, A, C, B)  -> Move disk 1 A->C
    |   |-- Move disk 2 A->B
    |   |-- Hanoi(1, C, B, A)  -> Move disk 1 C->B
    |
    |-- Move disk 3 A->C
    |
    |-- Hanoi(2, B, C, A)
        |
        |-- Hanoi(1, B, A, C) -> Move disk 1 B->A
        |-- Move disk 2 B->C
        |-- Hanoi(1, A, C, B) -> Move disk 1 A->C   */

