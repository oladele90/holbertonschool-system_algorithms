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

queue_t *find_path(queue_t *new, char **map, int rows, int cols, point_t *start, point_t const *target)
{
    if (start->x >= rows || start->y >= cols)
        return (new);

    printf("Checking coordinates [%d, %d]\n", start->x, start->y);

    if (start->x == target->x && start->y == target->y)
    {
        printf("herehere\n");
        queue_push_front(new, start);
        return (new);
    }

    if (map[start->x][start->y] == '1')
    {
        printf("in here\n");
        queue_push_front(new, start);

        if (find_path(new, map, rows, cols, right(start), target) )
            return (new);
        start = left(start);
        if (find_path(new, map, rows, cols, down(start), target))
            return (new);
        /*up(start);*/
        if (find_path(new, map, rows, cols, left(start), target))
            return (new);
        /*right(start);*/
        if (find_path(new, map, rows, cols, up(start), target))
            return (new);
        /*down(start);*/

        dequeue(new);
    }
    return (new);
}
queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start, point_t const *target)
{
    point_t *temp = malloc(sizeof(point_t));
    queue_t *new = queue_create();

    temp->x = start->x;
    temp->y = start->y;

    new = find_path(new, map, rows, cols, temp, target);

    return (new);
}