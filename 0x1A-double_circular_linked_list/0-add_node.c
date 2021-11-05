#include "list.h"

/**
 * new_node - Create a new node with it information
 *
 * @str: String to save on the node
 *
 * Return: Pointer of the node created
 */

List *new_node(char *str)
{
	List *new;

	if (str == NULL)
	{
		return (NULL);
	}
	new = malloc(sizeof(List));
	if (new == NULL)
	{
		return (NULL);
	}
	new->str = strdup(str);
	if (new->str == NULL)
	{
		return (NULL);
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/**
 * add_node_end - Add a new node at the end of the
 * double circular linked list
 *
 * @list: Pointer with the List add the node
 * @str: String to save on the node
 *
 * Return: Pointer of the node created
 */

List *add_node_end(List **list, char *str)
{
	List *node_to_add;
	List *reference_node;

	if (list == NULL)
	{
		return (NULL);
	}
	node_to_add = new_node(str);
	if (node_to_add == NULL)
	{
		return (NULL);
	}
	if (*list == NULL)
	{
		*list = node_to_add;
		node_to_add->next = node_to_add;
		node_to_add->prev = node_to_add;
		return (node_to_add);
	}
	reference_node = (*list)->prev;
	(*list)->prev = node_to_add;
	reference_node->next = node_to_add;
	node_to_add->next = (*list);
	node_to_add->prev = reference_node;
	return (node_to_add);
}

/**
 * add_node_begin - Add a new node at the begining of the
 * double circular linked list
 *
 * @list: Pointer with the List add the node
 * @str: String to save on the node
 *
 * Return: Pointer of the node created
 */

List *add_node_begin(List **list, char *str)
{
	List *node_to_add;
	List *reference_node;

	if (list == NULL)
	{
		return (NULL);
	}
	node_to_add = new_node(str);
	if (node_to_add == NULL)
	{
		return (NULL);
	}
	if (*list == NULL)
	{
		*list = node_to_add;
		node_to_add->next = node_to_add;
		node_to_add->prev = node_to_add;
		return (node_to_add);
	}
	reference_node = (*list)->prev;
	reference_node->next = node_to_add;
	(*list)->prev = node_to_add;
	node_to_add->prev = reference_node;
	node_to_add->next = (*list);
	*list = node_to_add;
	return (node_to_add);
}
