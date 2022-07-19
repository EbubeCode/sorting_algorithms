#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the shell sort algorithm, using knuth sequence
 *
 * @array: array to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t h = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;
	while (h < size / 3)
		h = (3 * h) + 1;
	while (h >= 1)
	{
		for (i = h; i < size; i++)
			for (j = i; j >= h && array[j] <
							array[j - h]; j -= h)
			{
				temp = array[j];
				array[j] = array[j - h];
				array[j - h] = temp;
			}
		print_array(array, size);
		h /= 3;
	}
}
