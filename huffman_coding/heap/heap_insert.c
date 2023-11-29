#include "heap.h"

static binary_tree_node_t *insert_node(binary_tree_node_t *root, binary_tree_node_t *new)
{
    binary_tree_node_t *Q[50];
    int idx = 0, count = 0;

    Q[idx] = root;
    while (Q[idx] != NULL)
    {
        count++;
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
}

binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
    binary_tree_node_t *new = NULL, *surfer;
    void *temp;

    if (!heap || !data)
        return (NULL);
    new = make_node(new, data);
    if (!heap->root)
    {
       heap->root = new;
       heap->size++;
       return (new);
    }
    new = insert_node(heap->root, new);
    if (new)
        heap->size++;
    surfer = new;
    while (surfer->parent && heap->data_cmp(surfer->data, surfer->parent->data) < 0)
    {
        temp = surfer->data;
        surfer->data = surfer->parent->data;
        surfer->parent->data = temp;
        surfer = surfer->parent;
    }
    new = surfer;
    return(new);
}


