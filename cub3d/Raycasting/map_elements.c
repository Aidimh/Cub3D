/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ouaj <mel-ouaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:16:16 by mel-ouaj          #+#    #+#             */
/*   Updated: 2025/11/27 12:05:58 by mel-ouaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E' || data->map[i][j] == 'W'
				|| data->map[i][j] == 'N' || data->map[i][j] == 'S')
			{
				data->y_pos = i * 64 + 32;
				data->x_pos = j * 64 + 32;
			}
			j++;
		}
		i++;
	}
}

void	load_all_textures(t_game *game)
{
	t_data	*data;

	data = game->data;
	load_texture(data, &data->tex_no, game->config.north);
	load_texture(data, &data->tex_so, game->config.south);
	load_texture(data, &data->tex_ea, game->config.east);
	load_texture(data, &data->tex_we, game->config.west);
}

void	map_dimensions(t_game *game)
{
	game->data->map_height = game->config.map.height * 64;
	game->data->map_width = game->config.map.width * 64;
}

void	set_numbers(t_data *data, int x, int y)
{
	data->x_dir = x;
	data->y_dir = y;
	data->x_plane = -(data->y_dir) * 0.66;
	data->y_plane = data->x_dir * 0.66;
}

void	player_dir(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
				set_numbers(data, 1, 0);
			if (data->map[i][j] == 'W')
				set_numbers(data, -1, 0);
			if (data->map[i][j] == 'N')
				set_numbers(data, 0, -1);
			if (data->map[i][j] == 'S')
				set_numbers(data, 0, 1);
			j++;
		}
		i++;
	}
}
