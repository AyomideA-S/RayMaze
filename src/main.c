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
#include "draw.h" // Include draw functions for rendering

/**
 * @brief Prints an error message to the console for a given SDL object and
 * exits the program.
 *
 * @param object_name The name of the SDL object that failed to initialize
 * (e.g., "Window", "Renderer", "Texture").
 * @param window The SDL_Window to destroy, or NULL if not initialized.
 * @param renderer The SDL_Renderer to destroy, or NULL if not initialized.
 * @param texture The SDL_Texture to destroy, or NULL if not initialized.
 * @param status The exit code to return from the program (1 for failure).
 * @return The provided exit code after cleanup.
 */
int print_error_and_exit(const char *object_name, SDL_Window *window,
			 SDL_Renderer *renderer, SDL_Texture *texture,
			 int status)
{
	printf("%s could not be created! SDL_Error: %s\n", object_name,
	       SDL_GetError());
	return (cleanup_and_exit(window, renderer, texture, status));
}

/**
 * @brief Cleans up SDL resources and exits the program with the specified
 * status code.
 *
 * @param window The SDL_Window to destroy, or NULL if not initialized.
 * @param renderer The SDL_Renderer to destroy, or NULL if not initialized.
 * @param texture The SDL_Texture to destroy, or NULL if not initialized.
 * @param status The exit code to return from the program (0 for success, 1 for
 * failure).
 * @return The provided exit code after cleanup.
 */
int cleanup_and_exit(SDL_Window *window, SDL_Renderer *renderer,
		     SDL_Texture *texture, int status)
{
	/* Clean up SDL resources if they were initialized */
	/* Destroy the texture */
	if (texture != NULL)
		SDL_DestroyTexture(texture);
	/* Destroy the renderer and window */
	if (renderer != NULL)
		SDL_DestroyRenderer(renderer);
	/* Destroy the window */
	if (window != NULL)
		SDL_DestroyWindow(window);
	/* Quit SDL subsystems */
	SDL_Quit();
	return (status);
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
	if (window == NULL)
		return (print_error_and_exit("Window", window, NULL, NULL, 1));

	/* Initialize SDL Renderer */
	SDL_Renderer *renderer =
	    SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
		return (print_error_and_exit("Renderer", window, renderer, NULL,
					     1));

	/* Initialize SDL Texture */
	SDL_Texture *texture = SDL_CreateTexture(
	    renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING,
	    SCREEN_WIDTH, SCREEN_HEIGHT);
	if (texture == NULL)
		return (print_error_and_exit("Texture", window, renderer,
					     texture, 1));

	/* Main event loop to keep the window open until the user closes it */
	SDL_Event e;
	bool quit = false;
	while (quit == false) {
		clear_color_buffer(0xFF000000);
		draw_rect(50, 50, 100, 100,
			  0xFFFF0000); // Example: Draw a red rectangle
		render_color_buffer(renderer, texture);
		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				quit = true;
		}
	}

	return (cleanup_and_exit(window, renderer, texture, 0));
}