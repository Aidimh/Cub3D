/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_parsing_funcs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:55:06 by moel-aid          #+#    #+#             */
/*   Updated: 2025/11/17 16:12:55 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	measure_map(size_t *height, size_t *max_width, char *filename)
{
	char	*line;
	size_t	len;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (file_not_found(filename));
	line = get_next_line(fd);
	while (line)
	{
		if (is_map_line(line) == SUCCESS)
		{
			len = ft_strlen(line);
			if (len > *max_width)
				*max_width = len;
			(*height)++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (SUCCESS);
}

bool	is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	has_only_digits(char *red, char *blue, char *green)
{
	int	i;

	i = 0;
	while (red[i])
	{
		if (!ft_isdigit(red[i]))
			return (ERROR);
		i++;
	}
	i = 0;
	while (green[i])
	{
		if (!ft_isdigit(green[i]))
			return (ERROR);
		i++;
	}
	i = 0;
	while (blue[i])
	{
		if (!ft_isdigit(blue[i]))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
