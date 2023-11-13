#include "rb_trees.h"

/**
 * is_bst - Checks if a tree is a BST
 * @tree: The tree to check
 * @min: The minimum allowed value in the tree
 * @max: The maximum allowed value in the tree
 * Return: 1 if BST, or 0
 */
static int is_bst(const rb_tree_t *tree, int min, int max);

/**
 * color_check - Checks if red nodes have only black children
 * @tree: The tree to check
 * Return: 1 if valid, 0 otherwise
 */
static int color_check(const rb_tree_t *tree);

/**
 * rb_height - Gets the height of a red-black tree
 * @tree: The red-black tree
 * Return: Height of the tree or -1
 */
static int rb_height(const rb_tree_t *tree);

/**
 * rb - Checks if a tree is a red-black tree
 * @tree: The binary tree to check
 * Return: 1 if valid, 0 otherwise
 */
static int rb(const rb_tree_t *tree);

/**
 * black_check - Checks if all paths have the same number of black nodes
 * @tree: The tree to check
 * Return: 1 if valid, 0 otherwise
 */
static int black_check(const rb_tree_t *tree);

/**
 * rb_tree_is_valid - Checks if a red-black tree is valid
 * @tree: The red-black tree to check
 * Return: 1 if valid, 0 otherwise
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (!tree || tree->color != BLACK)
		return (0);
	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	return (rb(tree));
}

/**
 * is_bst - Checks if a tree is a BST
 * @tree: The tree to check
 * @min: The minimum allowed value in the tree
 * @max: The maximum allowed value in the tree
 * Return: 1 if BST, or 0
 */
static int is_bst(const rb_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
			is_bst(tree->right, tree->n, max));
}

/**
 * color_check - Checks if red nodes have only black children
 * @tree: The tree to check
 * Return: 1 if valid, 0 otherwise
 */
static int color_check(const rb_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->color == RED)
	{
		if (tree->parent && tree->parent->color == RED)
			return (0);
		if (tree->left && tree->left->color == RED)
			return (0);
		if (tree->right && tree->right->color == RED)
			return (0);

		if (!color_check(tree->left) || !color_check(tree->right))
			return (0);
	}
	return (1);
}

/**
 * rb_height - Gets the height of a tree
 * @tree: The tree to get height
 * Return: Height of the tree or -1
 */
static int rb_height(const rb_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);

	left_height = rb_height(tree->left);
	right_height = rb_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * rb - Checks if a tree is a red-black tree
 * @tree: The tree to check
 * Return: 1 if valid or 0
 */
static int rb(const rb_tree_t *tree)
{
	int right_height, left_height;

	if (!tree)
		return (1);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	left_height = rb_height(tree->left);
	right_height = rb_height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	if (!rb(tree->left) || !rb(tree->right))
		return (0);

	if (!color_check(tree))
		return (0);

	if (!black_check(tree))
		return (0);

	return (1);
}

/**
 * black_check - Checks if all paths have the same number of black nodes
 * @tree: The tree to check
 * Return: 1 if valid or 0
 */
static int black_check(const rb_tree_t *tree)
{
	int l = 0, r = 0;

	if (!tree)
		return (0);
	if (tree->left && tree->left->color == BLACK)
		l = 1;
	if (tree->right && tree->right->color == BLACK)
		r = 1;

	l += black_check(tree->left);
	r += black_check(tree->right);

	return ((l == r) ? 1 : 0);
}
