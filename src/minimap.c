#include "main.h"
#include "game.h"
#include "raycaster.h"

/**
 * render_map - Render the world map
 *
 * @renderer: The renderer to use
 * @world_map: The 2D array representing the world map
 * @width: The width of the world map
 * @height: The height of the world map
 */
void render_map(SDL_Renderer *renderer, int **world_map, int width, int height)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (world_map[y][x] > 0)
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
			else
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

			SDL_Rect cell = {x * MINIMAP_SCALE, y * MINIMAP_SCALE,
							 MINIMAP_SCALE, MINIMAP_SCALE};
			SDL_RenderFillRect(renderer, &cell);
		}
	}
}

/**
 * render_player - Render the player as a dot on the minimap
 *
 * @renderer: The renderer to use
 * @player: The player structure
 */
void render_player(SDL_Renderer *renderer, Player *player)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_Rect player_rect = {(int)(player->pos_x * MINIMAP_SCALE) - 2,
							(int)(player->pos_y * MINIMAP_SCALE) - 2,
							4, 4};
	SDL_RenderFillRect(renderer, &player_rect);
}

/**
 * render_rays - Render rays showing the player's POV
 *
 * @renderer: The renderer to use
 * @player: The player structure
 * @world_map: The 2D array representing the world map
 * @width: The width of the world map
 * @height: The height of the world map
 * @ray_length: The length of the rays
 * @allow_ray_pass_through_walls: Whether rays should pass through walls
 */
void render_rays(SDL_Renderer *renderer, Player *player, int **world_map,
				 int width, int height, double ray_length,
				 int allow_ray_pass_through_walls)
{
	for (int x = 0; x < SCREEN_WIDTH; x += 10) /* Adjust step for fewer rays */
	{
		double ray_dir_x = 0, ray_dir_y = 0;
		int map_x = 0, map_y = 0;
		double delta_dist_x = 0, delta_dist_y = 0;
		double side_dist_x = 0, side_dist_y = 0;
		int step_x = 0, step_y = 0;
		int side = 0;
		double perp_wall_dist = ray_length;
		/* Calculate ray direction and map position */
		calculate_ray_direction(player, x, &ray_dir_x, &ray_dir_y,
								&delta_dist_x, &delta_dist_y, &map_x, &map_y);
		/* Determine step direction and initial side distance values */
		calculate_step_and_side_dist(ray_dir_x, ray_dir_y, player->pos_x,
									 player->pos_y, map_x, map_y, delta_dist_x,
									 delta_dist_y, &step_x, &step_y,
									 &side_dist_x, &side_dist_y);

		if (!allow_ray_pass_through_walls)
		{
			/* Perform DDA (Digital Differential Analysis) algorithm */
			perform_dda(&side_dist_x, &side_dist_y, delta_dist_x, delta_dist_y,
						&map_x, &map_y, step_x, step_y, &side, world_map, width, height);
			/* Calculate perpendicular wall distance */
			if (side == 0)
				perp_wall_dist = (map_x - player->pos_x + (1 - step_x) / 2) / ray_dir_x;
			else
				perp_wall_dist = (map_y - player->pos_y + (1 - step_y) / 2) / ray_dir_y;
		}
		/* Calculate the end position of the ray */
		int ray_end_x = (int)(player->pos_x + ray_dir_x * perp_wall_dist);
		int ray_end_y = (int)(player->pos_y + ray_dir_y * perp_wall_dist);
		/* Draw the ray */
		SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(renderer,
						   (int)(player->pos_x * MINIMAP_SCALE),
						   (int)(player->pos_y * MINIMAP_SCALE),
						   ray_end_x * MINIMAP_SCALE,
						   ray_end_y * MINIMAP_SCALE);
	}
}

/**
 * render_minimap - Render a minimap with the player as a dot and rays showing
 * the player's POV
 *
 * @renderer: The renderer to use
 * @player: The player structure
 * @world_map: The 2D array representing the world map
 * @width: The width of the world map
 * @height: The height of the world map
 * @ray_length: The length of the rays
 * @allow_ray_pass_through_walls: Whether rays should pass through walls
 */
void render_minimap(SDL_Renderer *renderer, Player *player, int **world_map,
					int width, int height, double ray_length,
					int allow_ray_pass_through_walls)
{
	/* Render the map */
	render_map(renderer, world_map, width, height);
	/* Render the player */
	render_player(renderer, player);
	/* Render the rays */
	render_rays(renderer, player, world_map, width, height, ray_length,
				allow_ray_pass_through_walls);
}
