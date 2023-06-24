#include "sort.h"

/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * @array: array of int to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped_int;

	/* check if array is empty or has only 1 element*/
	if (array == NULL || size < 2)
		return;

	/* num iterating from first to second last item of array*/
	for (i = 0; i < size - 1; i++)
	{
		/*swapped int initialized to 0*/
		swapped_int = 0;

		/*iterate through "inner loop" of the array for swapping"*/
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/*code block to swap*/
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				/*boolean condition*/
				swapped_int = 1;
				print_array(array, size);
			}
		}

		/*if statementnt to confirm no swaps have been done, exit*/
		if (swapped_int == 0)
		{
			return;
		}
	}
}
