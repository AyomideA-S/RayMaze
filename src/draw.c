/**
 * @file draw.c
 * @author Ayomide Ayodele-Soyebo (midesuperbest@gmail.com)
 * @brief Source file for drawing functions in the RayMaze raycasting game.
 * @version 0.1
 * @date 04-10-2026
 *
 * @copyright Copyright (c) 2026
 *
 */

#include "draw.h"

/* Global color buffer definition */
uint32_t color_buffer[SCREEN_WIDTH * SCREEN_HEIGHT];

/** @brief Clears the color buffer with a specified color.
 *
 * @param color The color to clear the buffer with.
 */
void clear_color_buffer(uint32_t color)
{
	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
		color_buffer[i] = color;
	}
}

/** @brief Draws a pixel at the specified coordinates with the given color.
 *
 * @param x The x-coordinate of the pixel to draw.
 * @param y The y-coordinate of the pixel to draw.
 * @param color The color of the pixel to draw.
 */
void draw_pixel(int x, int y, uint32_t color)
{
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
		color_buffer[y * SCREEN_WIDTH + x] = color;
	}
}

/** @brief Renders the color buffer to the screen using the provided SDL
 * renderer and texture.
 *
 * @param renderer The SDL_Renderer to use for rendering.
 * @param texture The SDL_Texture to update with the color buffer data.
 */
void render_color_buffer(SDL_Renderer *renderer, SDL_Texture *texture)
{
	if (SDL_UpdateTexture(texture, NULL, color_buffer,
			      SCREEN_WIDTH * sizeof(uint32_t)) != 0) {
		fprintf(stderr, "Error updating texture: %s\n", SDL_GetError());
	}
	if (SDL_RenderCopy(renderer, texture, NULL, NULL) != 0) {
		fprintf(stderr, "Error copying texture to renderer: %s\n",
			SDL_GetError());
	}
}

/** @brief Draws a rectangle at the specified coordinates with the given width,
 * height, and color.
 * @param x The x-coordinate of the top-left corner of the rectangle.
 * @param y The y-coordinate of the top-left corner of the rectangle.
 * @param width The width of the rectangle.
 * @param height The height of the rectangle.
 * @param color The color of the rectangle.
 */
void draw_rect(int x, int y, int width, int height, uint32_t color)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			draw_pixel(x + j, y + i, color);
		}
	}
}