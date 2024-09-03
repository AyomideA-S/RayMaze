#include "main.h"
#include "raycaster.h"

void render_scene(SDL_Renderer *renderer)
{
    /* Set the colour to draw */
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    /* Draw the vertical stripe for the current column */
    SDL_RenderDrawPoint(renderer, 100, 100);
}
