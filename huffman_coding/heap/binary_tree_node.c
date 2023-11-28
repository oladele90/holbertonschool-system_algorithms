#include "heap.h"


binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
    binary_tree_node_t *new;

    new = malloc(sizeof(binary_tree_node_t));
    if (!new)
        return NULL;
    if (!data)
        return NULL;

    new->parent = parent;
    new->left = NULL;
    new->right = NULL;
    new->data = data;
    return (new);
}