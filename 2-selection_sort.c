#include "sort.h"

/**
 * selection_sort - sorts an array in ascending order using
 * the Selection sort algorithm
 *
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;
		if (i == min)
			continue;
		array[i] += array[min];
		array[min] = array[i] - array[min];
		array[i] -= array[min];
		print_array(array, size);
	}
}
