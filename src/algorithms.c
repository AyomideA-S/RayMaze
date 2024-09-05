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
 * @hit: A pointer to an integer to store the hit status
 */
void perform_dda(double *side_dist_x, double *side_dist_y, double delta_dist_x,
				 double delta_dist_y, int *map_x, int *map_y, int step_x,
				 int step_y, int *side, int **map, int *hit)
{
	/* Perform DDA until a wall is hit */
	while (*hit == 0)
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
			*hit = 1;
	}
}

/**
 * handle_map - Handle the map
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
 * @hit: A pointer to an integer to store the hit status
 */
void handle_map(double *side_dist_x, double *side_dist_y, double delta_dist_x,
				double delta_dist_y, int *map_x, int *map_y, int step_x,
				int step_y, int *side, int *hit)
{
	int map_width, map_height;
	int **dynamic_map = get_map_from_file("assets/maps/level0.map", &map_width,
										&map_height);

	/* Check if the map file exists and was loaded successfully */
	if (!dynamic_map)
	{
		perror("Failed to load map");
		return;
	}

	/* Call the DDA algorithm */
	perform_dda(side_dist_x, side_dist_y, delta_dist_x, delta_dist_y, map_x,
				map_y, step_x, step_y, side, dynamic_map, hit);

	/* Free memory allocated for the map */
	free_map(dynamic_map, map_height);
}
