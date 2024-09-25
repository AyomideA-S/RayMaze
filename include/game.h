#ifndef GAME_H_
#define GAME_H_

#include <SDL2/SDL.h>

/* Map dimensions */
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

/**
 * struct player - Player structure
 *
 * @pos_x: Player's x position
 * @pos_y: Player's y position
 * @dir_x: Direction vector x
 * @dir_y: Direction vector y
 * @plane_x: Camera plane x
 * @plane_y: Camera plane y
 * @move_speed: Player's movement speed
 * @rot_speed: Player's rotation speed
 * @pitch: Vertical look angle
 */
typedef struct player
{
	double pos_x;
	double pos_y;
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;
	double move_speed;
	double rot_speed;
	double pitch;
} Player;

/**
 * enum log_destination - Log destination
 *
 * @LOG_TO_FILE: Log to file
 * @LOG_TO_STDOUT: Log to standard output
 * @LOG_TO_STDERR: Log to standard error
 */
typedef enum log_destination
{
	LOG_TO_FILE,
	LOG_TO_STDOUT,
	LOG_TO_STDERR
} log_destination;

/* Function to get the default map */
int (*get_default_map())[MAP_WIDTH];

/* Function to allocate memory for a 2D map */
int **allocate_map(int width, int height);
/* Function to free memory allocated for a 2D map */
void free_map(int **map, int height);
/* Function to get the map from a file */
int **get_map_from_file(const char *filename, int *width, int *height);

/* Function to move the player forward */
void move_forward(Player *player, int **world_map);
/* Function to move the player backward */
void move_backward(Player *player, int **world_map);
/* Function to rotate the player to the left */
void rotate_left(Player *player);
/* Function to rotate the player to the right */
void rotate_right(Player *player);
/* Function to update the player's pitch */
void update_pitch(Player *player, int key_states[]);

/* Function to handle SDL events */
void handle_events(SDL_Event *event, int *quit, int key_states[]);

/* Function to update the game state */
void update_game_state(Player *player, int key_states[], int **world_map);

/* Function to log the player's state */
void log_player_state(Player *player, int width, int height,
					  log_destination destination);

/* Game loop function */
void game_loop(SDL_Renderer *renderer);

#endif /* GAME_H_ */
