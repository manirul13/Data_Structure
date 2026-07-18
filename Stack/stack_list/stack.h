/***************************************************************************
 * Author      : Manirul Islam
 * Date        : 15/06/2025
 * Project     : Stack Implementation Using Linked List
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
#define STACK_L

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct node
{
	data_t data;
	struct node *link;
}Stack_t;

int Push(Stack_t **top, data_t data);
int Pop(Stack_t **top);
int Peek(Stack_t **top);
int Peep(Stack_t *top);
#endif
