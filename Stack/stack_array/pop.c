/*
* Pop(): Pop removes and returns the topmost element from the stack. 
* Before removing, it checks whether the stack is empty (Stack Underflow).
*/
#include "stack.h"

/* Function for Poping the element */
int Pop(Stack_t *s)
{	
	if (s->top == -1)
	{
	    return FAILURE;
	}
	s->top--;
	return SUCCESS;
}