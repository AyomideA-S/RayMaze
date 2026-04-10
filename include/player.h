/**
 * @file player.h
 * @author Ayomide Ayodele-Soyebo (midesuperbest@gmail.com)
 * @brief Header file for player-related structures and functions in the RayMaze
 * @version 0.1
 * @date 04-10-2026
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef PLAYER_H
#define PLAYER_H

/**
 * General player structure definition
 *
 * The player structure represents the player's position, direction vector,
 * camera plane, and movement/rotation speeds in the game world.
 */
typedef struct player {
	double pos_x;	/**< Player's absolute x-coordinate in the game world */
	double pos_y;	/**< Player's absolute y-coordinate in the game world */
	double dir_x;	/**< x-component of the player's direction vector */
	double dir_y;	/**< y-component of the player's direction vector */
	double plane_x; /**< x-component of the 2D camera plane */
	double plane_y; /**< y-component of the 2D camera plane */
	double move_speed; /**< Player's forward/backward movement speed */
	double turn_speed; /**< Speed at which the player rotates */
} Player;

/*Global player instance representing the player's state in the game */
extern Player player;

/* Define function prototypes for player-related functions */

void init_player(void);

#endif /* PLAYER_H */