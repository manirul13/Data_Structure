#include "stack.h"

int Peek(Stack_t **top)
{
    if (*top == NULL)
    {
        return FAILURE;  //Stack is empty
    }
    return (*top)->data;
}