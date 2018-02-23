#include <stdio.h>

void push(int n);
int pop();

#define MAX 10
int stack_array[MAX];
int front = -1;
int rear = -1;

int main()
{
    for (int i = 1; i <= MAX; i++)
    {
        push(i);
    }

    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", pop());
    }
}

void push(int n)
{
    if (rear == MAX - 1)
    {
        /* TODO: actually handle error instead of just complaining */
        printf("Stack overflow\n");
    }

    if (front == -1)
    {
        /* stack is initially empty */
        front = 0;
    } 
    
    rear++;
    stack_array[rear] = n;
}

int pop()
{
    if (front == -1)
    {
        printf("Queue is empty");
    }

    int result = stack_array[rear];
    rear--;
    
    if (rear == -1)
    {
        front = -1;
    }

    return result;
}
