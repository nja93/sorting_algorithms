#include "sort.h"

/**
 *
 *
 *
 *
 *
 */
void swapint_pos(int *num1, int *num2)
{	
	int tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	for(i = 0; i < size - 1; i++)
	{
		int min_index = i;
		
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_index])
				min_index = j;
		if (min_index != i)
		{
			swapint_pos();
			print_array(array, size);
		}
	}
}
