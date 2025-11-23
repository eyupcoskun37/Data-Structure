#include <stdio.h>

int main() {
    int rows = 3, cols = 3;
    int matrix[3][3] = {{0, 0, 3},
                        {4, 0, 0},
                        {0, 5, 6}};
    

    printf("Original Matrix:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nSparse representation [row column value]:\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (matrix[i][j] != 0) 
            {
                printf("%d\t%d\t%d\n", i, j, matrix[i][j]);
            }
        }
    }

    return 0;
}