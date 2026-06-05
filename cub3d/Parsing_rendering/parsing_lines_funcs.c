/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_lines_funcs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:08:43 by moel-aid          #+#    #+#             */
/*   Updated: 2025/11/17 15:08:49 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

char	*skip_identifier_and_spaces(char *line, int index, int id_len)
{
	if (line[index + 1] == 32 || line[index + 1] == '\t')
		id_len = 1;
	line = line + index + id_len;
	while (*line == ' ' || *line == '\t')
		line++;
	return (line);
}

int	get_map_directions_rgb(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O'
		&& (line[i + 2] == ' ' || line[i + 2] == '\t'))
		return (get_north_path(line, i, game));
	if (line[i] == 'S' && line[i + 1] == 'O'
		&& (line[i + 2] == ' ' || line[i + 2] == '\t'))
		return (get_south_path(line, i, game));
	if (line[i] == 'W' && line[i + 1] == 'E'
		&& (line[i + 2] == ' ' || line[i + 2] == '\t'))
		return (get_west_path(line, i, game));
	if (line[i] == 'E' && line[i + 1] == 'A'
		&& (line[i + 2] == ' ' || line[i + 2] == '\t'))
		return (get_east_path(line, i, game));
	if (line[i] == 'F' && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		return (get_floor_rgb(game, line + i));
	if (line[i] == 'C' && (line[i + 1] == ' ' || line[i + 1] == '\t'))
		return (get_ceiling_rgb(game, line + i));
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Invalid Texture line !", 2);
	return (ERROR);
}
