#include "sort.h"

/**
 * max - returns the maximum number in an array of integers
 * @array: array to search
 * @size: size of the array
 * Return: the maximum number
 */
int max(int *array, size_t size)
{
	size_t i;
	int max = 0;

	for (i = 0; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}

/**
 * create_array - Creates an array of integers and initializes its
 *                element
 * @size: size of the array
 * Return: the address of the array created
 */
int *create_array(size_t size)
{
	int *Array;
	size_t i;

	Array = malloc(sizeof(int) * size);
	if (!Array)
		return (NULL);

	/* Initialize all elements with zero */
	for (i = 0; i < size; i++)
		Array[i] = 0;

	return (Array);
}

/**
 * copy_array - copy the content of one array into the other
 * @destArray: the destination array, where to copy to
 * @srcArray: the source, where to copy from
 * @size: number of element to copy
 * Return: nothing
 */
void copy_array(int *destArray, int *srcArray, size_t size)
{
	size_t i = 0;

	if (!destArray || !srcArray)
		return;

	while (i < size)
	{
		destArray[i] = srcArray[i];
		i++;
	}
}

/**
 * counting_sort - sorts an array of integers in ascending order using
 *		   the Counting sort algorithm
 * @array: An array of integers
 * @size: The size of the integer
 */
void counting_sort(int *array, size_t size)
{
	int i;
	int *countArray;
	int *outputArray;
	int k = max(array, size); /* the maximum integer in the list */

	if (array == NULL || size < 2)
		return;

	/* Create the count array and output array, and fill them with zeros */
	countArray = create_array(k + 1);
	outputArray = create_array(size);

	/*
	 * Get the frequency of occurance of each
	 * number in lists
	 */
	for (i = 0; i < (int)size; i++)
		countArray[array[i]] += 1;

	/*
	 * computing for each index the cumulative sum of all elements
	 * before it and plus it
	 */
	for (i = 1; i < k + 1; i++)
		countArray[i] += countArray[i - 1];

	/* print countArray after it has been fulfilly completed */
	print_array(countArray, k + 1);

	/* sort all elements of array in order */
	for (i = (int)size - 1; i >= 0;  i--)
	{
		outputArray[countArray[array[i]] - 1] = array[i];
		countArray[array[i]] -= 1;
	}
	copy_array(array, outputArray, size);

	free(countArray);
	free(outputArray);
}
