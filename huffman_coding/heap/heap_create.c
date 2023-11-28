#include "heap.h"

/**
 * heap_create - Creates a new heap.
 * @data_cmp: Pointer to the comparison function for the heap data.
 *
 * Return: Pointer to the newly created heap, or NULL on failure.
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *new;

	new = malloc(sizeof(heap_t));
	if (!new)
		return (NULL);

	new->data_cmp = data_cmp;
	new->size = 0;
	new->root = NULL;

	return (new);
}
