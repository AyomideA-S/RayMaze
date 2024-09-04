#ifndef GAME_H_
#define GAME_H_

#include <SDL2/SDL.h>

/* Map dimensions */
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

/* Simple map for testing purposes */
extern int default_map[MAP_HEIGHT][MAP_WIDTH];

/* Game loop function */
void game_loop(SDL_Renderer *renderer);

#endif /* GAME_H_ */
