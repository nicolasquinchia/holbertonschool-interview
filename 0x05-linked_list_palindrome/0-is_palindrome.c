#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * reverse - reverse a linked list
 * @auxhead: pointer to head of list
 * Return: void
 */
void reverse(listint_t **auxhead)
{
	listint_t *prev = NULL;
	listint_t *current = *auxhead;
	listint_t *next;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*auxhead = prev;
}
/**
 * linkedlist_compare - check if two lists are the same
 * @head_a: pointer to head of list a
 * @head_b: pointer to head of list b
 * Return: true is are the same otherwise false
 */
int linkedlist_compare(listint_t *head_a, listint_t *head_b)
{
	listint_t *aux_a = head_a;
	listint_t *aux_b = head_b;

	while (aux_a && aux_b)
	{
		if (aux_a->n == aux_b->n)
		{
			aux_a = aux_a->next;
			aux_b = aux_b->next;
		}
		else
		{
			return (0);
		}
	}
	if (aux_a == NULL && aux_b == NULL)
	{
		return (1);
	}
	return (0);
}
/**
 * is_palindrome - prints all elements of a listint_t list
 * @head: pointer to head of list
 * Return: 1 if is palindrome otherwise 0
 */
int is_palindrome(listint_t **head)
{
	listint_t *aux_head = *head;
	listint_t *fast_route = aux_head;
	listint_t *slow_route = aux_head;
	listint_t *mid_node = NULL;
	listint_t *second_half = NULL;
	listint_t *aux_slow = aux_head;

	int result = 1;

	if (aux_head != NULL && aux_head->next != NULL)
	{
		while (fast_route != NULL && fast_route->next != NULL)
		{
			fast_route = fast_route->next->next;
			aux_slow = slow_route;
			slow_route = slow_route->next;
		}
		if (fast_route != NULL)
		{
			mid_node = slow_route;
			slow_route = slow_route->next;
		}
		second_half = slow_route;
		aux_slow->next = NULL;
		reverse(&second_half);
		result = linkedlist_compare(aux_head, second_half);
		reverse(&second_half);
		if (mid_node != NULL)
		{
			aux_slow->next = mid_node;
			mid_node->next = second_half;
		}
		else
		{
			aux_slow->next = second_half;
		}
	}
	return (result);
}
