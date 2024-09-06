#ifndef RAYCASTING_H_
#define RAYCASTING_H_

#include <SDL2/SDL.h>

/* Function to calculate the ray direction and map position */
void calculate_ray_direction(Player * player, int x, double *ray_dir_x,
							 double *ray_dir_y, double *delta_dist_x,
							 double *delta_dist_y, int *map_x, int *map_y);
/* Function to calculate the step and side distance */
void calculate_step_and_side_dist(double ray_dir_x, double ray_dir_y,
								  double player_pos_x, double player_pos_y,
								  int map_x, int map_y, double delta_dist_x,
								  double delta_dist_y, int *step_x,
								  int *step_y, double *side_dist_x,
								  double *side_dist_y);
/* Function to calculate the distance and height of the wall hit by the ray */
void calculate_distance_and_height(int map_x, int map_y, int step_x,
								   int step_y, double ray_dir_x,
								   double ray_dir_y, double player_pos_x,
								   double player_pos_y, int side,
								   double *perp_wall_dist, int *line_height);

/* Function to perform DDA algorithm */
void perform_dda(double *side_dist_x, double *side_dist_y, double delta_dist_x,
				 double delta_dist_y, int *map_x, int *map_y, int step_x,
				 int step_y, int *side, int **map, int *hit);

/* Function to draw a vertical line on the screen */
void draw_vertical_line(SDL_Renderer *renderer, int x, int draw_start,
						int draw_end, int side);

/* Function to render the scene using raycasting techniques */
void render_scene(SDL_Renderer *renderer, Player *player, int **world_map);

#endif /* RAYCASTING_H_ */
