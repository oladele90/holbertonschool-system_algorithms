#include "heap.h"
/**
 * get_last_node - Finds the last node in the heap using level order traversal.
 * @heap: Pointer to the heap structure.
 *
 * Return: Pointer to the last node.
 */

binary_tree_node_t *get_last_nod(heap_t *heap)
{
	binary_tree_node_t *current;
	binary_tree_node_t *Q[50];
	binary_tree_node_t *last_node;
	int idx = 0, count = 0;

	if (heap->size == 0 || heap->root == NULL)
		return (NULL);
	Q[count++] = heap->root;

	while (idx < count)
	{
		current = Q[idx++];

		if (current->left != NULL)
			Q[count++] = current->left;
		if (current->right != NULL)
			Q[count++] = current->right;
	}

	last_node = Q[count - 1];
	return (last_node);
}

/**
 * heap_delete - Deletes all nodes in the heap and frees associated memory.
 * @heap: Pointer to the heap structure.
 * @free_data: Pointer to the function used to free data in each node.
 */

void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	binary_tree_node_t *node;

	if (heap->size == 0)
		return;

	while (heap->size > 1)
	{
		node = get_last_nod(heap);
		if (node)
		{
			free_data(node->data);
			free(node);
		}
		heap->size--;
	}
	free(heap);
}