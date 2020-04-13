#include "linked_list.h"

#define INITIAL_INDEX (0)
#define ONE (1)

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