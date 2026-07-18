/*
* Peek(): Peek returns the top element of the stack without removing it. 
* It simply displays or returns the element at the current top position.
*/

#include "stack.h"

/* Function for display the top of the element in Stack */
int Peek(Stack_t *s)
{
	if (s->top == -1)
	{
	    return FAILURE;
	}
	return s->stack[s->top];
}