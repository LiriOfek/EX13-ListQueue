#include "linked_list.h"

#define INITIAL_INDEX (0)
#define ONE (1)
#define INITIAL_SIZE_OF_LIST (10)
#define PRINT_CONTENT_OF_ELEMENTS ("the %d'st elemnt: %d\n")

/*test_function 1 - for linked list*/
node_in_list* fill_list_with_int_element(node_in_list* head,
	int size_of_list) {
	/********************************************************\
	* Function name - fill_array_with_int_element
	*
	* Function Purpose - fill the list with INITIAL_SIZE_OF_LIST elements
	*
	* Parameters - INOUT node_in_list* head - pointer to the first node of the
	*			   list after fill the list with elements
	*			   IN int size_of_list - the number of elements to push in the
	*			   list
	*
	* Return Value - pointer to the first node of the list after fill it
	*				 with elements
	*
	* Side Effects - this function add elements to the list
	*
	* Semantics - this function add INITIAL_SIZE_OF_LIST elements
	*			  to the list
	*
	* Author - Liri
	\********************************************************/
	node_in_list* current_node;
	int index = INITIAL_INDEX;
	current_node = head;

	for (index = INITIAL_INDEX; index < size_of_list; ++index)
	{
		current_node->element = (int*)malloc(sizeof(int));
		*((int*)(current_node->element)) = index;
		if (NULL == current_node->element)
		{
			printf(ERROR_MEMORY_ALLOCATION_FAILED);
			return NULL;
		}
		if (index < size_of_list - ONE)
		{
			head = add_node_to_end_of_list(head);
			current_node = current_node->next;
		}
	}
	return head;
}

/*test_function 2*/
void print_elements_in_list(node_in_list* head) {
	/********************************************************\
	* Function name - print_elements_in_list
	*
	* Function Purpose - print the elements in the list
	*
	* Parameters - IN node_in_list* head - pointer to the first node of the
	*			   list
	*
	* Return Value - this function has no return value
	*
	* Side Effects - this function has no side effects
	*
	* Semantics - this function print the elements of the list
	*
	* Author - Liri
	\********************************************************/
	node_in_list* node;
	int size_of_list = 0;

	size_of_list = length_of_list(head);
	node = head;

	for (int index = 0; index < size_of_list; ++index) {
		printf(PRINT_CONTENT_OF_ELEMENTS,
			index + ONE,
			*((int*)(node->element)));
		node = node->next;
	}
}
