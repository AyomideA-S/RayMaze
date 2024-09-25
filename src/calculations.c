#include "main.h"
#include "game.h"
#include "raycaster.h"

/**
 * calculate_ray_direction - Calculate the ray direction and map position
 *
 * @player: The player structure
 * @x: The x-coordinate of the screen
 * @ray_dir_x: The x-component of the ray direction
 * @ray_dir_y: The y-component of the ray direction
 * @delta_dist_x: The x-component of the delta distance
 * @delta_dist_y: The y-component of the delta distance
 * @map_x: The x-coordinate of the map
 * @map_y: The y-coordinate of the map
 */
void calculate_ray_direction(Player *player, int x, double *ray_dir_x,
							 double *ray_dir_y, double *delta_dist_x,
							 double *delta_dist_y, int *map_x, int *map_y)
{
	/* x-coordinate in camera space */
	double camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	/* Calculate ray position and direction */
	*ray_dir_x = player->dir_x + player->plane_x * camera_x;
	*ray_dir_y = player->dir_y + player->plane_y * camera_x;

	/* Map positions */
	*map_x = (int)player->pos_x;
	*map_y = (int)player->pos_y;

	/* Length of ray from one x or y-side to next x or y-side */
	*delta_dist_x = (*ray_dir_x == 0) ? 1e30 : fabs(1 / *ray_dir_x);
	*delta_dist_y = (*ray_dir_y == 0) ? 1e30 : fabs(1 / *ray_dir_y);
}

/**
 * calculate_step_and_side_dist - Calculate the step and side distance
 *
 * @ray_dir_x: The x-component of the ray direction
 * @ray_dir_y: The y-component of the ray direction
 * @player_pos_x: The x-coordinate of the player's position
 * @player_pos_y: The y-coordinate of the player's position
 * @map_x: The x-coordinate of the map
 * @map_y: The y-coordinate of the map
 * @delta_dist_x: The x-component of the delta distance
 * @delta_dist_y: The y-component of the delta distance
 * @step_x: The x-component of the step
 * @step_y: The y-component of the step
 * @side_dist_x: The x-component of the side distance
 * @side_dist_y: The y-component of the side distance
 */
void calculate_step_and_side_dist(double ray_dir_x, double ray_dir_y,
								  double player_pos_x, double player_pos_y,
								  int map_x, int map_y, double delta_dist_x,
								  double delta_dist_y, int *step_x,
								  int *step_y, double *side_dist_x,
								  double *side_dist_y)
{
	/* Calculate step and initial side distance for x */
	if (ray_dir_x < 0)
	{
		*step_x = -1;
		*side_dist_x = (player_pos_x - map_x) * delta_dist_x;
	}
	else
	{
		*step_x = 1;
		*side_dist_x = (map_x + 1.0 - player_pos_x) * delta_dist_x;
	}
	/* Calculate step and initial side distance for y */
	if (ray_dir_y < 0)
	{
		*step_y = -1;
		*side_dist_y = (player_pos_y - map_y) * delta_dist_y;
	}
	else
	{
		*step_y = 1;
		*side_dist_y = (map_y + 1.0 - player_pos_y) * delta_dist_y;
	}
}

/**
 * calculate_distance_and_height - Calculate the distance and height of the
 * wall hit by the ray
 *
 * @map_x: The x-coordinate of the map
 * @map_y: The y-coordinate of the map
 * @step_x: The x-component of the step
 * @step_y: The y-component of the step
 * @ray_dir_x: The x-component of the ray direction
 * @ray_dir_y: The y-component of the ray direction
 * @player_pos_x: The x-coordinate of the player's position
 * @player_pos_y: The y-coordinate of the player's position
 * @side: The side of the wall hit
 * @perp_wall_dist: The perpendicular wall distance
 * @line_height: The height of the line to draw on the screen
 */
void calculate_distance_and_height(int map_x, int map_y, int step_x,
								   int step_y, double ray_dir_x, double ray_dir_y,
								   double player_pos_x, double player_pos_y,
								   int side, double *perp_wall_dist,
								   int *line_height)
{
	/**
	 * Calculate distance projected on camera direction
	 * (Euclidean distance will give fisheye effect!)
	 */
	if (side == 0)
		*perp_wall_dist = (map_x - player_pos_x + (1 - step_x) / 2) / ray_dir_x;
	else
		*perp_wall_dist = (map_y - player_pos_y + (1 - step_y) / 2) / ray_dir_y;

	/* Calculate height of line to draw on screen */
	*line_height = (int)(SCREEN_HEIGHT / *perp_wall_dist);
}
