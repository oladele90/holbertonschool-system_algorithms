#include "huffman.h"
#include "heap.h"

/**
 * huffman_tree - Builds a Huffman tree from given data and frequencies.
 *
 * @data: Array of characters.
 * @freq: Array of corresponding frequencies.
 * @size: Size of the arrays.
 *
 * Return: Pointer to the root of the Huffman tree.
 */
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
	heap_t *priority_queue = NULL;
	binary_tree_node_t *root = NULL;

	priority_queue = huffman_priority_queue(data, freq, size);

	if (!priority_queue)
		return (NULL);

	while (priority_queue->size > 1)
		huffman_extract_and_insert(priority_queue);
	root = heap_extract(priority_queue);
	heap_delete(priority_queue, NULL);
	return (root);
}
