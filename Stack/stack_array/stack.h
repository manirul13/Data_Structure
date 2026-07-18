/***************************************************************************
 * Author      : Manirul Islam
 * Date        : 06/07/2025
 * Project     : Stack Implementation Using Array
 *
 * Objective:
 * To implement a stack using an array in C and perform the basic stack
 * operations such as Push, Pop, Peek, and Peep following the LIFO
 * (Last In First Out) principle.
 *
 * Stack Operations:
 * 1. Push - Inserts an element onto the top of the stack.
 * 2. Pop  - Removes and returns the top element of the stack.
 * 3. Peek - Returns the top element without removing it.
 * 4. Peep - Returns the element at a specified position from the top
 *           without modifying the stack.
 ***************************************************************************/
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct stack
{
	unsigned int capacity;
	int top;
	int *stack;
}Stack_t;

int create_stack(Stack_t *, int );
int Push(Stack_t *, int);
int Pop(Stack_t *);
int Peek(Stack_t *);
void Peep(Stack_t);

#endif