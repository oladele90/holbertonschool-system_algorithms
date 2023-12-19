#include "nary_trees.h"

/**
 * nary_traverse - Recursively traverses an N-ary tree
 * @node: Pointer to the current node being traversed
 * @depth: Depth of the current node in the tree
 * @action: Pointer to a function to execute for each node being traversed
 * @max: Pointer to the variable tracking the maximum depth
 */
void nary_traverse(const nary_tree_t *node, size_t depth,
	void (*action)(nary_tree_t const *node, size_t depth), size_t *max)
{
	nary_tree_t *temp;

	action(node, depth);

	if (depth > *max)
		*max = depth;

	for (temp = node->children; temp != NULL; temp = temp->next)
		nary_traverse(temp, depth + 1, action, max);

}


/**
 * nary_tree_traverse - Goes through an N-ary tree, node by node
 * @root: Pointer to the root node of the tree to traverse
 * @action: Pointer to a function to execute for each node being traversed
 *
 * Return: The biggest depth of the tree pointed to by root
 */
size_t nary_tree_traverse(nary_tree_t const *root,
	void (*action)(nary_tree_t const *node, size_t depth))
{
	size_t max = 0;

	if (!root || !action)
		return (0);

	nary_traverse(root, 0, action, &max);
	return (max);
}
