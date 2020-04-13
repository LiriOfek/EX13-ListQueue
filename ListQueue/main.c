/********************************************************\
File Name: linked_list.c
Author: Liri (13/4/2020)
Purpose: This file contain test functions of linked list
\********************************************************/

#include "linked_list.h"
#include "queue.h"

#define INITIAL_INDEX (0)
#define ONE (1)
#define INITIAL_SIZE_OF_LIST (10)
#define PRINT_CONTENT_OF_ELEMENTS ("The %d'st elemnt: %d\n")
#define PRINT_LIST_AFTER_DELETE_FIRST_NODE ("List after delete first node: \n")
#define PRINT_FIRST_NODE ("The first node: %d\n")
#define PRINT_LAST_NODE ("The last node: %d\n")
#define PRINT_NEXT_NODE_AFTER_THE_FIRST ("Next node after the first: %d\n")
#define PRINT_PREVIOUS_NODE_BEFOR_THE_SECOND ("Previous node to the second node: %d\n")
#define PRINT_CONTENT_OF_FIRST_NODE ("Content of first node: %d\n")
#define PRINT_LENGTH_OF_LIST ("Length of the list: %d\n")
#define PRINT_FIRST_ELEMENT_IN_QUEUE ("The first element in queue: %d\n")
#define PRINT_LENGTH_OF_QUEUE ("Length of the queue: %d\n")
#define PRINT_ELEMENTS_AFTER_DEQUEUE ("List elements after dequeue:\n")
#define PRINT_ELEMENTS_AFTER_DELETE_FIRST_NODE ("List elements after delete the first node:\n")


enum return_values { FAILURE, SUCCESS };

int elements_to_list[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

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
	int index = INITIAL_INDEX;

	for (index = INITIAL_INDEX; index < size_of_list; ++index)
	{
		head = add_node_to_end_of_list(head, &elements_to_list[index]);
	}
	return head;
}

/*test_function 2 - for linked list*/
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
			*((int*)get_content_of_node(node)));
		node = node->next;
	}
}

/*test_function 3 - for linked list*/
int test_function_for_linked_list() {
	/********************************************************\
	* Function name - test_function_for_linked_list
	*
	* Function Purpose - test the functions in list module
	*
	* Parameters - OUT int if there was no error by allocation memory -
	*				return FAILURE, otherwise return SUCCESS
	*
	* Return Value - if there was no error by allocation memory -
	*				return FAILURE, otherwise return SUCCESS
	*
	* Side Effects - this function call functions that allocate memory for
	*				 nodes and elements in list
	*
	* Semantics - this function call to functions in list module
	*			  and print there return values to test them
	*
	* Author - Liri
	\********************************************************/
	node_in_list* head;
	node_in_list* node;

	/*initiate head*/
	head = initialize_list();

	/*add elements to the list*/
	head = fill_list_with_int_element(head, INITIAL_SIZE_OF_LIST);
	if (NULL == head)
	{
		return FAILURE;
	}

	print_elements_in_list(head);

	printf(PRINT_ELEMENTS_AFTER_DELETE_FIRST_NODE);

	/*delete first node from list*/
	head = delete_first_node_in_list(&head);
	printf(PRINT_LIST_AFTER_DELETE_FIRST_NODE);
	print_elements_in_list(head);

	/*get first node*/
	printf(PRINT_FIRST_NODE, 
		*((int*)get_content_of_node(head)));

	/*get lest node*/
	printf(PRINT_LAST_NODE, 
		*((int*)(get_content_of_node(get_last_node_from_list(head)))));

	/*use function to get next node*/
	node = get_next_node(head);
	printf(PRINT_NEXT_NODE_AFTER_THE_FIRST, 
		*((int*)get_content_of_node(node)));

	/*use function to get previos node*/
	printf(PRINT_PREVIOUS_NODE_BEFOR_THE_SECOND, 
		*((int*)(get_content_of_node(get_previous_node(head, node)))));

	/*The length of the list:*/
	printf(PRINT_LENGTH_OF_LIST,
		length_of_list(head));

	free_list(head);

	return SUCCESS;
}

Queue* fill_queue_with_int_element(Queue* queue,
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
	int index = INITIAL_INDEX;

	for (index = INITIAL_INDEX; index < size_of_list; ++index)
	{
		queue = enqueue(queue, &elements_to_list[index]);
		if (NULL == queue)
		{
			return NULL;
		}
	}
	return queue;
}

void print_elements_in_queue(Queue* queue) {
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
	print_elements_in_list(queue->front);
}

int test_function_for_queue() {
	Queue *queue;

	/*initialize queue*/
	queue = initialize_queue();
	if (NULL == queue)
	{
		return FAILURE;
	}

	/*add elements to the queue*/
	queue = fill_queue_with_int_element(queue,
										INITIAL_SIZE_OF_LIST);
	if (NULL == queue)
	{
		return FAILURE;
	}
	print_elements_in_queue(queue);

	printf(PRINT_ELEMENTS_AFTER_DEQUEUE);
	
	/*dequeue element from the queue*/
	queue = dequeue(queue);
	print_elements_in_queue(queue);

	/*get first node*/
	printf(PRINT_FIRST_ELEMENT_IN_QUEUE,
		*((int*)get_first_element_in_queue(queue)));

	/*the length of the queue*/
	printf(PRINT_LENGTH_OF_QUEUE, length_of_queue(queue));

	free_queue(queue);
	return SUCCESS;
}

int main() {
	/********************************************************\
	* Function name - main
	*
	* Function Purpose - test the functions in list module
	*
	* Parameters - OUT int if there was no error by allocation memory -
	*				return FAILURE, otherwise return SUCCESS
	*
	* Return Value - if there was no error by allocation memory -
	*				return FAILURE, otherwise return SUCCESS
	*
	* Side Effects - this function call functions that allocate memory for
	*				 nodes and elements in list
	*
	* Semantics - this function call to functions in list module
	*			  and print there return values to test them
	*
	* Author - Liri
	\********************************************************/
	return test_function_for_queue();

}

