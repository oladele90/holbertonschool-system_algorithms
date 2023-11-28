#include "heap.h"

/**
 * binary_tree_node - Creates a new binary tree node.
 * @parent: Pointer to the parent node.
 * @data: Pointer to the data to be stored in the node.
 *
 * Return: Pointer to the newly created binary tree node, or NULL on failure.
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *new;

	new = malloc(sizeof(binary_tree_node_t));
	if (!new)
		return (NULL);
	if (!data)
		return (NULL);

	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	new->data = data;

	return (new);
}
