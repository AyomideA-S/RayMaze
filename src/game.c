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
	SDL_Event event;

	while (!quit)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
				quit = 1;
			/* Handle other events (keyboard, mouse, etc.) here */
		}

		/* Clear screen */
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		/* Perform raycasting and render the scene */
		render_scene(renderer);

		/* Update screen */
		SDL_RenderPresent(renderer);
	}
}
