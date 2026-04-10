/**
 * @file map.h
 * @author Ayomide Ayodele-Soyebo (midesuperbest@gmail.com)
 * @brief Header file for the game map in RayMaze.
 * @version 0.1
 * @date 04-10-2026
 *
 * @copyright Copyright (c) 2026
 *
 */

#ifndef MAP_H
#define MAP_H

/* Define the dimensions of the game map */
#define MAP_WIDTH 24  /**< Width of the game map in grid units */
#define MAP_HEIGHT 24 /**< Height of the game map in grid units */

/* 2D array representing the game map */
extern int worldMap[MAP_WIDTH][MAP_HEIGHT];

#endif /* MAP_H */