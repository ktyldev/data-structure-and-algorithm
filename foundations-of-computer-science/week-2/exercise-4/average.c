#include <stdio.h>
#include <stdlib.h>

int main()
{
    int maxElements = 10;

    int num;
    float *ptr;
    float sum = 0;
    float average;

    printf("Enter number of elements(<%d): ", maxElements);
    scanf("%d", &num);
    if (num >= maxElements)
    {
        printf("Too many elements");
        exit(1);
    }

    ptr = calloc(num, sizeof(float));
    if (ptr == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }

    printf("Enter %d numbers:\n", num);
    for (int i = 0; i < num; i++)
    {
        scanf("%E", &ptr[i]);
        sum += ptr[i];
    }
    free(ptr);

    average = sum / num;
    printf("Average: %E\n", average);
    return 0;
}
