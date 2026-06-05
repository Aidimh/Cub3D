/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ouaj <mel-ouaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:04:57 by mel-ouaj          #+#    #+#             */
/*   Updated: 2025/11/27 12:06:50 by mel-ouaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotation(t_data *data, double angle)
{
	double	old_x_dir;
	double	old_x_plane;

	old_x_dir = data->x_dir;
	data->x_dir = data->x_dir * cos(angle) - data->y_dir * sin(angle);
	data->y_dir = old_x_dir * sin(angle) + data->y_dir * cos(angle);
	old_x_plane = data->x_plane;
	data->x_plane = data->x_plane * cos(angle) - data->y_plane * sin(angle);
	data->y_plane = old_x_plane * sin(angle) + data->y_plane * cos(angle);
}

int	close_win(t_game *game)
{
	cleanup_mlx(game);
	exit(1);
}

int	check_tile(t_data *data, int tile_x, int tile_y)
{
	if (tile_x < 0 || tile_x >= data->map_width / 64 || tile_y < 0
		|| tile_y >= data->map_height / 64)
		return (0);
	if (data->map[tile_y][tile_x] == '1')
		return (0);
	return (1);
}
