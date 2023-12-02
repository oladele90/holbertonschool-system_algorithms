#include "heap.h"

void heapify(heap_t *heap, binary_tree_node_t *node)
{
    binary_tree_node_t *smallest = node;
    binary_tree_node_t *left_child = node->left;
    binary_tree_node_t *right_child = node->right;

    if (left_child != NULL && heap->data_cmp(left_child->data, smallest->data) < 0)
        smallest = left_child;

    if (right_child != NULL && heap->data_cmp(right_child->data, smallest->data) < 0)
        smallest = right_child;

    if (smallest != node)
	{
        void *temp = node->data;
        node->data = smallest->data;
        smallest->data = temp;

        heapify(heap, smallest);
    }
}
/**
 * get_last_node - Finds the last node in the heap.
 * @heap: Pointer to the heap structure.
 *
 * Return: Pointer to the last node.
 */

binary_tree_node_t *get_last_node(heap_t *heap)
{
	binary_tree_node_t *current = heap->root;

    if (heap->size == 0)
        return (NULL);

    while (current->left != NULL || current->right != NULL)
	{
        if (current->left != NULL)
			current = current->left;
        else
            current = current->right;
    }

    return (current);
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
        return NULL;

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
