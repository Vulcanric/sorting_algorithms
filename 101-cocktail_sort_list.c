#include "sort.h"

listint_t *swap_right(listint_t **list, listint_t *current);
listint_t *swap_left(listint_t **list, listint_t *current);
void cocktail_sort_list(listint_t **list);

/**
 * swap_right - swaps the current node with the adjacent one
 *		in the forward direction
 * @list: A pointer to the list pointer
 * @current: A pointer to the cuurent node to swap
 *
 * Return: A pointer to the next node before the swap.
 */
listint_t *swap_right(listint_t **list, listint_t *current)
{
	listint_t *next_node, *prev_node;

	next_node = current->next;
	prev_node = current->prev;

	current->next = next_node->next;
	if (current->next != NULL)
		current->next->prev = current;

	next_node->prev = prev_node;
	if (next_node->prev != NULL)
		next_node->prev->next = next_node;
	else
		*list = next_node;

	next_node->next = current;
	current->prev = next_node;

	return (next_node);
}

/**
 * swap_left - swaps the current node with the adjacent one
 *		in the backward direction
 * @list: A pointer to the list pointer
 * @current: A pointer to the cuurent node to swap
 *
 * Return: A pointer to the previous node before the swap.
 */
listint_t *swap_left(listint_t **list, listint_t *current)
{
	listint_t *next_node, *prev_node;

	next_node = current->next;
	prev_node = current->prev;

	current->next = prev_node;
	current->prev = prev_node->prev;
	if (current->prev != NULL)
		current->prev->next = current;
	else
		*list = current;

	prev_node->next = next_node;
	prev_node->prev = current;

	if (prev_node->next != NULL)
		prev_node->next->prev = prev_node;

	return (prev_node);
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 *			in ascending order using the Cocktail
 *			shaker sort algorithm
 * @list: A pointer to the list pointer.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *right_sorted = NULL, *left_sorted = NULL;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	while (swapped)
	{
		swapped = 0;
		/* Sort foward */
		while (current->next != right_sorted)
		{
			if (current->n > current->next->n)
			{
				 /* Swap the nodes, return the previous node pointer */
				current = swap_right(list, current);
				swapped = 1;
				print_list(*list);
			} /* Traverse the list forward */
			current = current->next;
		} /* Store the pointer to the last sorted node to the right */
		right_sorted = current;

		if (swapped == 0)
			break; /* Break if no sorting occurs */

		while (current->prev != left_sorted) /* Sort backward */
		{
			if (current->n < current->prev->n)
			{	/* Swap the nodes, return the next node pointer */
				current = swap_left(list, current);
				swapped = 1;
				print_list(*list);
			} /* Traverse the list backward */
			current = current->prev;
		}
		/* Store the pointer to the last sorted node to the left */
		left_sorted = current;
	}
}
