/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ouaj <mel-ouaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:07:56 by mel-ouaj          #+#    #+#             */
/*   Updated: 2025/11/28 10:31:22 by mel-ouaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_delta(t_data *data)
{
	data->player_x = data->x_pos / 64.0;
	data->player_y = data->y_pos / 64.0;
	if (data->ray_dir_x == 0)
		data->deltadist_x = 1e30;
	else
		data->deltadist_x = fabs(1 / data->ray_dir_x);
	if (data->ray_dir_y == 0)
		data->deltadist_y = 1e30;
	else
		data->deltadist_y = fabs(1 / data->ray_dir_y);
	data->map_x = (int)data->player_x;
	data->map_y = (int)data->player_y;
}

void	calculation(t_data *data)
{
	set_delta(data);
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->sidestep_x = (data->player_x - data->map_x) * data->deltadist_x;
	}
	else
	{
		data->step_x = 1;
		data->sidestep_x = (data->map_x + 1 - data->player_x)
			* data->deltadist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->sidestep_y = (data->player_y - data->map_y) * data->deltadist_y;
	}
	else
	{
		data->step_y = 1;
		data->sidestep_y = (data->map_y + 1 - data->player_y)
			* data->deltadist_y;
	}
}

void	check_sides(t_data *data)
{
	if (data->side == 0)
		data->wall_dist = data->sidestep_x - data->deltadist_x;
	else
		data->wall_dist = data->sidestep_y - data->deltadist_y;
}

void	dda(t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->sidestep_x < data->sidestep_y)
		{
			data->sidestep_x += data->deltadist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->sidestep_y += data->deltadist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->map_x < 0 || data->map_x >= (data->map_width)
			|| data->map_y < 0 || data->map_y >= (data->map_height))
			return ;
		if (data->map[data->map_y][data->map_x] == '1')
			hit = 1;
	}
	check_sides(data);
}

void	cast_rays(t_data *data)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		data->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		data->ray_dir_x = data->x_dir + data->x_plane * data->camera_x;
		data->ray_dir_y = data->y_dir + data->y_plane * data->camera_x;
		calculation(data);
		dda(data);
		draw_walls(data, x);
		x++;
	}
}
