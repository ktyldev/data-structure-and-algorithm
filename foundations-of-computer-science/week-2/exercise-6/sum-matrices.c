#include <stdio.h>

void printMatrix(int (*matrix)[2]);

int main()
{
    int first[2][2] = 
    {
        { 1, 2 },
        { 3, 4 }
    };
    int second[2][2] =
    {
        { 3, 4 },
        { 5, 6 }
    };
    int result[2][2];

    printf("Matrix 1:\n");
    printMatrix(first);
    printf("Matrix 2:\n");
    printMatrix(second);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
   
    printf("Result:\n");
    printMatrix(result);
}

void printMatrix(int (*matrix)[2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
