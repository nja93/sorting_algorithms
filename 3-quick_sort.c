#include "sort.h"

/**
 * swapint_pos- fn that swaps two int
 * @num1: first int to be swapped
 * @num2: second int to be swapped
 */
void swapint_pos(int *num1, int *num2)
{
	int tmp;
	/*tmp acts as a placeholder to allow swapping*/
	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

/**
 * lomuto_partition - fn that sets last element as pivot in array subset
 * @array: array of int
 * @size: size of array
 * @left: (1st)farthest left index of the subset to sort
 * @right: (last)farthest right index of the subset to ort
 * Return: index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, more, less;

	pivot = array + right;
	for (more = less = left; less < right; less++)
	{
		if (array[less] < *pivot)
		{
			if (more < less)
			{
				swapint_pos(array + less, array + more);
				print_array(array, size);
			}
			more++;
		}
	}

	if (array[more] > *pivot)
	{
		swapint_pos(array + more, pivot);
		print_array(array, size);
	}

	return (more);
}
/**
 * lomuto_sort - fn that sorts array
 * @array: array of int
 * @size: size of array
 * @left: (1st)farthest left index of the subset to sort
 * @right: (last)farthest right index of the subset to ort
 * Return: index.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int split;

	if (right - left > 0)
	{
		split = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, split - 1);
		lomuto_sort(array, size, split + 1, right);
	}
}

/**
 * quick_sort - fn that sorts an array of int using Quicksort algo
 * @array: array of integers
 * @size: size of the array
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
