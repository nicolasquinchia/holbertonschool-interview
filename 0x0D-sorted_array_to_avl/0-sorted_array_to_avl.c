#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of element in the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *head;

	if (!array || !size)
		return (NULL);

	head = add_node(array, 0, size - 1, NULL);
	return (head);
}

/**
 * create_new_node - Function to create a new node
 *
 * @parent: Parent of the node
 * @n: Value
 * Return: Pointer to the node
 */

avl_t *create_new_node(avl_t *parent, size_t n)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	node->n = n;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;

	if (parent != NULL)
		node->parent = parent;
	else
		node->parent = NULL;

	return (node);
}

/**
 * add_node - Function to add a node
 *
 * @array: Array with the tree values to print
 * @parent: Parent of the node
 * @idx_left: Left index of the matrix
 * @idx_right: Right index of the matrix
 *
 * Return: Pointer to the node
 */

avl_t *add_node(int *array, size_t idx_left, size_t idx_right,
		avl_t *parent)
{
	avl_t *node;
	size_t middle;

	if (idx_left > idx_right)
		return (NULL);

	middle = (idx_left + idx_right) / 2;
	node = create_new_node(parent, array[middle]);
	if (!node)
		return (NULL);

	if (middle != idx_left)
		node->left = add_node(array, idx_left, middle - 1, node);

	if (middle != idx_right)
		node->right = add_node(array, middle + 1, idx_right, node);

	return (node);
}
