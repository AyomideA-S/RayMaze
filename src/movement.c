#include "main.h"
#include "game.h"

/**
 * move_forward - Move the player forward
 *
 * @player: Pointer to the player structure
 * @world_map: 2D array representing the world map
 */
void move_forward(Player *player, int **world_map)
{
	if (world_map[(int)(player->pos_x + player->dir_x * player->move_speed)][
		(int)player->pos_y] == 0)
		player->pos_x += player->dir_x * player->move_speed;
	if (world_map[(int)player->pos_x][(int)(player->pos_y + player->dir_y *
		player->move_speed)] == 0)
		player->pos_y += player->dir_y * player->move_speed;
}

/**
 * move_backward - Move the player backward
 *
 * @player: Pointer to the player structure
 * @world_map: 2D array representing the world map
 */
void move_backward(Player *player, int **world_map)
{
	if (world_map[(int)(player->pos_x - player->dir_x * player->move_speed)][
		(int)player->pos_y] == 0)
		player->pos_x -= player->dir_x * player->move_speed;
	if (world_map[(int)player->pos_x][(int)(player->pos_y - player->dir_y *
		player->move_speed)] == 0)
		player->pos_y -= player->dir_y * player->move_speed;
}

/**
 * rotate_left - Rotate the player to the left
 *
 * @player: Pointer to the player structure
 */
void rotate_left(Player *player)
{
	double old_dir_x = player->dir_x;
	double old_plane_x = player->plane_x;
	/* Rotate player direction and camera plane */
	player->dir_x = player->dir_x * cos(player->rot_speed) - player->dir_y *
										sin(player->rot_speed);
	player->dir_y = old_dir_x * sin(player->rot_speed) + player->dir_y *
									cos(player->rot_speed);
	player->plane_x = player->plane_x * cos(player->rot_speed) -
					  player->plane_y * sin(player->rot_speed);
	player->plane_y = old_plane_x * sin(player->rot_speed) +
					  player->plane_y * cos(player->rot_speed);
}

/**
 * rotate_right - Rotate the player to the right
 *
 * @player: Pointer to the player structure
 */
void rotate_right(Player *player)
{
	double old_dir_x = player->dir_x;
	double old_plane_x = player->plane_x;
	/* Rotate player direction */
	player->dir_x = player->dir_x * cos(-player->rot_speed) - player->dir_y *
										sin(-player->rot_speed);
	player->dir_y = old_dir_x * sin(-player->rot_speed) + player->dir_y *
									cos(-player->rot_speed);
	player->plane_x = player->plane_x * cos(-player->rot_speed) -
					  player->plane_y * sin(-player->rot_speed);
	player->plane_y = old_plane_x * sin(-player->rot_speed) +
					  player->plane_y * cos(-player->rot_speed);
}

/**
 * update_pitch - Update the player's pitch
 *
 * @player: Pointer to the player structure
 * @key_states: Array to track key states
 */
void update_pitch(Player *player, int key_states[])
{
	/* Handle key states for player looking up or down */
	if (key_states[SDL_SCANCODE_UP])
		player->pitch += 0.05;
	if (key_states[SDL_SCANCODE_DOWN])
		player->pitch -= 0.05;
	/* Clamp the pitch to avoid excessive looking up or down */
	if (player->pitch > 1.0)
		player->pitch = 1.0;
	if (player->pitch < -1.0)
		player->pitch = -1.0;
}
