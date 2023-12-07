#include "huffman.h"
#include "heap.h"

#include "heap.h"

/**
 * huffman_extract_and_insert - Perform a Huffman coding step.
 *
 * @priority_queue: Pointer to the heap representing the priority queue.
 *
 * Return: 1 on success, 0 on failure.
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
	binary_tree_node_t *node1 = heap_extract(priority_queue);
	binary_tree_node_t *node2 = heap_extract(priority_queue);
	binary_tree_node_t *node;
	symbol_t *symbol;

	if (!priority_queue)
		return (0);

	symbol = symbol_create(-1, ((symbol_t *)node1->data)->freq +
							((symbol_t *)node2->data)->freq);

	node = binary_tree_node(NULL, symbol);

	node->left = node1;
	node->right = node2;
	node1->parent = node;
	node2->parent = node;

	heap_insert(priority_queue, node);

	return (1);
}
