#include "graphs.h"

int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type)
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
    printf("%lu\n", from->nb_edges);
    return (1);

}

edge_t *edge_create(vertex_t *from, vertex_t *to, edge_t *edge)
{
    edge_t *temp;

    edge = malloc(sizeof(edge_t));
    edge->dest = to;
    edge->next = NULL;
    temp = from->edges;
    if (!temp)
        return (edge);
    else
    {
        while (temp->next)
            temp = temp->next;
        temp->next = edge;
    }
    return (from->edges);
}

vertex_t *find_vertex(graph_t *graph, const char *content)
{
    vertex_t *temp;
    int i = 0;

    temp = graph->vertices;
    if (strcmp(content, temp->content) == 0)
        return (temp);
    while (temp->next)
    {
        printf("loop%d\n", i);
        if (strcmp(content, temp->content) == 0)
            return (temp);
        temp = temp->next;
        i++;
    }
    if (strcmp(content, temp->content) != 0)
        return (NULL);
    return (temp);
}
