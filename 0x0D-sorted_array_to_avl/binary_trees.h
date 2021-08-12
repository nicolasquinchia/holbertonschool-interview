#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

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

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *create_new_node(avl_t *parent, size_t n);
avl_t *add_node(int *array, size_t idx_left, size_t idx_right, avl_t *parent);

void binary_tree_print(const binary_tree_t *);

#endif /* _BINARY_TREES_H_ */
