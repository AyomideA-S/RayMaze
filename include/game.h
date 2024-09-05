#ifndef GAME_H_
#define GAME_H_

#include <SDL2/SDL.h>

/* Map dimensions */
#define MAP_WIDTH 24
#define MAP_HEIGHT 24

/* Function to get the default map */
int (*get_default_map())[MAP_WIDTH];

/* Function to allocate memory for a 2D map */
int **allocate_map(int width, int height);
/* Function to free memory allocated for a 2D map */
void free_map(int **map, int height);
/* Function to get the map from a file */
int **get_map_from_file(const char *filename, int *width, int *height);

/* Game loop function */
void game_loop(SDL_Renderer *renderer);

#endif /* GAME_H_ */
