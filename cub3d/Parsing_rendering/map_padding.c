/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:54:41 by moel-aid          #+#    #+#             */
/*   Updated: 2025/11/17 15:54:43 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*pad_line(char *line, size_t max_len)
{
	size_t	len;
	size_t	i;
	char	*padded;

	len = ft_strlen(line);
	if (len >= max_len)
		return (ft_strdup(line));
	padded = malloc(max_len + 1);
	if (!padded)
		return (NULL);
	ft_strcpy(padded, line);
	i = len;
	while (i < max_len)
		padded[i++] = ' ';
	padded[max_len] = '\0';
	return (padded);
}

int	pad_map(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	game->config.map.flood_fill_copy = malloc(
			sizeof(char *) * (game->config.map.height + 1));
	if (!game->config.map.flood_fill_copy)
		return (malloc_failure());
	while (i < game->config.map.height)
	{
		game->config.map.flood_fill_copy[i] = pad_line(
				game->config.map.map_grid[i], game->config.map.width);
		if (!game->config.map.flood_fill_copy[i])
		{
			j = i;
			while (j > 0)
				free(game->config.map.flood_fill_copy[--j]);
			free(game->config.map.flood_fill_copy);
			game->config.map.flood_fill_copy = NULL;
			return (malloc_failure());
		}
		i++;
	}
	game->config.map.flood_fill_copy[i] = NULL;
	return (SUCCESS);
}
