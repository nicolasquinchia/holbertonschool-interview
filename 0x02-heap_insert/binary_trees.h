#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

struct queue_s
{
	struct binary_tree_s *node;
	struct queue_s *next;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;
typedef struct queue_s queue_t;

void binary_tree_print(const binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);
queue_t *enqueue(queue_t **heap_q, heap_t *node);
void dequeue(queue_t **heap_q);
heap_t *lvl_order_travrsl(heap_t **root, int value);
heap_t *swap(heap_t *node);

#endif /* BINARY_TREES_H */
