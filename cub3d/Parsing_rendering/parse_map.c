/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:54:34 by moel-aid          #+#    #+#             */
/*   Updated: 2025/11/17 16:47:59 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	fill_map_grid(t_game *game, char *line)
{
	game->config.map.map_grid[game->player.index] = ft_strdup(line);
	if (!game->config.map.map_grid[game->player.index])
		return (ERROR);
	if (ft_strlen(line) > game->line_length)
		game->line_length = ft_strlen(line);
	return (SUCCESS);
}

int	check_for_ids_existence(t_game *game)
{
	if (!game->config.seen_id[0] || !game->config.seen_id[1]
		|| !game->config.seen_id[2] || !game->config.seen_id[3]
		|| !game->config.seen_id[4] || !game->config.seen_id[5])
		return (map_is_not_last());
	if (!game->config.north)
		return (north_direction_missing());
	if (!game->config.south)
		return (south_direction_missing());
	if (!game->config.west)
		return (west_direction_missing());
	if (!game->config.east)
		return (east_direction_missing());
	if (!game->config.floor_flag)
		return (floor_is_missing());
	if (!game->config.ceiling_flag)
		return (ceiling_is_missing());
	return (SUCCESS);
}

int	process_line(t_game *game, char *line)
{
	if (ft_strlen(line) <= 2)
		return (map_row_is_short());
	if (is_map_line(line) == SUCCESS)
	{
		if (player_is_duplicated(line, game) != SUCCESS)
			return (duplicated_player());
		game->map_exist_flag++;
		if (!game->config.north && !game->config.south
			&& !game->config.east && !game->config.west
			&& !game->config.ceiling_flag && !game->config.floor_flag)
			return (map_is_not_last());
		if (check_for_ids_existence(game) != SUCCESS)
			return (ERROR);
		if (textures_before_map(game) != SUCCESS)
			return (map_is_not_last());
		if (fill_map_grid(game, line) != SUCCESS)
			return (ERROR);
		game->player.index++;
		return (SUCCESS);
	}
	return (get_map_directions_rgb(game, line));
}

int	get_map_copy_demensions(t_game *game, int fd)
{
	char	*line;

	game->line_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strlen(line) > 1 && line[ft_strlen(line) - 2] == '\r')
			line[ft_strlen(line) - 2] = '\0';
		if (line[0] == '\0')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (process_line(game, line) != SUCCESS)
			return (safe_free(line));
		if (is_map_line(line) == SUCCESS)
			game->line_count++;
		free(line);
		line = get_next_line(fd);
	}
	game->config.map.map_grid[game->player.index] = NULL;
	return (SUCCESS);
}

int	parse_map(t_game *game, char *filename)
{
	int	fd;

	game->line_length = 0;
	game->player.index = 0;
	if (check_cub_extension(filename) != SUCCESS)
		return (invalid_extension(filename));
	measure_map(&game->config.map.height, &game->config.map.width, filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (file_not_found(filename));
	if (get_map_copy_demensions(game, fd) != SUCCESS)
	{
		close(fd);
		return (ERROR);
	}
	close(fd);
	if (game->map_exist_flag == 0 || game->map_exist_flag < 3)
		return (map_is_short());
	if (game->config.map.height <= 2 && game->config.map.width <= 2)
		return (ERROR);
	if (validate_map_grid(game) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}
