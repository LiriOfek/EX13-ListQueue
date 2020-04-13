/********************************************************\
File Name: linked_list.h
Author: Liri (13/4/2020)
Purpose: This header file contain the struct of the linked list and 
		 the decleration functions for implement inked list
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
void free_list(node_in_list* head);
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
node_in_list* add_node_to_end_of_list(node_in_list* head, void* element);
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
*			   IN void* element - the new element
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
node_in_list* get_first_node_from_list(node_in_list* head);
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
node_in_list* get_last_node_from_list(node_in_list* head);
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
node_in_list* get_next_node(node_in_list* current_node);
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
node_in_list* get_previous_node(node_in_list* head,
								node_in_list* current_node);
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
node_in_list* delete_first_node_in_list(node_in_list** head);
/********************************************************\
* Function name - delete_first_node_in_list
*
* Function Purpose - delete the first node in the list, and free its
*					 allocated memory if the, if the list is empty
*					 or there is only one element in list return NULL
*
* Parameters - IN node_in_list** head - pointer to the pointer of the
*			   first node in list
*			   OUT node_in_list* pointer to the first node in list, after
*			   delete the first node in the list
*
* Return Value - the next node after current_node
*
* Side Effects - this function change the head of the list to point on the
*				 next node in list and free the memory allocated for the
*				 first node
*
* Semantics - this function return the previous node before
*			  current nodeif the list is empty or the current_node
*			  is the first element return NULL
*
* Author - Liri
\********************************************************/
void* get_content_of_node(node_in_list *current_node);
/********************************************************\
* Function name - get_content_of_node
*
* Function Purpose - get content of the current node
*
* Parameters - IN node_in_list* current node
*			   OUT void* pointer to the content of the current node
*
* Return Value - the content of the current node
*
* Side Effects - this function has no side affects
*
* Semantics - this function return the content of the current node
*
* Author - Liri
\********************************************************/
unsigned int length_of_list(node_in_list *head);
/********************************************************\
* Function name - length_of_list
*
* Function Purpose - calculate the length of the list
*
* Parameters - IN node_in_list* head - pointer to the first node
*				in linked list
*
* Return Value - the length of the list
*
* Side Effects - this function has no side affects
*
* Semantics - this function return the length of the list
*
* Author - Liri
\********************************************************/