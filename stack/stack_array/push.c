/*
* Push(): Push inserts a new element onto the top of the stack. 
* Before inserting, it checks whether the stack is full (Stack Overflow).
*/


#include "stack.h"

/* Fuction for inserting the element */
int Push(Stack_t *s, int element)
{
	if (s->top == s->capacity - 1)
	{
	    return FAILURE;
	}
	s->stack[++(s->top)] = element;
	return SUCCESS;
}