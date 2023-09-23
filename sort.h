#ifndef SORT_H
#define SORT_H

/**
 * struct listint_s - Double linked list node
 *
 * @n: Integer to be stored inside the node
 * @prev: pointer to the previous node
 * @next: pointer to the next node
 *
 * Description: represents a node of a double linked list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Function used in printing the list during sorting */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting Algorithms */
void bubble_sort(int *array, size_t size);

#endif /* SORT_H */