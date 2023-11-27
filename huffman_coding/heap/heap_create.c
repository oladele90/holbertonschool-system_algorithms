#include "heap.h"


heap_t *heap_create(int (*data_cmp)(void *, void *))
{
    heap_t *new;

    new = malloc(sizeof(heap_t));
    new->data_cmp = data_cmp;
    new->size = 0;
    new->root = NULL;
    return (new);
}