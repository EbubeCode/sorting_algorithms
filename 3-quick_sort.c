#include "sort.h"

/**
 * partition - finds the partition position
 * @array: the array
 * @low: lower index
 * @high: higher index
 * @size: size of the array
 *
 * Return: the index of partition
 */
size_t partition(int *array, int low, int high, size_t size)
{
	int piv = array[high], temp;
	int i = (low - 1), j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= piv)
		{
			i++;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			if (j != i)
				print_array(array, size);
		}
	}
	j = i + 1;
	temp = array[high];
	array[high] = array[j];
	array[j] = temp;
	if (j != high)
		print_array(array, size);

	return (j);
}

/**
 * q_sort - recursive funtion to sort the array
 * @low: lower index
 * @high: higher index
 * @size: size of the array
 * @array: the array
 */
void q_sort(int *array, int low, int high, size_t size)
{
	int piv;

	if (low < high)
	{
		piv = partition(array, low, high, size);

		q_sort(array, low, piv - 1, size);

		q_sort(array, piv + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 */~/Documents/ALX/ALX_SE/sorting_algorithms
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	q_sort(array, 0, size - 1, size);
}
