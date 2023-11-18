#include "graphs.h"

/**
 * graph_add_vertex - Adds a vertex to the graph
 * @graph: Pointer to the graph
 * @str: Content of the new vertex
 *
 * Return: Pointer to the new vertex on success, NULL on failure
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *vertex = NULL, *temp;

	if (!graph || !str)
		return (NULL);

	temp = graph->vertices;

	if (!temp)
	{
		vertex = build_vertex(vertex, str);
		graph->vertices = vertex;
		graph->nb_vertices++;
		return (vertex);
	}
	else
	{
		while (temp->next)
		{
			if (strcmp(str, temp->content) == 0)
				return (NULL);
			temp = temp->next;
		}

		if (strcmp(str, temp->content) == 0)
			return (NULL);

		vertex = build_vertex(vertex, str);
		vertex->index = temp->index + 1;
		temp->next = vertex;
		graph->nb_vertices++;
	}

	return (vertex);
}

/**
 * build_vertex - Creates a new vertex with the given content
 * @vertex: Pointer to the vertex structure
 * @str: Content of the new vertex
 *
 * Return: Pointer to the new vertex
 */
vertex_t *build_vertex(vertex_t *vertex, const char *str)
{
	vertex = malloc(sizeof(vertex_t));
	vertex->index = 0;
	vertex->content = strdup(str);
	vertex->nb_edges = 0;
	vertex->edges = NULL;
	vertex->next = NULL;
	return (vertex);
}
