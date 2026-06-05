/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ouaj <mel-ouaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:38:01 by mel-ouaj          #+#    #+#             */
/*   Updated: 2025/11/27 12:22:03 by mel-ouaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_map(t_game *game)
{
	t_data	*data;

	data = game->data;
	data->mlx = mlx_init();
	load_all_textures(game);
	data->mlx_window = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"test");
	data->img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length,
			&data->endian);
	player_pos(data);
	player_dir(data);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img, 0, 0);
}

int	get_tex_color(t_tex *tex, int x, int y)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= tex->width || y >= tex->height)
		return (0);
	pixel = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(unsigned int *)pixel);
}

void	draw_vertical(t_data *data, int x, int start, int end)
{
	int	color;

	while (start < end)
	{
		data->tex_y = (int)data->texpos;
		data->texpos = data->texpos + data->tex_step;
		color = get_tex_color(data->wall_tex, data->tex_x, data->tex_y);
		my_pixel_put(data, x, start, color);
		start++;
	}
}

void	set_tex(t_data *data)
{
	if (data->map[data->map_y][data->map_x] != '1')
		return ;
	if (data->side == 0 && data->ray_dir_x > 0)
		data->wall_tex = &data->tex_ea;
	else if (data->side == 0 && data->ray_dir_x < 0)
		data->wall_tex = &data->tex_we;
	else if (data->side == 1 && data->ray_dir_y < 0)
		data->wall_tex = &data->tex_no;
	else
		data->wall_tex = &data->tex_so;
	if (data->side == 0)
		data->wall_x = data->player_y + data->wall_dist * data->ray_dir_y;
	else
		data->wall_x = data->player_x + data->wall_dist * data->ray_dir_x;
	data->fwallx = data->wall_x - floor(data->wall_x);
	data->tex_x = (int)(data->fwallx * data->wall_tex->width);
}

void	draw_walls(t_data *data, int x)
{
	int	lineheight;
	int	start;
	int	end;

	set_tex(data);
	lineheight = (int)(SCREEN_HEIGHT / data->wall_dist);
	start = -lineheight / 2 + SCREEN_HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = lineheight / 2 + SCREEN_HEIGHT / 2;
	if (end >= SCREEN_HEIGHT)
		end = SCREEN_HEIGHT - 1;
	data->tex_step = data->wall_tex->height / (double)lineheight;
	data->texpos = (start - SCREEN_HEIGHT / 2 + lineheight / 2)
		* data->tex_step;
	draw_vertical(data, x, start, end);
}
