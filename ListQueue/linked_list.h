/********************************************************\
File Name: linked_list.c
Author: Liri (13/4/2020)
Purpose: This file contain the the functions for implement
		 linked list
\********************************************************/

#include <stdio.h>
#include <stdlib.h>

#define ERROR_MEMORY_ALLOCATION_FAILED ("Error! memory allocation failed.\n")
#define INITIAL_LENGTH (0)

/*linked list struct, containing void pointer of the element
and the pointer to the next element in list*/
typedef struct list
{
	void* element;
	struct list *next;
}node_in_list;

node_in_list* initialize_list();