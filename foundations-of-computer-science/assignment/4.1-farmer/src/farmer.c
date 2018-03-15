#include <stdio.h>
#include <stdlib.h>

typedef struct _State
{
    struct _State* last;
    int* data;
} State;

State* createState(int* data, State* last);
int isValid(State* state);
int areEqual(State* a, State* b);
void isSuccess(State* state);
void step(State* state);
void swapSide(int* value);
void printState(State* state);

#define STATE_SIZE 4

int _left = 0;
int _right = 1;
int _initial[] = { 0, 0, 0, 0 };
int _success[] = { 1, 1, 1, 1 };

int main()
{
    State* currentState = createState(_initial, NULL);
    step(currentState);

    return 0;
}

State* createState(int* data, State* last)
{
    State* state = (State*)malloc(sizeof(State));
    if (state == NULL)
    {
        printf("error creating state");
        exit(1);
    }

    state->data = data;
    state->last = last;

    return state;
}

int isValid(State* state)
{
    printf("Checking state:\n");
    printState(state);
    if (state == NULL)
        return 0;

    for (int i = 1; i <= 2; i++)
    {
        // Farmer not on same side as grain/chicken
        if (state->data[0] != state->data[i])
        {
            // Grain/chicken on same side as chicken/wolf
            if (state->data[i] == state->data[i + 1])
            {
                printf("invalid - something got eaten\n");
                return 0;
            }
        }
    }

    State* current = state->last;
    while (current->last != NULL)
    {
        if (areEqual(current, state))
        {
            printf("invalid - already been here\n");
            return 0;
        }

        current = current->last;
    }
    
    return 1;
}

int areEqual(State* a, State* b)
{
    if (a == NULL && b == NULL)
        return 1;

    if (a == NULL || b == NULL)
        return 0;

    for (int i = 0; i < STATE_SIZE; i++)
    {
        if (a->data[i] != b->data[i])
            return 0;
    }

    return 1;
}

void checkSuccess(State* state)
{
    for (int i = 0; i < STATE_SIZE; i++)
    {
        if (state->data[i] != _success[i])
            return;
    }

    printf("Success!\n");

    int states = 1;
    State* current = state;
    while (current->last != NULL)
    {
        states++;
        current = current->last;
    }
    printf("%d states\n", states);

    State* path[states];
    current = state;
    for (int i = states; i > 0; i--)
    {
        path[i - 1] = current;
        current = current->last;
    }
   
    printf("Path:\n"); 
    for (int i = 0; i < states; i++)
    {
        printState(path[i]);
        printf("----\n");
    }

    exit(0);
}

// Recurse me baby
void step(State* state)
{
    checkSuccess(state);

    printf("step:\n");
    printState(state);
    
    // Copy values into new state, leave the old one alone
    // Since something else may be using it
    int newStateData[STATE_SIZE];
    for (int i = 0; i < STATE_SIZE; i++)
    {
        newStateData[i] = state->data[i];
    }
    // Farmer always changes side
    swapSide(&(newStateData[0]));

    State* swapFarmerState = createState(newStateData, state);

    // Check if farmer changing side alone is okay
    if (isValid(swapFarmerState) == 1)
    {
        step(swapFarmerState);
    }

    for (int i = 1; i < 4; i++)
    {
        // Is the boater on the same side as the farmer?
        if (state->data[0] == state->data[i])
        {
            // reset new state data in each iteration
            for (int i = 0; i < STATE_SIZE; i++)
            {
                newStateData[i] = state->data[i];
            }
            
            // Swap farmer side since we reset it
            swapSide(&(newStateData[0]));
            // Swap object side
            swapSide(&(newStateData[i]));
            State* swapManyState = createState(newStateData, state);

            if (isValid(swapManyState) == 1)
            {
                step(swapManyState);
            }
        }
    }
}

void swapSide(int* value)
{
    if (*value == _left)
    {
        *value = _right;
    }
    else
    {
        *value = _left;
    }
}

void printState(State* state)
{
    char* boaters[STATE_SIZE] = 
    {
        "Farmer",
        "Grain",
        "Chicken",
        "Wolf"
    };
    
    void printRow(int row)
    {
        for (int i = 0; i < STATE_SIZE; i++)
        {
            if (state->data[i] == row)
            {
                // Just print first character of each name
                printf("%c", boaters[i][0]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    printRow(0);
    printRow(1);
}
