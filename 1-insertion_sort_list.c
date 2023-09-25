#include "sort.h"

listint_t *swap_prev_node(listint_t **list, listint_t *current);
void insertion_sort_list(listint_t **list);

/**
 * swap_prev_node - swaps the current node with adjacent previous node
 * @list: A pointer to the head pointer of the list.
 * @current: A pointer to the current node to be swapped
 *
 * Return: A pointer to the swapped node to the right.
 */
listint_t *swap_prev_node(listint_t **list, listint_t *current)
{
	listint_t *prev_node, *next_node;

	prev_node = current->prev;
	next_node = current->next;

	/* Update the surrounding node pointers */
	if (prev_node != NULL)
		prev_node->next = next_node;

	if (next_node != NULL)
		next_node->prev = prev_node;


	/* Update the current node pointer */
	current->prev = prev_node->prev;
	current->next = prev_node;

	/* Update the adjacent node to be swapped with */
	prev_node->prev = current;

	if (current->prev != NULL)
		current->prev->next = current;
	else
		*list = current;

	return (prev_node);
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *			order using the Insertion sort algorithm
 * @list: A pointer to the head pointer of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *ptr;

	if (*list == NULL || (*list)->next == NULL)
		return;

	head = (*list)->next;
	while (head)
	{
		ptr = head;
		while (ptr && (ptr->n < ptr->prev->n))
		{
			/* Compare and swap backward */
			ptr = swap_prev_node(list, ptr);
			print_list(*list);

			if (ptr->prev->prev != NULL)
				ptr = ptr->prev;
			else
				ptr = NULL;
		}
		head = head->next;
	}
}
