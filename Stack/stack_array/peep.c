/*
* Peep(): Peep returns the element at a given position from the top of the stack without removing i
*/
#include "stack.h"

/* Function for print the data's in the stack */
void Peep(Stack_t s)
{
	/* Checking the Stack is empty or not */
	if (s.top == -1)
	{
		printf("INFO : Stack is empty\n");
	}
    else
    {
	    /* Declaring the temp for store the top value to print the values in the Stack*/
	    printf("Top -> ");
	    for (int i = s.top; i >= 0; i--)
	    {
	        printf("%d ", s.stack[i]);
	    }
	    printf("\n");
    }
}