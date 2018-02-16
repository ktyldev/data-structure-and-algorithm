#include <stdio.h>
#include <stdlib.h>

int main()
{
    int temps[2][7] = 
    {
        { 20, 21, 22, 20, 19, 23, 18 },
        { 12, 11, 14, 10, 13, 11, 12 }
    };

    char* cities[2] = { "London", "Derby" };

    for (int i = 0; i < 2; i++)
    {
        printf("%s:\n", cities[i]);
        for (int j = 0; j < 7; j++)
        {
            printf("%d", temps[i][j]);
            if (j != 6)
            {
                printf(", ");
            }
        }
        printf("\n");
    }
}
