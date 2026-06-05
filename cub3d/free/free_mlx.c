/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:49:02 by moel-aid          #+#    #+#             */
/*   Updated: 2025/11/18 16:49:06 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

void	free_paths(t_config *config)
{
	if (!config)
		return ;
	if (config->north)
		free(config->north);
	if (config->south)
		free(config->south);
	if (config->east)
		free(config->east);
	if (config->west)
		free(config->west);
}

void	free_rgb(t_rgb *rgb)
{
	int	i;

	if (!rgb->rgb_colors)
		return ;
	if (rgb->rgb_colors)
	{
		i = 0;
		while (rgb->rgb_colors[i])
		{
			free(rgb->rgb_colors[i]);
			i++;
		}
		free(rgb->rgb_colors);
	}
}

void	free_config(t_config *config)
{
	int	i;

	free_paths(config);
	free_rgb(&config->floor);
	free_rgb(&config->ceiling);
	if (config->map.flood_fill_copy)
	{
		i = 0;
		while (config->map.flood_fill_copy[i])
		{
			free(config->map.flood_fill_copy[i]);
			i++;
		}
		free(config->map.flood_fill_copy);
	}
}

void	free_textures(t_data *data)
{
	if (data->tex_no.img)
		mlx_destroy_image(data->mlx, data->tex_no.img);
	if (data->tex_so.img)
		mlx_destroy_image(data->mlx, data->tex_so.img);
	if (data->tex_ea.img)
		mlx_destroy_image(data->mlx, data->tex_ea.img);
	if (data->tex_we.img)
		mlx_destroy_image(data->mlx, data->tex_we.img);
}

void	cleanup_mlx(t_game *game)
{
	t_data	*data;

	data = game->data;
	if (data)
	{
		free_textures(data);
		if (data->img)
			mlx_destroy_image(data->mlx, data->img);
		if (data->mlx_window)
			mlx_destroy_window(data->mlx, data->mlx_window);
		if (data->mlx)
		{
			mlx_destroy_display(data->mlx);
			free(data->mlx);
		}
		free_array(data->map);
		free(data);
	}
	free_config(&game->config);
	free(game);
}
