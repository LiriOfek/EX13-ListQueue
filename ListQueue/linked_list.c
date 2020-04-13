#include "linked_list.h"

node_in_list* initialize_list() {
	/********************************************************\
	* Function name - initialize_list
	*
	* Function Purpose - initialize the linked list
	*
	* Parameters - INOUT linked_list* head - pointer to the first node
	*				in linked list, initiate it with NULL
	*
	* Return Value - the pointer to the first node in linkes list
	*
	* Side Effects - this function point the head of the list to NULL
	*
	* Semantics - this function initialize the head of the list to NULL
	*
	* Author - Liri
	\********************************************************/
	node_in_list* head = NULL;
	return head;
}

void free_list(node_in_list* head) {
	/********************************************************\
	* Function name - free_list
	*
	* Function Purpose - free all elements in linked list
	*
	* Parameters - IN linked_list* head - pointer to the first node
	*				in linked list
	*
	* Return Value - this function has no return value
	*
	* Side Effects - this function free allocated memory of all the elements
	*				 in linked list
	*
	* Semantics - this function free allocated memory og all the elements
	*			  in linked list
	*
	* Author - Liri
	\********************************************************/
	node_in_list* tmp;

	while (NULL != head)
	{
		tmp = head;
		head = head->next;
		free(tmp->element);
		free(tmp);
	}
}