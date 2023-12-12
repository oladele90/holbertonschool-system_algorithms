#include "pathfinding.h"

point_t *right(point_t *start)
{
    start->y++;
    return (start);
}

point_t *down(point_t *start)
{
    start->x++;
    return (start);
}

point_t *left(point_t *start)
{
    start->y--;
    return (start);
}

point_t *up(point_t *start)
{
    start->x--;
    return (start);
}

point_t *pointdup(point_t *start)
{
    point_t *new_point = malloc(sizeof(point_t));

    new_point->x = start->x;
    new_point->y = start->y;
    return (new_point);
}

int find_path(queue_t *new, char **map, int rows, int cols, point_t *start, point_t const *target, char **visited)
{
    int on_target_path = 0;

    printf("Checking coordinates [%d, %d]\n", start->x, start->y);

    if (start->x >= rows || start->y >= cols)
        return (0);

    if (start->x == target->x && start->y == target->y)
    {
        queue_push_front(new, (void *)pointdup(start));
        return (1);
    }
    visited[start->y][start->x] = '1';
    on_target_path += find_path(new, map, rows, cols, right(start), target, visited);
    left(start);
    if (on_target_path)
    {
        queue_push_front(new, (void *)pointdup(start));
        return (1);
    }
    on_target_path += find_path(new, map, rows, cols, down(start), target, visited);
    up(start);
    if (on_target_path)
    {
        queue_push_front(new, (void *)pointdup(start));
        return (1);
    }
    on_target_path += find_path(new, map, rows, cols, left(start), target, visited);
    right(start);
    if (on_target_path)
    {
        queue_push_front(new, (void *)pointdup(start));
        return (1);
    }
    on_target_path += find_path(new, map, rows, cols, up(start), target, visited);
    down(start);

    if (on_target_path)
    {
        queue_push_front(new, (void *)pointdup(start));
        return (1);
    }

    return (0);
}
queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start, point_t const *target)
{
    int i;
    point_t *temp = malloc(sizeof(point_t));
    queue_t *new = queue_create();
    char **visited = (char **)calloc(rows, sizeof(char *));

    for (i = 0; i < rows; ++i)
        visited[i] = (char *)calloc(cols, sizeof(char));

    temp->x = start->x;
    temp->y = start->y;

    find_path(new, map, rows, cols, temp, target, visited);

    return (new);
}