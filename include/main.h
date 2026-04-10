/**
 * @file main.h
 * @author Ayomide Ayodele-Soyebo (midesuperbest@gmail.com)
 * @brief Header file for the main entry point of the RayMaze raycasting game.
 * @version 0.1
 * @date 04-10-2026
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef MAIN_H_
#define MAIN_H_

/**
 * SDL_MAIN_HANDLED - This is for when not using the standard main function:
 * int main(int argc, char *argv[])
 */
#define SDL_MAIN_HANDLED

/* Include standard libraries */
#include <stdbool.h> // For boolean type and values
#include <stdio.h>

/* Include SDL2 library */
#include <SDL2/SDL.h>

/* Screen dimensions */
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#endif /* MAIN_H_ */