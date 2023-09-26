#include "sort.h"
#include <stdio.h>
/**
 * shell_sort - sorts an array of integers in ascending order
 *
 * Description: This algorithm used is Shell sort algorithm,
 *		using the Knuth sequence.
 * @array: An array of integers
 * @size: The size of the integer
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	/* Get the gap using the Knuth sequence */
	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			/* Compare the current element with the element at index gap */
			while (j >= gap && (array[j - gap] > temp))
			{
				/* Assign a greater value at this position */
				array[j] = array[j - gap];
				/* Go back, check if temp is lowest there */
				j -= gap;
			}
			/* Insert temp in its correct position */
			array[j] = temp;
		}
		print_array(array, size);
	}
}
