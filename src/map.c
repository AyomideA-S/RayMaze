#include "main.h"
#include "game.h"

/**
 * get_default_map - Get the default map
 *
 * This function returns a pointer to the default map used in the game.
 *
 * Return: A pointer to a 2D array representing the default map.
 */
int (*get_default_map())[MAP_WIDTH]
{
	/* Simple map for testing purposes */
	static int default_map[MAP_HEIGHT][MAP_WIDTH] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
	return (default_map);
}

/**
 * allocate_map - Allocate memory for a 2D map
 *
 * @width: The width of the map
 * @height: The height of the map
 *
 * Return: A pointer to the allocated map
 */
int **allocate_map(int width, int height)
{
	/* Allocate memory for the map */
	int **map = (int **)malloc(height * sizeof(int *));

	/* Check if memory allocation was successful */
	if (!map)
		return (NULL);

	/* Allocate memory for each row of the map */
	for (int i = 0; i < height; i++)
	{
		map[i] = (int *)malloc(width * sizeof(int));
		/* Check if memory allocation was successful */
		if (!map[i])
		{
			/* Free memory allocated for previous rows */
			for (int j = 0; j < i; j++)
				free(map[j]);
			/* Free memory allocated for the map */
			free(map);

			return (NULL);
		}
	}

	return (map);
}

/**
 * free_map - Free memory allocated for a 2D map
 *
 * @map: The map to free
 * @height: The height of the map
 */
void free_map(int **map, int height)
{
	/* Free memory allocated for each row of the map */
	for (int i = 0; i < height; i++)
		free(map[i]);
	/* Free memory allocated for the map */
	free(map);
}

/**
 * convert_to_int_ptr - Convert a 2D array to int**
 *
 * @array: The 2D array to convert
 * @width: The width of the array
 * @height: The height of the array
 *
 * Return: A pointer to a 2D array of int**
 */
int **convert_to_int_ptr(int array[][MAP_WIDTH], int width, int height)
{
	int **map = allocate_map(width, height);
	/* Check if memory allocation was successful */
	if (!map)
		return (NULL);
	/* Copy the contents of the array to the map */
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			map[i][j] = array[i][j];
		}
	}
	return (map);
}

/**
 * get_map_from_file - Get the map from a file
 *
 * @filename: The name of the file to read
 * @width: A pointer to store the width of the map
 * @height: A pointer to store the height of the map
 *
 * Return: A pointer to a 2D array representing the map
 */
int **get_map_from_file(const char *filename, int *width, int *height)
{
	FILE *file = fopen(filename, "r");
	/* Check if file was opened successfully */
	if (!file)
	{
		perror("Failed to open file");
		/* Return the default map if the file does not exist */
		*width = (int)MAP_WIDTH, *height = (int)MAP_HEIGHT;
		return (convert_to_int_ptr(get_default_map(), MAP_WIDTH, MAP_HEIGHT));
	}
	if (fscanf(file, "%d %d", width, height) != 2)
	{
		perror("Failed to read dimensions");
		fclose(file);
		/* Return the default map if the dimensions are not found */
		*width = (int)MAP_WIDTH, *height = (int)MAP_HEIGHT;
		return (convert_to_int_ptr(get_default_map(), MAP_WIDTH, MAP_HEIGHT));
	}
	int **map = allocate_map(*width, *height);
	/* Check if memory allocation was successful */
	if (!map)
	{
		perror("Failed to allocate memory for map");
		fclose(file);
		/* Return the default map if memory allocation fails */
		*width = (int)MAP_WIDTH, *height = (int)MAP_HEIGHT;
		return (convert_to_int_ptr(get_default_map(), MAP_WIDTH, MAP_HEIGHT));
	}
	/* Read the map data from the file */
	for (int i = 0; i < *height; i++)
	{
		for (int j = 0; j < *width; j++)
		{
			if (fscanf(file, "%d", &map[i][j]) != 1)
			{
				perror("Failed to read map data");
				fclose(file);
				free_map(map, *height);
				/* Return the default map if reading map data fails */
				*width = (int)MAP_WIDTH, *height = (int)MAP_HEIGHT;
				return (convert_to_int_ptr(get_default_map(), MAP_WIDTH,
						MAP_HEIGHT));
			}
		}
	}
	fclose(file);
	return (map);
}
