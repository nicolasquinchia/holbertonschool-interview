#include "lists.h"

/**
 * check_cycle - Check if there is a cycle in a linked list
 * @list: linked list head
 *
 * Return: 1 if find a cycle otherwise 0
 */

int check_cycle(listint_t *list)
{
	listint_t *temp = list;
	listint_t *curr = list;

	while (temp != NULL && temp->next != NULL)
	{
		curr = curr->next;
		temp = temp->next;
		temp = temp->next;
		if (temp == curr)
		{
			return (1);
		}
	}
	return (0);
}
