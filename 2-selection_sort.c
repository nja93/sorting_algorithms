#include "sort.h"

/**
 *swapint_pos- function that swaps integers
 *@num1: first int value
 *@num2: second int value
 *
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
 * selection_sort - fn that carried out selection sort
 * @array: array to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	/*check size of array is greater than 1 an not empty*/
	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_index])
				min_index = j;
		if (min_index != i)
		{
			swapint_pos(&array[min_index], &array[i]);
			print_array(array, size);
		}
	}
}
