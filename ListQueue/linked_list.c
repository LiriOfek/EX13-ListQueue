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

node_in_list* get_first_node_from_list(node_in_list* head) {
	/********************************************************\
	* Function name - get_first_node_from_list
	*
	* Function Purpose - return the first node in the list
	*
	* Parameters - INOUT linked_list* head - pointer to the first node
	*				in linked list
	*
	* Return Value - pointer to the first node in the list
	*
	* Side Effects - this function has no side affects
	*
	* Semantics - this function return the first node in the list
	*
	* Author - Liri
	\********************************************************/
	return head;
}

node_in_list* get_last_node_from_list(node_in_list* head) {
	/********************************************************\
	* Function name - get_last_node_from_list
	*
	* Function Purpose - return the last node of the list, if the list is
	*					 empty return NULL
	*
	* Parameters - IN linked_list* head - pointer to the first node
	*				in linked list
	*			   OUT node_in_list* pointer to last node in the list
	*
	* Return Value - pointer to the last node in the list
	*
	* Side Effects - this function has no side affects
	*
	* Semantics - this function go through the given list and and
	*			  return the last node of the list, if the list is empty
	*			  return NULL
	*
	* Author - Liri
	\********************************************************/
	node_in_list *current_node;

	current_node = head;

	if (NULL == current_node) {
		/*list is empty*/
		return NULL;
	}
	while (NULL != current_node->next) {
		current_node = current_node->next;
	}
	return current_node;
}

node_in_list* get_next_node(node_in_list* current_node) {
	/********************************************************\
	* Function name - get_next_node
	*
	* Function Purpose - get the next node after the given nodes
	*
	* Parameters - IN node_in_list* the current node
	*			   OUT node_in_list* next node after current_node
	*
	* Return Value - the next node after current_node
	*
	* Side Effects - this function has no side affects
	*
	* Semantics - this function return the next node after
	*			  current node
	*
	* Author - Liri
	\********************************************************/
	return current_node->next;
}

node_in_list* get_previous_node(node_in_list* head, node_in_list* current_node) {
	/********************************************************\
	* Function name - get_previous_node
	*
	* Function Purpose - get the node before the current_node, if the list
	*					 is empty or the current_node is the first element
	*					 return NULL
	*
	* Parameters - IN node_in_list* head - pointer to the first node
	*				in linked list
	*			   IN node_in_list* the current node
	*			   OUT node_in_list* next node before current_node
	*
	* Return Value - the next node after current_node
	*
	* Side Effects - this function has no side affects
	*
	* Semantics - this function return the previous node before
	*			  current nodeif the list is empty or the current_node
	*			  is the first element return NULL
	*
	* Author - Liri
	\********************************************************/
	node_in_list *previous_node;

	previous_node = head;

	if (head == NULL) {
		return NULL;
	}

	if (current_node == previous_node) {
		return NULL;
	}

	while (NULL != previous_node)
	{
		if (current_node == previous_node->next)
		{
			return previous_node;
		}
		previous_node = previous_node->next;
	}
	return previous_node;
}

void free_node_in_list(node_in_list* node_to_delete) {
	/********************************************************\
	* Function name - free_node_in_list
	*
	* Function Purpose - free the allocated memory of the given node
	*
	* Parameters - IN node_in_list* node_to_delete - the node that need
	*				to delete
	*
	* Return Value - this function has no return value
	*
	* Side Effects - free the memory that allocated for the given node
	*
	* Semantics - this function free the allocated memory of the given node
	*
	* Author - Liri
	\********************************************************/

	free(node_to_delete->element);
	free(node_to_delete);
}