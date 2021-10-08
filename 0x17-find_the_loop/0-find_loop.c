#include "lists.h"

/**
 * find_listint_loop - Check if there is a cycle in a linked list
 * @head: Linked list head
 *
 * Return: Address of the pointer where the cycle is
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *temp = head;
	listint_t *curr = head;

	while (temp != NULL && temp->next != NULL)
	{
		curr = curr->next;
		temp = temp->next;
		temp = temp->next;
		if (temp == curr)
		{
			curr = head;
			while (curr != temp)
			{
				curr = curr->next;
				temp = temp->next;
			}
			return (temp);
		}
	}
	return (NULL);
}
