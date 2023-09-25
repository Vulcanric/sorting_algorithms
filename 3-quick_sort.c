#include "sort.h"

void swap(int *array, int i, int j);
int partition(int *array, int first, int last, size_t size);
void sort(int *array, int first, int last, size_t size);
void quick_sort(int *array, size_t size);

/**
 * swap - swaps two elements of an array
 * @array: The array of integers to be partitioned
 * @i: Index of the first element to be swapped
 * @j: Imdex of the second element
 */
void swap(int *array, int i, int j)
{
	size_t temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * partition - partition the array of integers into two.
 * @array: The array of integers to be partitioned
 * @first: The index of the first element of the array
 * @last: The index of the last element of the array
 * @size: The size of the array
 *
 * Return: The index of the pivot used for the partitioning
 */
int partition(int *array, int first, int last, size_t size)
{
	int pivot, i, j;

	/* Set a temporary pivot index */
	i = first - 1;

	pivot = array[last];

	for (j = first; j < last; j++)
	{
		if ((array[j] < pivot) && (array[++i] != array[j]))
		{
			/**
			 * Swap the current element with the element at the
			 * temporary pivot index
			 */
			swap(array, i, j);
			print_array(array, size);
		}
	}
	i++;
	if (array[i] != array[j])
	{
		swap(array, i, j);
		print_array(array, size);

	}
	return (i);
}

/**
 * sort -  sorts an array of integers using quick sort
 * @array: The array of integers to be partitioned.
 * @first: The index of the first element of the array.
 * @last: The index of the last element of the array.
 * @size: The size of the array.
 */
void sort(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < 0 || first >= last)
		return;

	/* Partition the array with a pivot and get its index */
	pivot = partition(array, first, last, size);


	/* Sort the first half */
	sort(array, 0, pivot - 1, size);

	/* Sort the second half */
	sort(array, pivot + 1, last, size);
}

/**
 * quick_sort - sorts an array of integers in ascending order using
 *		the Quick sort algorithm
 * @array: An array of integers to be sorted.
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	int first = 0, last = size - 1;

	if (array == NULL || size < 2)
		return;

	sort(array, first, last, size);
}
