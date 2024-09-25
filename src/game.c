#include "main.h"
#include "game.h"
#include "raycaster.h"

/**
 * log_player_state - Log the player's state to a specified destination
 *
 * @player: Pointer to the player structure
 * @destination: The logging destination (file, stdout, stderr)
 * @width: The width of the world map
 * @height: The height of the world map
 */
void log_player_state(Player *player, int width, int height,
					  log_destination destination)
{
	FILE *log_file = NULL;

	switch (destination)
	{
	case LOG_TO_FILE:
		log_file = fopen("player.log", "a");
		if (log_file == NULL)
		{
			fprintf(stderr, "Error opening log file\n");
			return;
		}
		break;
	case LOG_TO_STDOUT:
		log_file = stdout;
		break;
	case LOG_TO_STDERR:
		log_file = stderr;
		break;
	}

	fprintf(log_file,
			"Position: (%f, %f), Direction: (%f, %f), Plane: (%f, %f),\n"
			"Speed: %f, Rotation Speed: %f, Pitch: %f\n",
			player->pos_x, player->pos_y,
			player->dir_x, player->dir_y,
			player->plane_x, player->plane_y,
			player->move_speed, player->rot_speed, player->pitch);
	fprintf(log_file, "Dimensions: %d, %d\n", width, height);

	if (destination == LOG_TO_FILE)
	{
		fclose(log_file);
	}
}

/**
 * handle_events - Handle SDL events
 *
 * @quit: Pointer to the quit flag
 * @key_states: Array to track key states
 */
void handle_events(SDL_Event *event, int *quit, int key_states[])
{
	/* Handle events */
	while (SDL_PollEvent(event) != 0)
	{
		/* Handle quit event */
		if (event->type == SDL_QUIT)
			*quit = 1;
		/* Update key states */
		if (event->type == SDL_KEYDOWN)
			key_states[event->key.keysym.scancode] = 1;
		if (event->type == SDL_KEYUP)
			key_states[event->key.keysym.scancode] = 0;
	}
}

/**
 * update_game_state - Update the game state
 *
 * @player: Pointer to the player structure
 * @key_states: Array to track key states
 * @world_map: 2D array representing the world map
 */
void update_game_state(Player *player, int key_states[], int **world_map)
{
	/* Handle key states for player forward movement */
	if (key_states[SDL_SCANCODE_W])
		move_forward(player, world_map);
	/* Handle key states for player backward movement */
	if (key_states[SDL_SCANCODE_S])
		move_backward(player, world_map);
	/* Handle key states for player strafing left */
	if (key_states[SDL_SCANCODE_A])
		rotate_left(player);
	/* Handle key states for player strafing right */
	if (key_states[SDL_SCANCODE_D])
		rotate_right(player);
	update_pitch(player, key_states);
}

/**
 * game_loop - Main game loop
 *
 * @renderer: The renderer to use
 */
void game_loop(SDL_Renderer *renderer)
{
	/* Quit flag */
	int quit = 0;
	/* Array to track key states */
	int key_states[SDL_NUM_SCANCODES] = {0};
	/* SDL event */
	SDL_Event event;
	int width = 0, height = 0;

	/* Set up player's initial state */
	/* Initial position, direction, plane, speed, rotation speed, pitch */
	Player player = {1.0, 1.0, -1.0, 0.0, 0.0, 0.66, 0.05, 0.03, 0.0};
	/* World map */
	/* check if level map exists else asign default map */
	int **world_map = get_map_from_file("assets/maps/level0.map",
										&width, &height);

	while (!quit)
	{
		/* Handle events */
		handle_events(&event, &quit, key_states);
		/* Update game state */
		update_game_state(&player, key_states, world_map);

		/* Log player's state */
		log_player_state(&player, width, height, LOG_TO_FILE);

		/* Clear screen */
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);
		/* Perform raycasting and render the scene */
		render_scene(renderer, &player, world_map, width, height);
		/* Render the minimap */
		render_minimap(renderer, &player, world_map, width, height, 10,
					   TRUE);
		/* Update screen */
		SDL_RenderPresent(renderer);
		/* Delay to limit frame rate */
		SDL_Delay(16); /* Approx. 60 frames per second */
	}
}
