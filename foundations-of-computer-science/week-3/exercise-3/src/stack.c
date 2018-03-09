#include <stdio.h>

void push(int n);
int pop();
int isEmpty();

#define MAX 10
int stack_array[MAX];
int front = -1;
int rear = -1;

int main()
{
    for (int i = 1; i <= MAX; i++)
    {
        if (i % 2 != 0)
        {
            push(i);
        }
    }

    while (isEmpty() == 0)
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
        printf("Stack is empty");
    }

    int result = stack_array[rear];
    rear--;
    
    if (rear == -1)
    {
        front = -1;
    }

    return result;
}

int isEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
