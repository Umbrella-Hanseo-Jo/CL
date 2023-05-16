//Dynamic Matrix Allocation (Rows: i, Columns: j)
#include <stdio.h>
#include <stdlib.h>


int main() {
    int i, j;
    int** matrix;

    printf("Enter the number of rows, i: ");
    scanf("%d", &i);

    printf("Ennter the number of cols, j: ");
    scanf("%d", &j);

    //Dynamic allocation of the matrix
    matrix = (int**)malloc(i*sizeof(int*));

    for (int row = 0; row < i; row++) {
        matrix[row] = (int*)malloc(j * sizeof(int));
    }

    //Filling matrix values
    int count = 1;
    for (int row = 0; row < i; row++) {
        for (int col = 0; col < j; col ++) {
            matrix[row][col] = count;
            count++; 
        }
    }

    //Matrix printing
    printf("The Matrix:\n");
    for (int row = 0; row < i; row++) {
        for (int col = 0; col < j; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }

    //Memory deallocation
    for (int row = 0; row < i; row++) {
        free(matrix[row]);
    }
    free(matrix);

    return 0;
}