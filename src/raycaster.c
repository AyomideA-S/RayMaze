#include "main.h"
#include "game.h"
#include "raycaster.h"

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
 * Raycasting is a technique used in computer graphics to render a 3D scene
 * from a 2D perspective. It involves casting rays from the viewpoint of the
 * camera and determining the intersection points with objects in the scene.
 *
 * This allows for the creation of a 2D image that simulates a 3D environment.
 * This is known as a "2.5D" technique, as it creates the illusion of depth.
 *
 * Raycasting is computationally efficient and can produce realistic results.
 * It is popularly used in video games to create realistic 3D graphics.
 * It was used in early first-person shooter games like Wolfenstein 3D & Doom.
 *
 * @renderer: The renderer to use
 * @player: The player structure
 * @world_map: The 2D array representing the world map
 * @width: The width of the world map
 * @height: The height of the world map
 */
void render_scene(SDL_Renderer *renderer, Player *player, int **world_map,
				  int width, int height)
{
	/* Loop through each column of the screen */
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		double ray_dir_x = 0, ray_dir_y = 0;				/* Ray direction */
		int map_x = 0, map_y = 0;							/* Map positions */
		double delta_dist_x = 0, delta_dist_y = 0;		/* Delta distances */
		double side_dist_x = 0, side_dist_y = 0;		/* Side distances */
		int step_x = 0, step_y = 0;						/* Step direction */
		int line_height = 0, side = 0;	/* NS or EW wall hit? (NS=0, EW=1) */
		double perp_wall_dist = 0;			/* Perpendicular wall distance */

		/* Calculate ray direction and map position */
		calculate_ray_direction(player, x, &ray_dir_x, &ray_dir_y,
								&delta_dist_x, &delta_dist_y, &map_x, &map_y);
		/* Determine step direction and initial side distance values */
		calculate_step_and_side_dist(ray_dir_x, ray_dir_y, player->pos_x,
			player->pos_y, map_x, map_y, delta_dist_x, delta_dist_y, &step_x,
			&step_y, &side_dist_x, &side_dist_y);
		/* Perform DDA (Digital Differential Analysis) algorithm */
		perform_dda(&side_dist_x, &side_dist_y, delta_dist_x, delta_dist_y,
			&map_x, &map_y, step_x, step_y, &side, world_map, width, height);
		/* Calculate distance to the point of impact and line height */
		calculate_distance_and_height(map_x, map_y, step_x, step_y, ray_dir_x,
			ray_dir_y, player->pos_x, player->pos_y, side, &perp_wall_dist,
			&line_height);
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
