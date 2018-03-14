#include <stdio.h>
#include <string.h>

void push(char n);
char pop();
int isEmpty();

#define MAX 10
char stackArray[MAX];
char front = -1;
char rear = -1;

int main()
{
    // The full palindrome can be twice the size of the stack
    int maxLength = MAX * 2;
    char input[maxLength];
    // Get user input
    printf("Enter test string: ");
    if (!fgets(input, maxLength, stdin))
    {
        printf("You've suffered a most terrible fate\n");
        return 1;
    }
  
    // Get palindrome from input, remove newline
    int end = strlen(input) - 1;
    char palindrome[end];
    for (int i = 0; i < end; i++)
    {
        palindrome[i] = input[i];
    }
    
    int middle = end / 2;
    if (end % 2 != 0)
    {
        middle++;
    }

    printf("\n");
    // Push first half of input onto stack
    for (int i = 0; i < middle; i++)
    {
        printf("push %c\n", palindrome[i]);
        push(palindrome[i]);
    }
  
    printf("length %d - ", end); 
    if (end % 2 == 0)
    {
        printf("even\n");
    }
    else
    {
        printf("odd\n");
    }

    int count = 0;
    if (end % 2 != 0)
    {
        // Get middle letter if odd-length palindrome
        count = -1;
    }
    
    // Pop stack items and compare to rest of input
    while (isEmpty() == 0)
    {
        char c = pop();
        printf("popped %c\n", c);

        char inputChar = palindrome[middle + count];
        printf("got %c from input\n", inputChar);
        
        if (c != inputChar)
        {
            printf("%s is not a palindrome", palindrome);
            return 0;
        }

        count++; 
    }

    printf("%s is a palidrome ", palindrome);
    return 1;
}

void push(char n)
{
    if (rear == MAX - 1)
    {
        // TODO: actually handle error instead of just complaining
        printf("Stack overflow\n");
    }

    if (front == -1)
    {
        // stack is initially empty 
        front = 0;
    } 
    
    rear++;
    stackArray[rear] = n;
}

char pop()
{
    if (front == -1)
    {
        printf("Stack is empty");
    }

    char result = stackArray[rear];
   
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
