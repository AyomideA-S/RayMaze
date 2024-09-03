#include "main.h"
#include "game.h"

/**
 * main - The main entry point of the program.
 *
 * This function initializes SDL, creates a window and renderer, starts the
 * game loop, and cleans up resources before exiting.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return (1);
	}

	SDL_Window * window = SDL_CreateWindow("RayMaze", SDL_WINDOWPOS_UNDEFINED,
										  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
										  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1,
												SDL_RENDERER_ACCELERATED);

	if (renderer == NULL)
	{
		printf("Renderer could not be created! SDL_Error: %s\n",
			   SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return (1);
	}

	game_loop(renderer);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return (0);
}
