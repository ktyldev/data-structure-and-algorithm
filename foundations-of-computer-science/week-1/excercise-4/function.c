#include <stdio.h>

void print_big(int x) {
    if (x > 10) {
        printf("x is big\n");   
    }
}

int main() {
    int x;

    printf("Enter a number: ");
    scanf("%d", &x);

    print_big(x);
}
