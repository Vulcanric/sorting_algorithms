#include "sort.h"

/**
 * bubble_sort - sorts a list or array using the Bubble Sort algorithm
 * @array: Array of integers to sort
 * @size: Size or the number of elements in the array
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int swap = 1, temp;

	if (!array || size < 2)
		return;

	while (swap != 0)
	{
		swap = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				/* Swapping takes place */
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				swap = 1;
			}
		}
	}
}
