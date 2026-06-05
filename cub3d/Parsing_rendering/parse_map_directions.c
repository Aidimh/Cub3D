/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_directions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ouaj <mel-ouaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:38:44 by moel-aid          #+#    #+#             */
/*   Updated: 2025/11/28 10:16:17 by mel-ouaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_texture_path_existence(char *path)
{
	if ((access(path, F_OK)) == -1)
		return (ERROR);
	return (SUCCESS);
}

int	get_north_path(char *line, int index, t_game *game)
{
	char	*path;
	char	*trimmed_path;

	if (game->config.seen_id[0] == 1)
		return (id_is_duplicate(0));
	path = skip_identifier_and_spaces(line, index, 2);
	trimmed_path = ft_strtrim(path, " \t\n\r");
	if (!trimmed_path)
		return (ERROR);
	game->config.north = ft_strdup(trimmed_path);
	free(trimmed_path);
	if (!game->config.north)
		return (ERROR);
	game->config.seen_id[0]++;
	if (check_texture_path_existence(game->config.north) != SUCCESS)
		return (invalid_north_path(game->config.north));
	return (SUCCESS);
}

int	get_south_path(char *line, int index, t_game *game)
{
	char	*path;
	char	*trimmed_path;

	if (game->config.seen_id[1] == 1)
		return (id_is_duplicate(1));
	path = skip_identifier_and_spaces(line, index, 2);
	trimmed_path = ft_strtrim(path, " \t\n\r");
	if (!trimmed_path)
		return (ERROR);
	game->config.south = ft_strdup(trimmed_path);
	free(trimmed_path);
	if (!game->config.south)
		return (ERROR);
	game->config.seen_id[1]++;
	if (check_texture_path_existence(game->config.south) != SUCCESS)
		return (invalid_south_path(game->config.south));
	return (SUCCESS);
}

int	get_west_path(char *line, int index, t_game *game)
{
	char	*path;
	char	*trimmed_path;

	if (game->config.seen_id[2] == 1)
		return (id_is_duplicate(2));
	path = skip_identifier_and_spaces(line, index, 2);
	trimmed_path = ft_strtrim(path, " \t\n\r");
	if (!trimmed_path)
		return (ERROR);
	game->config.west = ft_strdup(trimmed_path);
	free(trimmed_path);
	if (!game->config.west)
		return (ERROR);
	game->config.seen_id[2]++;
	if (check_texture_path_existence(game->config.west) != SUCCESS)
		return (invalid_west_path(game->config.west));
	return (SUCCESS);
}

int	get_east_path(char *line, int index, t_game *game)
{
	char	*path;
	char	*trimmed_path;

	if (game->config.seen_id[3] == 1)
		return (id_is_duplicate(3));
	path = skip_identifier_and_spaces(line, index, 2);
	trimmed_path = ft_strtrim(path, " \t\n\r");
	if (!trimmed_path)
		return (ERROR);
	game->config.east = ft_strdup(trimmed_path);
	free(trimmed_path);
	if (!game->config.east)
		return (ERROR);
	game->config.seen_id[3]++;
	if (check_texture_path_existence(game->config.east) != SUCCESS)
		return (invalid_east_path(game->config.east));
	return (SUCCESS);
}
