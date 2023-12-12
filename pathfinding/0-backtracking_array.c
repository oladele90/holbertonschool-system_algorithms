#include "pathfinding.h"

point_t *right(point_t *start)
{
    start->x++;
    return (start);
}

point_t *down(point_t *start)
{
    start->y++;
    return (start);
}

point_t *left(point_t *start)
{
    start->x--;
    return (start);
}

point_t *up(point_t *start)
{
    start->y--;
    return (start);
}

point_t *pointdup(point_t *start)
{
    point_t *new_point = malloc(sizeof(point_t));

    new_point->x = start->x;
    new_point->y = start->y;
    return (new_point);
}

queue_t *find_path(queue_t *new, char **map, int rows, int cols, point_t *start, point_t const *target)
{
    int on_target_path = 0;

    if (start->x >= rows || start->y >= cols)
        return (new);

    printf("Checking coordinates [%d, %d]\n", start->x, start->y);

    if (start->x == target->x && start->y == target->y)
    {
        printf("herehere\n");
        queue_push_front(new, start);
        return (new);
    }

    if (map[start->y][start->x] == '0')
    {
        
        if (find_path(new, map, rows, cols, right(start), target))
            on_target_path = 1;
        left(start);
        if (find_path(new, map, rows, cols, down(start), target))
            on_target_path = 1;
        up(start);
        if (find_path(new, map, rows, cols, left(start), target))
            on_target_path = 1;
        right(start);
        if (find_path(new, map, rows, cols, up(start), target))
            on_target_path = 1;
        down(start);

        if (on_target_path)
        {
            map[start->y][start->x] = '1';
            queue_push_front(new, pointdup(start));
            return (new);
        }

        dequeue(new);

    }
    return (NULL);
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