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
void free_list(node_in_list* head);
node_in_list* add_node_to_end_of_list(node_in_list* head, void* element);
node_in_list* get_first_node_from_list(node_in_list* head);
node_in_list* get_last_node_from_list(node_in_list* head);
node_in_list* get_next_node(node_in_list* current_node);
node_in_list* get_previous_node(node_in_list* head,
								node_in_list* current_node);
void free_node_in_list(node_in_list* node_to_delete);
node_in_list* delete_first_node_in_list(node_in_list** head);
void* get_content_of_node(node_in_list *current_node);
unsigned int length_of_list(node_in_list *head);