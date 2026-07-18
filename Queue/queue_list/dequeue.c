#include "queue.h"

int dequeue(Queue_t **front, Queue_t **rear)
{
    if (*front == NULL)
    {
        return FAILURE;
    }
    
    Queue_t *temp = *front;
    *front = (*front)->link;
    
    if (*front == NULL)
    {
        *rear = NULL;
    }
    
    free(temp);
    return SUCCESS;
}