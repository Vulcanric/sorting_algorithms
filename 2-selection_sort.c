#include "sort.h"

/**
 * sorted - Checks if a list of integers is sorted
 * @array: the list of integers to check
 * @size: size of the list
 * Return: true if it has been sorted, otherwise false
 */
int sorted(const int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (!(array[i] <= array[i + 1]))
			return (false);
	}

	return (true);
}

/**
 * selection_sort - Sorts a lists of integer using
 * the Selection Sort Algorithm
 * @array: the array of integers to be sorted
 * @size: the size or total amount of elements in the list
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	/*
	 * i is the index, m and n are the selectors
	 * 'm' is the main selector that is used in sorting
	 * 'n' is the temporary selector that move from index to index
	 * searching for a number that is smaller so that
	 * m can get that number to insert it at the sorted position
	 * index ('i').
	 */
	size_t i, m, n;
	int tmp;

	/* If array doesn't exist or size is not greater than 1 */
	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (m = n = i; n < size; n++)
		{
			/* IF the number at n's position is smaller */
			/* than that of the main selector */
			/* Change the main selector index to that of n */
			if (array[n] < array[m])
				m = n;
		}

		if (sorted(array, size) == true)
			break;

		if (array[m] == array[i])
			continue;

		/* finally, swap the number at index-'i' with */
		/* with that of the main selector, 'm'*/
		tmp = array[i];
		array[i] = array[m];
		array[m] = tmp;
		print_array(array, size);
	}
}
