#include "nary_trees.h"

/**
 * path_exists - Checks if a path exists in an N-ary tree.
 * @root: Pointer to the root node of the N-ary tree.
 * @path: Array of strings representing the path to check.
 *
 * Return: 1 if the path exists, 0 otherwise.
 */

int path_exists(nary_tree_t const *root, char const * const *path)
{
	nary_tree_t *temp = (nary_tree_t *)root;
	int i, flag, path_length = 0;

	while (path[path_length] != NULL)
		path_length++;

	for (i = 0; path[i] && path_length; i++)
	{
		flag = 0;
		while (temp && !flag)
		{
			if (strcmp(path[i], temp->content) == 0)
			{
				path_length--;
				temp = temp->children;
				flag = 1;
				break;
			}
			if (!flag)
				temp = temp->next;
		}
	}
	if (path_length)
		return (0);
	return (1);
}
