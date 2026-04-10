/**
 * @file draw.h
 * @author Ayomide Ayodele-Soyebo (midesuperbest@gmail.com)
 * @brief Header file for drawing functions in the RayMaze raycasting game.
 * @version 0.1
 * @date 04-10-2026
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef DRAW_H
#define DRAW_H

#include "main.h"   // Include main header for screen dimensions and SDL types
#include <stdint.h> // For uint32_t type

/* Global color pixel buffer definition*/
extern uint32_t color_buffer[SCREEN_WIDTH * SCREEN_HEIGHT];

/* Function prototypes for drawing functions */

void clear_color_buffer(uint32_t color);
void draw_pixel(int x, int y, uint32_t color);
void render_color_buffer(SDL_Renderer *renderer, SDL_Texture *texture);
void draw_rect(int x, int y, int width, int height, uint32_t color);

#endif /* DRAW_H */