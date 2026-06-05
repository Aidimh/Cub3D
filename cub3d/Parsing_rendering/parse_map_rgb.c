/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ouaj <mel-ouaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:24:13 by moel-aid          #+#    #+#             */
/*   Updated: 2025/11/28 10:17:36 by mel-ouaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_rgb_line(char *rgb_line)
{
	int	i;

	i = 0;
	while (rgb_line[i])
	{
		if (!ft_isalnum(rgb_line[i]) || rgb_line[i] != ','
			|| rgb_line[i] != ' ' || rgb_line[i] != '\t')
		{
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("Invalid RGB line !", 2);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	check_rgb_values(int red, int green, int blue)
{
	if ((red < 0 || red > 255) || (blue < 0 || blue > 255)
		|| (green < 0 || green > 255))
		return (ERROR);
	return (SUCCESS);
}

int	parse_rgb(t_rgb *rgb, char *rgb_line)
{
	if (!rgb || !rgb_line)
		return (ERROR);
	rgb->rgb_colors = ft_split(rgb_line, ',');
	if (!rgb->rgb_colors || !rgb->rgb_colors[0] || !rgb->rgb_colors[1]
		|| !rgb->rgb_colors[2])
	{
		return (ERROR);
	}
	rgb->red = ft_strtrim(rgb->rgb_colors[0], " \t");
	rgb->green = ft_strtrim(rgb->rgb_colors[1], " \t");
	rgb->blue = ft_strtrim(rgb->rgb_colors[2], " \t");
	if (!rgb->red || !rgb->blue || !rgb->green
		|| has_only_digits(rgb->red, rgb->blue, rgb->green) != SUCCESS)
	{
		free_colors(rgb->red, rgb->blue, rgb->green);
		return (ERROR);
	}
	rgb->r = ft_atoi(rgb->red);
	rgb->g = ft_atoi(rgb->green);
	rgb->b = ft_atoi(rgb->blue);
	free_colors(rgb->red, rgb->green, rgb->blue);
	return (check_rgb_values(rgb->r, rgb->g, rgb->b));
}

int	get_ceiling_rgb(t_game *game, char *line)
{
	char	*rgb_start;

	if (game->config.seen_id[5] > 0)
		return (ERROR);
	rgb_start = line + 1;
	while (*rgb_start == ' ' || *rgb_start == '\t')
		rgb_start++;
	if (parse_rgb(&game->config.ceiling, rgb_start) != SUCCESS)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("ceiling rgb line is invalid or doesn't exists!", 2);
		return (ERROR);
	}
	game->config.seen_id[5]++;
	game->config.ceiling_flag++;
	return (SUCCESS);
}

int	get_floor_rgb(t_game *game, char *line)
{
	char	*rgb_start;

	if (game->config.seen_id[4] > 0)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Duplicated floor rgb line !", 2);
		return (ERROR);
	}
	rgb_start = line + 1;
	while (*rgb_start == ' ' || *rgb_start == '\t')
		rgb_start++;
	if (parse_rgb(&game->config.floor, rgb_start) != SUCCESS)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("floor rgb line is invalid or doesn't exists!", 2);
		return (ERROR);
	}
	game->config.seen_id[4]++;
	game->config.floor_flag++;
	return (SUCCESS);
}
