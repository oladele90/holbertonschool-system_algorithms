#include "heap.h"
void delete(binary_tree_node_t *root, void (*free_data)(void *))
{
	if (!root)
		return;
	delete(root->left, free_data);
	delete(root->right, free_data);
	free_data(root->data);
	free(root);

}
/**
 * heap_delete - Deletes all roots in the heap and frees associated memory.
 * @heap: Pointer to the heap structure.
 * @free_data: Pointer to the function used to free data in each root.
 */

void heap_delete(heap_t *heap, void (*free_data)(void *))
{

	delete(heap->root, free_data);
	free(heap);
}