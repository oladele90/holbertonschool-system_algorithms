#include "graphs.h"


graph_t *graph_create(void)
{
    graph_t *graph = malloc(sizeof(graph_t));

    graph->vertex = NULL;
    graph->nb_vertices = 0;
    return (graph);
}
