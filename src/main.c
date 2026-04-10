/**
 * @file main.c
 * @author Ayomide Ayodele-Soyebo (midesuperbest@gmail.com)
 * @brief Main entry point for the RayMaze raycasting game.
 * @version 0.1
 * @date 04-10-2026
 *
 * @copyright Copyright (c) 2026
 *
 */

#include "main.h"

/**
 * @brief Cleans up SDL resources and exits the program with the specified exit
 * code.
 *
 * @param window The SDL_Window to be destroyed, if it exists.
 * @param exit_code The exit code for the program.
 * @return This function does not return; it exits the program.
 */
void cleanup_and_exit(SDL_Window *window, int exit_code)
{
	if (window != NULL)
		SDL_DestroyWindow(window);
	SDL_Quit();
	exit(exit_code);
}

/**
 * @brief The main function initializes the SDL video subsystem, creates a
 * window, and keeps it open until the user decides to close it. It also handles
 * cleanup before exiting.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	/* Code to make use of argc & argv to avoid unused parameter warnings */
	(void)argc;
	(void)argv;

	/* Initialize SDL Video subsystem */
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n",
		       SDL_GetError());
		return (1);
	}

	/* Initialize SDL Window */
	SDL_Window *window = SDL_CreateWindow(
	    "RayMaze", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	    SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		printf("Window could not be created! SDL_Error: %s\n",
		       SDL_GetError());
		cleanup_and_exit(window, 1);
	}

	/* Initialize SDL Renderer */
	SDL_Renderer *renderer =
	    SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		printf("Renderer could not be created! SDL_Error: %s\n",
		       SDL_GetError());
		cleanup_and_exit(window, 1);
	}

	/* Initialize SDL Texture */
	SDL_Texture *texture = SDL_CreateTexture(
	    renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING,
	    SCREEN_WIDTH, SCREEN_HEIGHT);
	if (texture == NULL) {
		printf("Texture could not be created! SDL_Error: %s\n",
		       SDL_GetError());
		cleanup_and_exit(window, 1);
	}

	/* Main event loop to keep the window open until the user closes it */
	SDL_Event e;
	bool quit = false;
	while (quit == false) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				quit = true;
		}
	}

	/* Clean up renderer */
	SDL_DestroyRenderer(renderer);
	/* Destroy the texture */
	SDL_DestroyTexture(texture);
	/* Destroy the window */
	SDL_DestroyWindow(window);
	/* Clean up and exit */
	SDL_Quit();
	return (0);
}