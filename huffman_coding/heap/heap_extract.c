#include "heap.h"

/**
 * get_last_node - Gets the value of the last node in the heap and removes it.
 * @heap: Pointer to the heap structure.
 *
 * Return: The value of the last node.
 */
size_t get_last_node(heap_t *heap)
{
	binary_tree_node_t *Q[50];
	size_t count = 0, idx = 0;
	size_t min = 0;
	size_t last_index = heap->size - 1;

	if (!heap || !heap->root)
		return (0);

	Q[idx] = heap->root;

	while (count < last_index)
	{
		if (Q[idx]->left)
			Q[++count] = Q[idx]->left;

		if (Q[idx]->right)
			Q[++count] = Q[idx]->right;

		idx++;
	}

	if (Q[0]->data)
	{
		min = *(size_t *)Q[0]->data;
		Q[0]->data = Q[last_index]->data;
		free(Q[last_index]);

		if (last_index > 0)
		{
			binary_tree_node_t *parent = Q[(last_index - 1) / 2];

			if (parent->left == Q[last_index])
				parent->left = NULL;
			else
				parent->right = NULL;
		}
	}

	return (min);
}

/**
 * heapify_down - Maintains the heap property by fixing violations.
 * @heap: Pointer to the heap structure.
 */
void heapify_down(heap_t *heap)
{
	binary_tree_node_t *current = heap->root;
	binary_tree_node_t *child;

	if (!heap || !heap->root)
		return;

	while (current->left || current->right)
	{
		child = current->left;

		if (current->right && heap->data_cmp(current->right->data, child->data) < 0)
			child = current->right;

		if (heap->data_cmp(child->data, current->data) < 0)
		{
			void *temp = current->data;

			current->data = child->data;
			child->data = temp;
			current = child;
		}
		else
		{
			break;
		}
	}
}

/**
 * heap_extract - Extracts the minimum value from the heap.
 * @heap: Pointer to the heap structure.
 *
 * Return: Pointer to the extracted minimum value.
 */
void *heap_extract(heap_t *heap)
{
	size_t *min_value;

	if (!heap)
		return (NULL);

	min_value = malloc(sizeof(size_t));
	if (!min_value)
		return (NULL);

	*min_value = get_last_node(heap);
	heap->size--;
	heapify_down(heap);

	return ((void *)min_value);
}
