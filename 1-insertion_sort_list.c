#include "sort.h"

/**
 * insertion_sort_list - fnthat sorts int in a doubly linked list Insertion algo
 * @list: ptr to the head node of the dounly-linked  list to be sorted
 * Return: sorted list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *sorted, *tmp;
	
	/*check if list is empty or only has one node*/

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	sorted = *list;
	curr = sorted->next;

	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;

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
