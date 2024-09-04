#include "game.h"
#include "raycaster.h"

/**
 * game_loop - Main game loop
 *
 * @renderer: The renderer to use
 */
void game_loop(SDL_Renderer *renderer)
{
	int quit = 0;

	/* Set up player's initial state */
	/* Initial position, direction, plane, speed, rotation speed, pitch */
	Player player = {22.0, 12.0, -1.0, 0.0, 0.0, 0.66, 0.05, 0.03, 0.0};

	while (!quit)
	{
		/* Clear screen */
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		/* Perform raycasting and render the scene */
		render_scene(renderer, &player);

		/* Update screen */
		SDL_RenderPresent(renderer);

		/* Delay to limit frame rate */
		SDL_Delay(16); /* Approx. 60 frames per second */
	}
}
