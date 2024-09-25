#include "game.h"
#include "raycaster.h"

/**
 * perform_dda - Perform the Digital Differential Analysis (DDA) algorithm
 *
 * @side_dist_x: The x-component of the side distance
 * @side_dist_y: The y-component of the side distance
 * @delta_dist_x: The x-component of the delta distance
 * @delta_dist_y: The y-component of the delta distance
 * @map_x: The x-coordinate of the map
 * @map_y: The y-coordinate of the map
 * @step_x: The x-component of the step
 * @step_y: The y-component of the step
 * @side: The side of the wall hit
 * @map: The world map
 * @width: The width of the map
 * @height: The height of the map
 */
void perform_dda(double *side_dist_x, double *side_dist_y, double delta_dist_x,
				 double delta_dist_y, int *map_x, int *map_y, int step_x,
				 int step_y, int *side, int **map, int width, int height)
{
	int hit = 0;
	/* Perform DDA until a wall is hit */
	while (hit == 0 && *map_x >= 0 && *map_x < width && *map_y >= 0 &&
		   *map_y < height)
	{
		/* Jump to next map square, OR in x-direction, OR in y-direction */
		if (*side_dist_x < *side_dist_y)
		{
			/* jump to next x-side */
			*side_dist_x += delta_dist_x;
			*map_x += step_x;
			*side = 0;
		}
		else
		{
			/* jump to next y-side */
			*side_dist_y += delta_dist_y;
			*map_y += step_y;
			*side = 1;
		}

		/* Check if ray has hit a wall */
		if (map[*map_y][*map_x] > 0)
			hit = 1;
	}
}
