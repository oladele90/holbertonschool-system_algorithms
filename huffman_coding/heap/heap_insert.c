#include "heap.h"

/**
 * insert_node - Inserts a new node into a binary tree.
 * @root: Pointer to the root of the binary tree.
 * @new: Pointer to the new node to be inserted.
 *
 * Return: Pointer to the newly inserted node or NULL on failure.
 */
static binary_tree_node_t *insert_node(binary_tree_node_t *root,
										binary_tree_node_t *new)
{
	binary_tree_node_t *Q[50];
	int idx = 0, count = 1, i, c = 50;

	for(i = 0; i < c; i++)
		Q[i] = NULL;

	Q[idx] = root;
	while (Q[idx])
	{
		if (Q[idx]->left)
		{
			Q[count] = Q[idx]->left;
			count++;
		}
		else
		{
			Q[idx]->left = new;
			new->parent = Q[idx];
			return (new);
		}
		if (Q[idx]->right)
		{
			Q[count] = Q[idx]->right;
			count++;
		}
		else
		{
			Q[idx]->right = new;
			new->parent = Q[idx];
			return (new);
		}
		idx++;
	}
	return (NULL);
}

/**
 * make_node - Creates a new binary tree node with the given data.
 * @new: Pointer to the new node to be created.
 * @data: Pointer to the data to be stored in the new node.
 *
 * Return: Pointer to the newly created node or NULL on failure.
 
static binary_tree_node_t *make_node(binary_tree_node_t *new, void *data)
{
	new = malloc(sizeof(binary_tree_node_t));
	if (!new)
		return (NULL);
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	new->parent = NULL;
	return (new);
}*/

/**
 * heap_insert - Inserts a new node into a binary heap.
 * @heap: Pointer to the binary heap.
 * @data: Pointer to the data to be stored in the new node.
 *
 * Return: Pointer to the newly inserted node or NULL on failure.
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *new = NULL, *surfer;
	void *temp;

	if (!heap || !data)
		return (NULL);
	new = binary_tree_node(NULL, data);
	if (!heap->root)
	{
		heap->root = new;
		heap->size++;
		return (new);
	}
	insert_node(heap->root, new);
	if (new)
		heap->size++;
	surfer = new;
	while (surfer->parent &&
			heap->data_cmp(surfer->data, surfer->parent->data) < 0)
	{
		temp = surfer->data;
		surfer->data = surfer->parent->data;
		surfer->parent->data = temp;
		surfer = surfer->parent;
	}
	new = surfer;
	return (new);
}
