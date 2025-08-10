#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using Insertion Sort
 * @list: Pointer to pointer to head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		tmp = current;
		current = current->next;
	
		while (tmp->prev && tmp->n < tmp->prev->n)
		{
		
			tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;

			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;

			if (tmp->prev)
				tmp->prev->next = tmp;
			else
				*list = tmp;

			tmp->next->prev = tmp;

			print_list(*list);
		}
	}
}
