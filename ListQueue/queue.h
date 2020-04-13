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
/********************************************************\
* Function name - initialize_queue
*
* Function Purpose - initialize the queue
*
* Parameters - OUT Queue* queue - pointer to the queue
*				 initiate it with NULL
*
* Return Value - the pointer to the queue
*
* Side Effects - this function allocate memory for queue struct,
*				 and initialize its fields
*
* Semantics - this function initialize the queue struct
*			  by allocate memory, and initiate its fields with NULL
*
* Author - Liri
\********************************************************/
Queue* enqueue(Queue *queue, void* element);
/********************************************************\
* Function name - enqueue
*
* Function Purpose - add new element to the queue
*
* Parameters - INOUT Queue* queue - pointer to the queue
*				 after add the new element to it
*			   IN *void element - the new element
*
* Return Value - the pointer to the queue after add the new element
*
* Side Effects - this function allocate memory for the new node in the
*				 list, and add the element to the queue
*
* Semantics - this function allocate memory for the new node,
*			  chenge the pointer of the element to point to the
*			  given element, and add the new element in the end of the queue
*
* Author - Liri
\********************************************************/
Queue* dequeue(Queue *queue);
/********************************************************\
* Function name - dequeue
*
* Function Purpose - delete the first element from the queue
*
* Parameters - INOUT Queue* queue - pointer to the queue
*				 delete the first element from it
*
* Return Value - the pointer to the queue after delete the first element
*
* Side Effects - this function free memory of the first node in list (queue->front),
*				 and change the pointer of the queue->front to point
*				 on the next node
*
* Semantics - this function free memory of the first node in list (queue->front),
*			  and change the pointer of the queue->front to point to
*			  the next node
*
* Author - Liri
\********************************************************/
void* get_first_element_in_queue(Queue *queue);
/********************************************************\
* Function name - get_first_element_in_queue
*
* Function Purpose - return the content of the first element in queue
*
* Parameters -  IN Queue *queue - pointer to the queue
*				OUT void* the content of the first element in queue
*
* Return Value - the content of the first element in queue
*
* Side Effects - this function has no side effects
*
* Semantics - this function return the content of the first element
*			  in the queue by calling to get_content_of_node()
*
* Author - Liri
\********************************************************/
void free_queue(Queue *queue);
/********************************************************\
* Function name - free_queue
*
* Function Purpose - free the allocated memory of the queue
*					 and its fields
*
* Parameters -  IN Queue *queue - pointer to the queue
*
* Return Value - this function has no return value
*
* Side Effects - this function free the allocated memory of
*				 the queue and its fields
*
* Semantics - this function free the allocated memory of the
*			  queue and its fields by calling to free_list()
*
* Author - Liri
\********************************************************/
unsigned int length_of_queue(Queue *queue);
/********************************************************\
* Function name - length_of_queue
*
* Function Purpose - return the length of the queue
*
* Parameters -  IN Queue *queue - pointer to the queue
*				OUT unsigned int length of the queue
*
* Return Value - the length of the queue
*
* Side Effects - this function has no side effects
*
* Semantics - this function return the length of the queue
*			  by calling the function length_of_list()
*
* Author - Liri
\********************************************************/

#endif
