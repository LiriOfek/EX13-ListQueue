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

node_in_list* add_node_to_end_of_list(node_in_list* head) {
	/********************************************************\
	* Function name - add_node_to_end_of_list
	*
	* Function Purpose - add new node to the end of the list
	*					 if the list is don't have elements than the head
	*					 will be the new node
	*
	* Parameters - INOUT node_in_list* head - the first node in the linked list
	*										in the function add to it the new
	*										node in the end of the list
	*
	* Return Value - the list after add to it new node in the end
	*
	* Side Effects - this function allocate memory for the new element
	*				 and add it to the list. if the list is empty than the \
	*				 head will be the new element
	*
	* Semantics - this function allocate memory for the new element
	*			  and add it to the list. if the list is empty than the \
	*			  head will be the new element. if allocation failed return NULL
	*
	* Author - Liri
	\********************************************************/
	node_in_list *new_node;
	node_in_list *current_node;
	new_node = (node_in_list*)malloc(sizeof(node_in_list));
	if (NULL == new_node) {
		printf(ERROR_MEMORY_ALLOCATION_FAILED);
		return NULL;
	}
	new_node->next = NULL;

	if (head == NULL) {
		return new_node;
	}

	else {
		/*add the new node in the end of the list*/
		current_node = head;
		while (NULL != current_node->next)
		{
			current_node = current_node->next;
		}
		current_node->next = new_node;
	}
	return head;
}
