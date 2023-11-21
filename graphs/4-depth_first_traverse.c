#include "graphs.h"

/**
 * dfs_recursive - Perform depth-first search recursively.
 * @vertex: Current vertex to explore.
 * @visited: Array to track visited vertices.
 * @depth: Current depth in the graph.
 * @action: Action to perform on each vertex.
 * @max_depth: Maximum depth reached so far.
 *
 * Return: The maximum depth reached during traversal.
 */
size_t dfs_recursive(vertex_t *vertex, int *visited, size_t depth,
					 void (*action)(const vertex_t *v, size_t depth),
					 size_t max_depth)
{
	edge_t *edge = vertex->edges;
	size_t result;

	if (!vertex || visited[vertex->index])
		return (depth - 1);

	action(vertex, depth);

	visited[vertex->index] = 1;

	while (edge)
	{
		result = dfs_recursive(edge->dest, visited, depth + 1,
									  action, max_depth);
		if (result > max_depth)
			max_depth = result;
		edge = edge->next;
	}
	return (max_depth);
}

/**
 * depth_first_traverse - Perform depth-first traversal of a graph.
 * @graph: Graph to traverse.
 * @action: Action to perform on each vertex during traversal.
 *
 * Return: The maximum depth reached during traversal.
 */
size_t depth_first_traverse(const graph_t *graph,
							void (*action)(const vertex_t *v, size_t depth))
{
	vertex_t *current_vertex = graph->vertices;
	size_t depth = 0;
	int *visited = calloc(graph->nb_vertices, sizeof(int));
	size_t max_depth = 0;

	if (!graph)
		return (0);

	depth = dfs_recursive(current_vertex, visited, depth, action, max_depth);

	free(visited);
	return (depth);
}
