#include "main.h"
#include "raycaster.h"

/**
 * render_scene - Render the scene using raycasting techniques
 *
 * @renderer: The renderer to use
 */
void render_scene(SDL_Renderer *renderer)
{
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		/* Set the colour to draw */
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		/* Draw the vertical stripe for the current column */
		SDL_RenderDrawLine(renderer, x, 0, x, SCREEN_HEIGHT);
	}
}
