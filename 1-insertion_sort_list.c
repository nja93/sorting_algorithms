include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order using the Insertion sort
 * @list: pointer to the head node of list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *tmp;
	
	/*check if list is empty or only has one node*/

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	sorted = *list;
	current = sorted->next;

	while (current != NULL)
	{
		tmp = current;
		current = current->next;

		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
			tmp->next = tmp->prev;
			tmp->prev = tmp->next->prev;
			tmp->next->prev = tmp;

			if (tmp->prev != NULL)
				tmp->prev->next = tmp;
			else
				*list = tmp;

			print_list(*list);
		}
	}
}
