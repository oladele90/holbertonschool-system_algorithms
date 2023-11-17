#include "graphs.h"


graph_t *graph_create(void)
{
    vertex_t *vertex = malloc(sizeof(vertex_t));
    graph_t *graph = malloc(sizeof(graph_t));

    vertex = NULL;
    graph->vertices = vertex;
    graph->nb_vertices = 0;
    return (graph);
}
