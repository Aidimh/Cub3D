/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:41:09 by moel-aid          #+#    #+#             */
/*   Updated: 2025/11/17 15:41:12 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

int	if_space_is_walled(char **map, size_t height, size_t width)
{
	size_t	i;
	size_t	j;
	size_t	index_array[2];

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == ' ')
			{
				index_array[0] = i;
				index_array[1] = j;
				if (char_is_wall(map, index_array, height, width))
					return (ERROR);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	is_identifier(char c, t_game *game)
{
	if (c == 'N')
		game->config.seen_id[0]++;
	else if (c == 'S')
		game->config.seen_id[1]++;
	else if (c == 'W')
		game->config.seen_id[2]++;
	else if (c == 'E')
		game->config.seen_id[3]++;
	else if (c == 'C')
		game->config.seen_id[4]++;
	else if (c == 'F')
		game->config.seen_id[5]++;
	else
		return (ERROR);
	return (SUCCESS);
}

int	line_is_walled(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ' && line[i] != '\t')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	all_lines_are_walled(size_t height, char **map_grid)
{
	int		j;
	int		i;
	int		end;

	if (!map_grid || !map_grid[0]
		|| line_is_walled(map_grid[0]) != SUCCESS
		|| line_is_walled(map_grid[height - 1]) != SUCCESS)
		return (map_is_not_fully_walled());
	j = 0;
	while (map_grid[j])
	{
		i = 0;
		while (map_grid[j][i] == ' ' || map_grid[j][i] == '\t')
			i++;
		if (map_grid[j][i] != '1' && map_grid[j][i] != '\0')
			return (line_isnt_start_walled(j));
		end = ft_strlen(map_grid[j]) - 1;
		while (end >= 0
			&& (map_grid[j][end] == ' ' || map_grid[j][end] == '\t'))
			end--;
		if (end >= 0 && map_grid[j][end] != '1')
			return (line_isnt_end_walled(j));
		j++;
	}
	return (SUCCESS);
}

int	map_is_walled(char **map, size_t height, size_t width)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == '0'
				&& (map[i + 1][j] == 'v' || map[i - 1][j] == 'v'
					|| map[i][j + 1] == 'v' || map[i][j - 1] == 'v'))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
