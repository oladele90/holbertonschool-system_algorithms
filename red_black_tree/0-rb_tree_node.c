#include "rb_trees.h"

/**
 * rb_tree_node - Creates a new red-black tree node
 * @parent: Pointer to the parent node
 * @value: Value to be stored in the node
 * @color: Color of the node (RED or BLACK)
 * Return: Pointer to the newly created node, or NULL on failure
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *new_node;

	new_node = malloc(sizeof(rb_tree_t));
	if (!new_node)
		return (NULL);

	new_node->color = color;
	new_node->n = value;
	new_node->right = NULL;
	new_node->left = NULL;
	new_node->parent = parent;

	return (new_node);
}

/**
 * rb_tree_rotate_right - balances tree by rotating right
 * @node: tree to balance
 * Return: pointer to tree
 */
rb_tree_t *rb_tree_rotate_right(rb_tree_t *node)
{
    rb_tree_t *x = node->left;
    rb_tree_t *y = x->right;

	if (!node || !node->left)
        return node;
    x->right = node;
    node->left = y;
    node->parent = x;

    if (y)
        y->parent = node;

    return x;
}

/**
 * rb_tree_rotate_left - balances tree by rotating left
 * @node: tree to balance
 * Return: pointer to tree
 */
rb_tree_t *rb_tree_rotate_left(rb_tree_t *node)
{
    rb_tree_t *x, *y;

    if (!node || !node->right)
    {
        return node;
    }

    x = node->right;
    y = x->left;

    if (y)
    {
        x->left = node;
        node->right = y;
        node->parent = x;
        if (y)
            y->parent = node;
    }
    else
    {
        x->left = node;
        node->right = NULL;
        node->parent = x;
    }

    return x;
}



/**
* rb_tree_rotate_right - balances tree by rotating right
* @tree: tree to balance
* Return: pointer to tree

rb_tree_t *rb_tree_rotate_right(rb_tree_t *tree)
{
	rb_tree_t *old = NULL, *new = NULL, *temp = NULL;

	if (!tree || !tree->left)
		return (tree);
	old = tree;
	new = tree->left;
	if (old->parent)
	{
		if (old == old->parent->right)
			old->parent->right = new;
		else
			old->parent->left = new;
		temp = old->parent;
	}
	old->parent = new;
	if (new->right)
	{
		old->left = new->right;
		new->right->parent = old;
	}
	else
		old->left = NULL;
	new->right = old;
	new->parent = temp;
	if (old->left)
		old->left->parent = old;
	return (new);
}


* rb_tree_rotate_left - balances tree by rotating left
* @tree: tree to balance
* Return: pointer to tree

rb_tree_t *rb_tree_rotate_left(rb_tree_t *tree)
{
	rb_tree_t *old = NULL, *new = NULL, *temp = NULL;

	if (!tree || !tree->right)
		return (tree);
	old = tree;
	new = tree->right;
	if (old->parent)
	{
		if (old == old->parent->left)
			old->parent->left = new;
		else
			old->parent->right = new;
		temp = old->parent;
	}
	old->parent = new;
	if (new->left)
	{
		old->right = new->left;
		new->left->parent = old;
	}
	else
		old->right = NULL;
	new->left = old;
	new->parent = temp;
	if (old->right)
		old->right->parent = old;
	return (new);
}*/
