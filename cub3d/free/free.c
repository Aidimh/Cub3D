/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:08:41 by moel-aid          #+#    #+#             */
/*   Updated: 2025/11/17 17:08:44 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

void	free_colors(char *red, char *green, char *blue)
{
	free(red);
	free(blue);
	free(green);
}

int	safe_free(char *line)
{
	get_next_line(-1);
	if (line)
		free(line);
	return (ERROR);
}

void	free_array(char **double_array)
{
	int	i;

	if (!double_array)
		return ;
	i = 0;
	while (double_array[i])
	{
		free(double_array[i]);
		double_array[i] = NULL;
		i++;
	}
	free(double_array);
}

void	free_rgb_array(char **rgb_array)
{
	int	i;

	if (!rgb_array)
		return ;
	i = 0;
	while (rgb_array[i])
	{
		free(rgb_array[i]);
		rgb_array[i] = NULL;
		i++;
	}
	free(rgb_array);
}

int	free_all_data(t_game *game)
{
	if (!game)
		return (ERROR);
	if (game->config.map.map_grid)
	{
		free_array(game->config.map.map_grid);
		game->config.map.map_grid = NULL;
	}
	if (game->config.map.flood_fill_copy)
	{
		free_array(game->config.map.flood_fill_copy);
		game->config.map.flood_fill_copy = NULL;
	}
	free(game->config.north);
	free(game->config.south);
	free(game->config.west);
	free(game->config.east);
	free(game->data);
	game->config.north = NULL;
	game->config.south = NULL;
	game->config.west = NULL;
	game->config.east = NULL;
	return (SUCCESS);
}
