#include "binary_trees.h"

/**
 * heap_insert - inserts a node in max binary heap
 * @root: pointer to root of tree
 * @value: value of new node
 *
 * Return: pointer to new node or NULL if fails
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;

	if (!*root)
	{
		new = binary_tree_node(NULL, value);
		*root = new;
		return (new);
	}
	new = lvl_order_travrsl(root, value);
	return (swap(new));
}

/**
 * enqueue - insert node into queue
 * @heap_q: pointer to queue
 * @node: pointer to node
 *
 * Return: pointer to new node or NULL if fails
 */
queue_t *enqueue(queue_t **heap_q, heap_t *node)
{
	queue_t *current = *heap_q;
	queue_t *new;

	new = malloc(sizeof(queue_t));
	if (!new)
		return (NULL);
	new->node = node;
	new->next = NULL;

	if (!current)
	{
		*heap_q = new;
		return (new);
	}

	/* traverse the queue till find tail */
	while (current->next)
		current = current->next;
	current->next = new;
	return (new);
}

/**
 * dequeue - pops nodes out from queue
 * @heap_q: pointer to queue
 *
 */
void dequeue(queue_t **heap_q)
{
	queue_t *temp = *heap_q;

	*heap_q = (*heap_q)->next;
	free(temp);
}

/**
 * lvl_order_travrsl - level order traversal of complete BST
 * @root: pointer to root
 * @value: value of new node
 *
 * Return: pointer to insert-node of heap
 */
heap_t *lvl_order_travrsl(heap_t **root, int value)
{
	queue_t *heap_q = NULL;
	heap_t *current;
	heap_t *new = NULL;

	if (!enqueue(&heap_q, *root))
		return (NULL);

	while (heap_q)
	{
		current = heap_q->node;
		if (current->left)
		{
			if (!enqueue(&heap_q, current->left))
				return (NULL);
		}
		else if (!new)
		{
			new = binary_tree_node(current, value);
			if (!new)
				return (NULL);
			current->left = new;
		}

		if (current->right)
		{
			if (!enqueue(&heap_q, current->right))
				return (NULL);
		}
		else if (!new)
		{
			new = binary_tree_node(current, value);
			if (!new)
				return (NULL);
			current->right = new;
		}
		dequeue(&heap_q);
	}
	return (new);
}

/**
 * swap - swap nodes to order the heap
 * @node: pointer to new node
 *
 * Return: pointer to node in correct position
 */
heap_t *swap(heap_t *node)
{
	heap_t *swapper = node;
	int aux;

	while (swapper->parent)
	{
		if (swapper->n > swapper->parent->n)
		{
			aux = swapper->parent->n;
			swapper->parent->n = swapper->n;
			swapper->n = aux;
			node = node->parent;
		}
		swapper = swapper->parent;
	}
	return (node);
}
