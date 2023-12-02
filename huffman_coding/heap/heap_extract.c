#include "heap.h"

/**
 * heapify - Maintains the min-heap property by fixing a potential violation
 *           at the given node.
 * @heap: Pointer to the heap structure.
 * @node: Pointer to the node where the heap property may be violated.
*/

void heapify(heap_t *heap, binary_tree_node_t *node)
{
	binary_tree_node_t *smallest = node;
	binary_tree_node_t *l_child = node->left;
	binary_tree_node_t *r_child = node->right;

	if (l_child != NULL && heap->data_cmp(l_child->data, smallest->data) < 0)
		smallest = l_child;

	if (r_child != NULL && heap->data_cmp(r_child->data, smallest->data) < 0)
		smallest = r_child;

	if (smallest != node)
	{
		void *temp = node->data;

		node->data = smallest->data;
		smallest->data = temp;

		heapify(heap, smallest);
	}

	if (smallest->right == r_child && smallest->left == NULL)
	{
		smallest->left = smallest->right;
		smallest->right = NULL;
		free(smallest->right);
	}
}
#include <stdlib.h>

/**
 * get_last_node - Finds the last node in the heap using level order traversal.
 * @heap: Pointer to the heap structure.
 *
 * Return: Pointer to the last node.
 */
binary_tree_node_t *get_last_node(heap_t *heap)
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
 * heap_extract - Extracts the minimum element from the min heap.
 * @heap: Pointer to the heap structure.
 *
 * Return: Pointer to the extracted minimum element.
 */

void *heap_extract(heap_t *heap)
{
	void *min_element = heap->root->data;
	binary_tree_node_t *last_node;

	if (heap->size == 0)
		return (NULL);

	if (heap->size == 1)
	{
		free(heap->root);
		heap->root = NULL;
		heap->size = 0;
		return (min_element);
	}

	last_node = get_last_node(heap);

	heap->root->data = last_node->data;

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	free(last_node);

	heapify(heap, heap->root);

	heap->size--;

	return (min_element);
}
