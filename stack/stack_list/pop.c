#include "stack.h"

int Pop(Stack_t **top)
{
    if (*top == NULL)
    {
        return FAILURE; //Stack is empty
    }
    
    Stack_t *temp = *top;
    *top = (*top)->link;  //Move top to next
    free(temp);           //Deallocating the top
    
    return SUCCESS;
}