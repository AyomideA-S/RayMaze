#ifndef MAIN_H_
#define MAIN_H_

/* Boolean values */
#define FALSE 0
#define TRUE 1

/**
 * SDL_MAIN_HANDLED - This is for when not using the standard main function:
 * int main(int argc, char *argv[])
 */
#define SDL_MAIN_HANDLED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void game_loop(SDL_Renderer *renderer);

#endif /* MAIN_H_ */
