#include "rb_trees.h"

/**
* bst_insert - inserts a node in avl tree
* @root: current root of tree
* @new: new node to insert
* Return: new root of tree
*/
static rb_tree_t *bst_insert(rb_tree_t *root, rb_tree_t *new)
{
    if (!new)
        return NULL;

    if (!root)
    {
        root = new;
        return root;
    }

    if (new->n > root->n)
    {
        root->right = bst_insert(root->right, new);
        if (root->right)
            root->right->parent = root;
    }
    else if (new->n < root->n)
    {
        root->left = bst_insert(root->left, new);
        if (root->left)
            root->left->parent = root;
    }

    return root;
}




static rb_tree_t *get_uncle(rb_tree_t *new)
{
    if (!new->parent || !new->parent->parent)
        return NULL;

    if (new->parent == new->parent->parent->left)
    {
        if (new->parent->parent->right)
            return new->parent->parent->right;
    }
    else
    {
        if (new->parent->parent->left)
            return new->parent->parent->left;
    }

    return NULL;
}

static rb_tree_t *fix_red_uncle(rb_tree_t *new, rb_tree_t *uncle)
{
    if (new->parent && new->parent->parent)
    {
        new->parent->color = BLACK;
        if (uncle)
            uncle->color = BLACK;
        new->parent->parent->color = RED;
        return new->parent->parent;
    }

    return new;
}


static rb_tree_t *insert_help(rb_tree_t *tree, rb_tree_t *new)
{
    rb_tree_t *uncle = get_uncle(new);

    if (uncle && uncle->color == RED)
    {
        new = fix_red_uncle(new, uncle);

        if (new->parent && new->parent->parent)
        {
            tree = insert_help(tree, new->parent->parent);
        }
    }

    return tree;
}


rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
    rb_tree_t *new;

    new = rb_tree_node(NULL, value, RED);
    *tree = bst_insert(*tree, new);

    if (new == *tree)
    {
        new->color = BLACK;
        return new;
    }
    else if (new->parent->color != BLACK)
{
    *tree = insert_help(*tree, new);
}

    return new;
}

