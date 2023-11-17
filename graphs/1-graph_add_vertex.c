#include "graphs.h"


vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
    vertex_t *vertex = NULL, *temp;

    temp = graph->vertices;
    if (!temp)
    {
        printf("temp is null\n");
        vertex = build_vertex(vertex, str);
        printf("%s\n", vertex->content);
        graph->vertices = vertex;
        graph->nb_vertices++;
        return (vertex);
    }
    else{
        while (temp->next)
        {
            if (strcmp(str, temp->content) == 0)
                    return (NULL);
            temp = temp->next;
        }
        if (strcmp(str, temp->content) == 0)
            return (NULL);
        vertex = build_vertex(vertex, str);
        temp = vertex;
        graph->nb_vertices++;
    }
    return (vertex);

}

vertex_t *build_vertex(vertex_t* vertex, const char *str)
{
    vertex = malloc(sizeof(vertex_t));
    vertex->index = 0;
    vertex->content = strdup(str);
    vertex->nb_edges = 0;
    vertex->edges = NULL;
    vertex->next = NULL;
    return (vertex);
}