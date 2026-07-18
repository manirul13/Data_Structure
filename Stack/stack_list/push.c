#include "stack.h"

int Push(Stack_t **top, data_t data)
{
    //Allocate the memory for new node
    Stack_t *new = malloc(sizeof(Stack_t));
    
    if (!new)
    {
        return FAILURE;  //Memory alloation failed
    }  
    
    new->data = data;
    new->link = *top;   //Link new node top
    *top = new;         //Update top pointer to new node    
    
    return SUCCESS;
}
