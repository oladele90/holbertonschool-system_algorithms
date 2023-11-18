#include "graphs.h"

/**
 * graph_add_edge - Adds an edge between two vertices in a graph
 * @graph: Pointer to the graph
 * @src: Source vertex content
 * @dest: Destination vertex content
 * @type: Type of edge
 *
 * Return: 1 on success, 0 on failure
 */
int graph_add_edge(graph_t *graph, const char *src,
					const char *dest, edge_type_t type)
{
	vertex_t *from, *to;
	edge_t *edge = NULL;

	if (!dest || !src || !graph)
		return (0);

	from = find_vertex(graph, src);
	if (!from)
		return (0);

	to = find_vertex(graph, dest);
	if (!to)
		return (0);

	from->edges = edge_create(from, to, edge);
	if (from->edges)
		from->nb_edges++;

	if (type)
	{
		to->edges = edge_create(to, from, edge);
		to->nb_edges++;
	}

	return (1);
}

/**
 * edge_create - Creates a new edge between two vertices
 * @from: Source vertex
 * @to: Destination vertex
 * @edge: Pointer to the edge
 *
 * Return: Pointer to the edges of the source vertex
 */
edge_t *edge_create(vertex_t *from, vertex_t *to, edge_t *edge)
{
	edge_t *temp;

	edge = malloc(sizeof(edge_t));
	edge->dest = to;
	edge->next = NULL;

	temp = from->edges;

	if (!temp)
		return (edge);

	while (temp->next)
		temp = temp->next;
	temp->next = edge;

	return (from->edges);
}

/**
 * find_vertex - Finds a vertex in the graph by content
 * @graph: Pointer to the graph
 * @content: Content of the vertex to find
 *
 * Return: Pointer to the vertex if found, otherwise NULL
 */
vertex_t *find_vertex(graph_t *graph, const char *content)
{
	vertex_t *temp;

	temp = graph->vertices;

	if (strcmp(content, temp->content) == 0)
		return (temp);

	while (temp->next)
	{
		if (strcmp(content, temp->content) == 0)
			return (temp);
		temp = temp->next;
	}

	if (strcmp(content, temp->content) != 0)
		return (NULL);

	return (temp);
}
