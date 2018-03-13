#include <stdio.h>

void enqueue(int n);
int dequeue();

#define MAX 10
int queue_array[MAX];
int front = -1;
int rear = -1;

int main()
{
    for (int i = 1; i <= MAX; i++)
    {
        enqueue(i);
    }
    
    int divisor;
    printf("Enter divisor: ");
    scanf("%d", &divisor);

    for (int i = 0; i < MAX; i++)
    {
        int val = dequeue();

        if (val % divisor == 0)
        {
            printf("%d ", val);
        }
    }
}

void enqueue(int n)
{
    if (rear == MAX - 1)
    {
        /* TODO: actually handle error instead of just complaining */
        printf("Queue overflow\n");
    }

    if (front == -1)
    {
        /* queue is initially empty */
        front = 0;
    } 
    
    rear++;
    queue_array[rear] = n;
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty");
    }

    int result = queue_array[front];

    /* move all elements forward */
    for (int i = front; i <= rear; i++)
    {
        queue_array[i] = queue_array[i + 1];
    }

    rear--;
    if (rear == -1)
    {
        front = -1;
    }

    return result;
}
