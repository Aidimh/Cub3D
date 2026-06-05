/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ouaj <mel-ouaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 11:59:59 by mel-ouaj          #+#    #+#             */
/*   Updated: 2025/11/27 12:15:01 by mel-ouaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	to_hex(int r, int g, int b)
{
	return (((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF));
}

void	coloring(t_data *data, t_config *config)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				color = to_hex(config->ceiling.r, config->ceiling.g,
						config->ceiling.b);
			else
				color = to_hex(config->floor.r, config->floor.g,
						config->floor.b);
			my_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	my_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dest;

	if (x >= 0 && y >= 0 && x < SCREEN_WIDTH && y < SCREEN_HEIGHT)
	{
		dest = img->addr + (y * img->line_length + x * (img->bpp / 8));
		*(unsigned int *)dest = color;
	}
}

int	load_texture(t_data *data, t_tex *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(data->mlx, path, &tex->width,
			&tex->height);
	if (!tex->img)
	{
		fprintf(stderr, "Error: failed to load texture: %s\n", path);
		return (ERROR);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len,
			&tex->endian);
	if (!tex->addr)
	{
		fprintf(stderr, "Error: failed to get texture data: %s\n", path);
		return (ERROR);
	}
	return (SUCCESS);
}
