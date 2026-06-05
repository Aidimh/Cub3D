/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:39:12 by moel-aid          #+#    #+#             */
/*   Updated: 2025/11/17 15:39:15 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

bool	char_is_wall(char **map, size_t *index, size_t height, size_t width)
{
	if (index[0] > 0 && is_walkable(map[index[0] - 1][index[1]]))
		return (true);
	if (index[0] < height - 1 && is_walkable(map[index[0] + 1][index[1]]))
		return (true);
	if (index[1] > 0 && is_walkable(map[index[0]][index[1] - 1]))
		return (true);
	if (index[1] < width - 1 && is_walkable(map[index[0]][index[1] + 1]))
		return (true);
	return (false);
}

int	player_is_duplicated(char *line, t_game *game)
{
	int	i;

	i = 0;
	if (!line)
		return (ERROR);
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
			game->player_seen++;
		if (game->player_seen > 1)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	if (!line || !(*line))
		return (ERROR);
	while (line[i])
	{
		if (line[i] != 'N' && line[i] != 'S' && line[i] != '1'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != '0'
			&& line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

void	mark_border_spaces(char **map, int height, int width)
{
	int	i;
	int	x;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		x = 0;
		while (x < width && map[i][x] == ' ')
		{
			map[i][x] = 'v';
			x++;
		}
		x = width - 1;
		while (x >= 0 && map[i][x] == ' ')
		{
			map[i][x] = 'v';
			x--;
		}
		i++;
	}
}

int	validate_map_grid(t_game *game)
{
	int	height;

	height = game->config.map.height;
	if (all_lines_are_walled(
			game->config.map.height, game->config.map.map_grid) != SUCCESS)
		return (ERROR);
	if (game->player_seen == 0)
		return (player_not_found());
	if (validate_texture_paths(&game->config) != SUCCESS)
		return (ERROR);
	if (pad_map(game) != SUCCESS)
		return (ERROR);
	mark_border_spaces(game->config.map.flood_fill_copy,
		game->config.map.height, game->config.map.width);
	if (map_is_walled(game->config.map.flood_fill_copy,
			height, game->config.map.width) != SUCCESS)
		return (map_is_not_fully_walled());
	if (if_space_is_walled(game->config.map.flood_fill_copy,
			height, game->config.map.width) != SUCCESS)
		return (space_isnt_walled());
	return (SUCCESS);
}
