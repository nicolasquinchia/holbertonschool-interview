#include "lists.h"
/**
 *insert_node - inserts a number into a sorted singly linked list
 *@head: double pointer of a list
 *@number: number of node to be inserted
 *
 * Return: address of the new node, or NULL
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *aux;

	if (head == NULL)
		return (NULL);
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = number;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = NULL;
		return (new_node);
	}
	else
	{
		aux = *head;
		while (aux->next != NULL)
		{
			if (new_node->n > aux->n)
			{
				aux = aux->next;
			}
			else
			{
				new_node->n = aux->n;
				aux->n = number;
				new_node->next = aux->next;
				aux->next = new_node;
				return (aux);
			}
			if (aux->next == NULL)
				return (add_nodeint_end(head, number));
		}
	}
	return (new_node);
}
