#include "graphs.h"

/**
 * graph_create - Creates a new graph
 *
 * Return: Pointer to the new graph on success, NULL on failure
 */
graph_t *graph_create(void)
{
	graph_t *graph = malloc(sizeof(graph_t));

	graph->vertices = NULL;
	graph->nb_vertices = 0;
	return (graph);
}
