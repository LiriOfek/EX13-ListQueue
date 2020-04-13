/********************************************************\
File Name: linked_list.c
Author: Liri (13/4/2020)
Purpose: This file contain the the functions for implement
		 linked list
\********************************************************/

#include "linked_list.h"

node_in_list* initialize_list() {
	node_in_list* head = NULL;
	return head;
}

void free_list(node_in_list* head) {
	node_in_list* tmp;

	while (NULL != head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

node_in_list* add_node_to_end_of_list(node_in_list* head, void* element) {
	node_in_list *new_node;
	node_in_list *current_node;
	new_node = (node_in_list*)malloc(sizeof(node_in_list));
	if (NULL == new_node) {
		printf(ERROR_MEMORY_ALLOCATION_FAILED);
		return NULL;
	}
	new_node->element = element;
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
	return head;
}

node_in_list* get_last_node_from_list(node_in_list* head) {
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
	return current_node->next;
}

node_in_list* get_previous_node(node_in_list* head, node_in_list* current_node) {
	node_in_list *previous_node;

	previous_node = head;

	if (head == NULL) {
		return NULL;
	}

	if (current_node == head) {
		/*the current node is the first node, so there isn't node before it*/
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

node_in_list* delete_first_node_in_list(node_in_list** head) {
	node_in_list *node_to_delete;
	if (NULL == head) {
		return NULL;
	}

	node_to_delete = *head;

	if (NULL != (*head)->next) {
		*head = (*head)->next;
		free(node_to_delete);
		return *head;
	}

	else {
		/*there is only one element -> and after delete it the list will be empty*/
		free(node_to_delete);
		head = NULL;
		return NULL;
	}
}

void* get_content_of_node(node_in_list *current_node) {
	return current_node->element;
}

unsigned int length_of_list(node_in_list *head) {
	node_in_list *current_node;
	int length = INITIAL_LENGTH;

	current_node = head;
	while (NULL != current_node) {
		++length;
		current_node = current_node->next;
	}
	return length;
}
