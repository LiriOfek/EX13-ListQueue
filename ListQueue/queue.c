/********************************************************\
File Name: queue.c
Author: Liri (13/4/2020)
Purpose: This file contain the the functions for implement
		 queue
\********************************************************/

#include "queue.h"

Queue* initialize_queue() {
	Queue *queue;
	queue = (Queue*)malloc(sizeof(Queue));
	if (NULL == queue) {
		printf(ERROR_MEMORY_ALLOCATION_FAILED);
		return NULL;
	}
	queue->front = initialize_list();
	queue->rear = initialize_list();
	return queue;
}

Queue* enqueue(Queue *queue, void* element) {
	node_in_list* new_node;

	new_node = (node_in_list*)malloc(sizeof(node_in_list));
	if (NULL == new_node) {
		printf(ERROR_MEMORY_ALLOCATION_FAILED);
		return NULL;
	}
	new_node->element = element;
	new_node->next = NULL;
	if (NULL == queue->front) {
		queue->front = queue->rear = new_node;
	}
	else {
		queue->rear->next = new_node;
		queue->rear = new_node;
	}
	return queue;
}