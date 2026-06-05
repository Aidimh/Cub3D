/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_textures_lines.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:39:36 by moel-aid          #+#    #+#             */
/*   Updated: 2025/11/17 15:39:39 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

int	is_valid_rgb_char(char c)
{
	return ((c >= '0' && c <= '9') || c == ',' || c == ' ' || c == '\t');
}

int	textures_before_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (game->config.seen_id[i] != 1)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	validate_texture_paths(t_config *config)
{
	if (!config->north || is_valid_xpm_path(config->north) != SUCCESS)
		return (invalid_north_path(config->north));
	if (!config->west || is_valid_xpm_path(config->west) != SUCCESS)
		return (invalid_west_path(config->west));
	if (!config->south || is_valid_xpm_path(config->south) != SUCCESS)
		return (invalid_south_path(config->south));
	if (!config->east || is_valid_xpm_path(config->east) != SUCCESS)
		return (invalid_east_path(config->east));
	return (SUCCESS);
}
