#include "huffman.h"
#include "heap.h"

/**
 * data_cmp - Compares the frequencies of two symbols for heap ordering.
 *
 * @f1: Pointer to the first symbol.
 * @f2: Pointer to the second symbol.
 *
 * Return: The difference in frequencies (f1 - f2).
 */
int data_cmp(void *f1, void *f2)
{
	symbol_t *n1, *n2;
	binary_tree_node_t *one, *two;

	one = (binary_tree_node_t *)f1;
	two = (binary_tree_node_t *)f2;
	n1 = (symbol_t *)one->data;
	n2 = (symbol_t *)two->data;

	return ((int)n1->freq - (int)n2->freq);
}

/**
 * huffman_priority_queue - Creates a priority queue for Huffman coding.
 *
 * @data: Array of characters representing symbols.
 * @freq: Array of frequencies corresponding to each symbol.
 * @size: Number of elements in the arrays.
 *
 * Return: Pointer to the created heap representing the priority queue.
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	symbol_t *new_sym = NULL;
	binary_tree_node_t *new_node = NULL;
	heap_t *new_heap = NULL;
	size_t idx = 0;

	new_heap = heap_create(data_cmp);

	while (idx < size)
	{
		new_sym = symbol_create(data[idx], freq[idx]);
		new_node = binary_tree_node(new_heap->root, new_sym);
		heap_insert(new_heap, new_node);
		idx++;
	}

	return (new_heap);
}
