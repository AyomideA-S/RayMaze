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
	} else
	{
		*step_x = 1;
		*side_dist_x = (map_x + 1.0 - player_pos_x) * delta_dist_x;
	}
	/* Calculate step and initial side distance for y */
	if (ray_dir_y < 0)
	{
		*step_y = -1;
		*side_dist_y = (player_pos_y - map_y) * delta_dist_y;
	} else
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

/**
 * draw_vertical_line - Draw a vertical line on the screen
 *
 * @renderer: The renderer to use
 * @x: The x-coordinate of the line
 * @draw_start: The starting y-coordinate of the line
 * @draw_end: The ending y-coordinate of the line
 * @side: The side of the wall hit (x=0, y=1)
 */
void draw_vertical_line(SDL_Renderer *renderer, int x, int draw_start,
						int draw_end, int side)
{
	/* Set the color based on the side of the wall hit (x=0, y=1) */
	if (side == 1)
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
	else
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);

	/* Draw the vertical stripe for the current column */
	SDL_RenderDrawLine(renderer, x, draw_start, x, draw_end);
}

/**
 * render_scene - Render the scene using raycasting techniques
 *
 * @renderer: The renderer to use
 * @player: The player structure
 */
void render_scene(SDL_Renderer *renderer, Player *player)
{
	/* Loop through each column of the screen */
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		double ray_dir_x = 0, ray_dir_y = 0;	   /* Ray direction */
		int map_x = 0, map_y = 0;				   /* Map positions */
		double delta_dist_x = 0, delta_dist_y = 0; /* Delta distances */
		double side_dist_x = 0, side_dist_y = 0;   /* Side distances */
		int step_x = 0, step_y = 0;				   /* Step direction */
		int line_height = 0, side = 0;			   /* NS or EW wall hit? (NS=0, EW=1) */
		double perp_wall_dist = 0;				   /* Perpendicular wall distance */

		/* Calculate ray direction and map position */
		calculate_ray_direction(player, x, &ray_dir_x, &ray_dir_y,
								&delta_dist_x, &delta_dist_y, &map_x, &map_y);

		/* Determine step direction and initial side distance values */
		calculate_step_and_side_dist(ray_dir_x, ray_dir_y, player->pos_x,
										player->pos_y, map_x, map_y, delta_dist_x,
										delta_dist_y, &step_x, &step_y,
										&side_dist_x, &side_dist_y);

		/* Calculate distance to the point of impact and line height */
		calculate_distance_and_height(map_x, map_y, step_x, step_y, ray_dir_x,
										ray_dir_y, player->pos_x, player->pos_y,
										side, &perp_wall_dist, &line_height);

		/* Calculate lowest and highest pixel to fill in current stripe */
		int draw_start = -line_height / 2 + SCREEN_HEIGHT / 2 +
							(int)(player->pitch * SCREEN_HEIGHT / 2);
		int draw_end = line_height / 2 + SCREEN_HEIGHT / 2 +
						(int)(player->pitch * SCREEN_HEIGHT / 2);

		if (draw_start < 0)
			draw_start = 0;
		if (draw_end >= SCREEN_HEIGHT)
			draw_end = SCREEN_HEIGHT - 1;
		draw_vertical_line(renderer, x, draw_start, draw_end, side);
	}
}
