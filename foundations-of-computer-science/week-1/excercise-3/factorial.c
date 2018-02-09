#include <stdio.h>

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int result = array[0];
    for(int i = 1; i < 10; i++) {
        result *= array[i];
    }

    printf("Final result: %d\n", result);
    return 0;
}
