#include "queue.h"

int print_queue(Queue_t *front, Queue_t *rear)
{
	if (front == NULL)
	{
		printf("INFO : Queue is Empty\n");
		return FAILURE;
	}

	printf("Front -> ");
	while (front != NULL)		
	{
		printf("%d ", front->data);
		front = front->link;
	 
	}
	printf("<- Rear\n");
	
	return SUCCESS;
}