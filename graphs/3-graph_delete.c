#include "graphs.h"

/**
 * graph_delete - Deletes an entire graph
 * @graph: Pointer to the graph to be deleted
 */
void graph_delete(graph_t *graph)
{
	vertex_t *vertex_surfer;

	if (!graph)
		return;
	if (!graph->vertices)
	{
		free(graph);
		return;
	}
	while (graph->nb_vertices > 1)
	{
		vertex_surfer = graph->vertices;
		graph->vertices = graph->vertices->next;

		free_edges(vertex_surfer);

		free(vertex_surfer->content);
		free(vertex_surfer);
		graph->nb_vertices--;
	}

	free_edges(graph->vertices);
	free(graph->vertices->content);
	free(graph->vertices);
	free(graph);
}

/**
 * free_edges - Frees all edges of a vertex
 * @vertex_surfer: Pointer to the vertex whose edges are to be freed
 */
void free_edges(vertex_t *vertex_surfer)
{
	edge_t *edge_surfer;

	while (vertex_surfer->nb_edges > 1)
	{
		edge_surfer = vertex_surfer->edges;
		vertex_surfer->edges = vertex_surfer->edges->next;

		free(edge_surfer);
		vertex_surfer->nb_edges--;
	}

	free(vertex_surfer->edges);
}
