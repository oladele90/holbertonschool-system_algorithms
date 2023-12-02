#include "heap.h"
/**
 * delete - recursive function that frees data and roots of a heap
 * @root: the current root to free
 * @free_data: function that frees the data in a heap root
*/
void delete(binary_tree_node_t *root, void (*free_data)(void *))
{
	if (!root)
		return;
	delete(root->left, free_data);
	delete(root->right, free_data);
	if (free_data)
		free_data(root->data);
	free(root);

}
/**
 * heap_delete - deletes a heap
 * @heap: pointer to a heap struct
 * @free_data: function pointer that frees a roots stored data
*/
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	delete(heap->root, free_data);
	free(heap);
}
