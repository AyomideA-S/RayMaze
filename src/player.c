/**
 * @file player.c
 * @author Ayomide Ayodele-Soyebo (midesuperbest@gmail.com)
 * @brief Source file for player-related structures and functions in RayMaze
 * @version 0.1
 * @date 04-10-2026
 *
 * @copyright Copyright (c) 2026
 *
 */

#include "player.h"

/* Instantiate the global player variable */
Player player; /**< Global player instance */

/**
 * @brief Initializes the player's starting position, direction, camera plane,
 * and movement speeds.
 */
void init_player(void)
{
	/* Set initial position */
	player.pos_x = 22.0;
	player.pos_y = 12.0;

	/* Set initial direction vector */
	player.dir_x = 0.0;
	player.dir_y = -1.0;

	/* Set the camera plane perpendicular to the direction */
	player.plane_x = 0.66;
	player.plane_y = 0.0;

	/* Set movement and rotation speeds */
	player.move_speed = 0.05;
	player.turn_speed = 0.05;
}