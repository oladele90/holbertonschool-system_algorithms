#include "pathfinding.h"

/**
 * was_visited - checks if a cell has been visited
 * @visited: the visited array
 * @x: the x coordinate
 * @y: the y coordinate
 * Return: 1 if has been visited, else 0
 */
static int was_visited(char **visited, int x, int y)
{
	return (visited[y][x] == '1');
}

/**
 * point_dup - allocate a point struct onto the heap
 * @point: the point to be copied
 * Return: the copied point
 */
static point_t *point_dup(point_t *point)
{
	point_t *copy = malloc(sizeof(point_t));

	copy->x = point->x;
	copy->y = point->y;
	return (copy);
}

/**
 * can_visit - checks if the next move is valid
 * @map: the map being navigated
 * @rows: number of rows
 * @cols: number of cols
 * @next_move: coordinates of the next attempted move
 * Return: 1 if valid move, else 0
 */
static int can_visit(char **map, int rows, int cols, point_t *next_move)
{
	int x = next_move->x;
	int y = next_move->y;

	return (x < rows && x >= 0 && y < cols && y >= 0 && map[y][x] == '0');
}

/**
 * find_path - solves a maze using backtracking
 * @map: the map to navigate
 * @rows: number of rows
 * @cols: number of cols
 * @current: coordinates of the current position
 * @target: coordinates of the target position
 * @queue: the queue that holds the final path
 * @visited: array to keep track of visited cells
 * Return: 1 if found path, else 0
 */
static int find_path(char **map, int rows, int cols, point_t *current,
					  point_t *target, queue_t *queue, char **visited)
{
	point_t next_move, *next_move_dup;

	int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	int on_target_path = 0, i;

	printf("Checking coordinates [%d, %d]\n", current->x, current->y);
	visited[current->y][current->x] = '1';

	if (current->x == target->x && current->y == target->y)
	{
		next_move_dup = point_dup(current);
		queue_push_front(queue, (void *)next_move_dup);
		return (1);
	}

	for (i = 0; i < 4; ++i)
	{
		next_move.x = current->x + directions[i][0];
		next_move.y = current->y + directions[i][1];

		if (can_visit(map, rows, cols, &next_move) &&
			!was_visited(visited, next_move.x, next_move.y))
		{
			on_target_path += find_path(map, rows, cols, &next_move,
										target, queue, visited);
		}

		if (on_target_path)
			break;
	}

	if (on_target_path)
	{
		queue_push_front(queue, (void *)point_dup(current));
		return (1);
	}

	return (0);
}

/**
 * backtracking_array - finds a path using backtracking
 * @map: the map to navigate
 * @rows: number of rows
 * @cols: number of cols
 * @start: the starting coordinates
 * @target: the target coordinates
 * Return: queue with the path to target
 */
queue_t *backtracking_array(char **map, int rows, int cols,
							 point_t const *start, point_t const *target)
{
	int i;
	queue_t *queue;
	point_t *current = malloc(sizeof(point_t));
	point_t *finish = malloc(sizeof(point_t));
	char **visited = (char **)calloc(rows, sizeof(char *));

	for (i = 0; i < rows; ++i)
		visited[i] = (char *)calloc(cols, sizeof(char));

	queue = queue_create();
	*current = *start;
	*finish = *target;
	find_path(map, rows, cols, current, finish, queue, visited);

	if (!queue->front)
	{
		free(queue);
		queue = NULL;
	}

	free(current);
	free(finish);

	for (i = 0; i < rows; ++i)
		free(visited[i]);

	free(visited);

	return (queue);
}
