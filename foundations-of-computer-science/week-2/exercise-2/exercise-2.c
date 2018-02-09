#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *ptr, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &num);

    ptr = calloc(num, sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }

    printf("Enter %d numbers:\n", num);
    for (int i = 0; i < num; ++i)
    {
        scanf("%d", &ptr[i]);
        sum += ptr[i];
    }
    free(ptr);

    printf("Sum: %d\n", sum);
    return 0;
}
