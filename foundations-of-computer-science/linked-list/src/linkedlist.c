#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    struct _Node* next;
    int item;
} Node;

Node* createNode(int item, Node* next);
void add(int item);
void insert(int index, int item);
void removeAt(int index);
int getLength();
Node* getNode(int index);
int getValue(int index);
void printList();

Node* _head;

int main()
{
    // Create list
    _head = createNode(0, NULL);
    
    // Add some items
    for (int i = 1; i <= 5; i++)
    {
        add(i);
    }
    printList();

    // Let's try inserting some items now
    insert(0, -1);
    insert(4, 6);
    printList();
    
    // Get some individual items
    printf("%d\n", getValue(1));
    printf("%d\n", getValue(5));

    // Finally, remove some items
    removeAt(0);
    removeAt(1);
    printList();

    exit(0);
}

Node* createNode(int item, Node* next)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("error creating node\n");
        exit(1);
    }

    node->item = item;
    node->next = next;
    printf("Created node with item: %d\n", item);
    
    return node;
}

// Appends node onto end of the list
void add(int item)
{
    Node* node = createNode(item, NULL);

    Node* current = _head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = node;
}

void insert(int index, int item)
{
    Node* node = createNode(item, NULL);
   
    // Put new node at the front
    if (index == 0)
    {
        node->next = _head;
        _head = node;
    }
    // Put it somewhere else
    else 
    {
        Node* before = _head;
        for(int i = 0; i < index; i++)
        {
            if (before->next == NULL)
            {
                printf("index out of range");
                exit(1);
            }
            before = before->next;
        }
        
        // after could be NULL
        Node* after = before->next;
        before->next = node;
        node->next = after;
    }
}

void removeAt(int index)
{
    Node* node = getNode(index);

    Node* before = getNode(index - 1);
    Node* after = getNode(index + 1);
   
    if (index == 0)
    {
        _head = node->next;
    }

    if (before != NULL)
    {
        before->next = after;   
    }

    free(node);
}

int getLength()
{
    if (_head == NULL)
    {
        printf("list not initialised\n");
        exit(1);
    }

    int length = 1;
    Node* current = _head;
    while (current->next != NULL)
    {
        current = current->next;
        length++;     
    }

    return length;
}

Node* getNode(int index)
{
    int length = getLength();
    if (index >= length)
        return NULL;
    
    Node* current = _head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    return current;
}

int getValue(int index)
{
    int length = getLength();
    if (index >= length)
    {
        printf("index out of range");
        exit(1);
    }

    Node* node = getNode(index);
    if (node == NULL)
    {
        printf("error retrieving value");
        exit(1);
    }

    return node->item;
}

void printList()
{
    Node* current = _head;

    for(int i = 0; i < getLength(); i++)
    {
        if (current == NULL)
        {
            printf("index out of range");
            exit(1);
        }
       
        printf("%d ", current->item);
        current = current->next;
    }
    printf("\n");
}
