/********************************************************\
File Name: linked_list.h
Author: Liri (13/4/2020)
Purpose: This header file contain queue struct and
		 the decleration functions for implement queue
\********************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include "linked_list.h"

/*Queue struct, containing pointer to the first node in list,
	and the pointer to the final node in list*/
typedef struct queue
{
	node_in_list *front;
	node_in_list *rear;
}Queue;

Queue* initialize_queue();
Queue* enqueue(Queue *queue, void* element);
Queue* dequeue(Queue *queue);

#endif
