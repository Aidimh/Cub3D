/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:54:55 by moel-aid          #+#    #+#             */
/*   Updated: 2025/11/17 15:54:57 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_valid_xpm_path(char *path)
{
	char	*dot;
	char	*p;

	if (!path || !(*path))
		return (ERROR);
	dot = NULL;
	p = path;
	while (*p)
	{
		if (*p == '.')
			dot = p;
		p++;
	}
	if (!dot)
		return (ERROR);
	if (ft_strcmp(dot, ".xpm") == 0)
		return (SUCCESS);
	return (ERROR);
}

int	check_cub_extension(char *filename)
{
	int	len;

	if (!filename)
		return (ERROR);
	len = ft_strlen(filename);
	if (len < 4)
		return (ERROR);
	if (ft_strcmp(filename + len - 4, ".cub") == 0)
		return (SUCCESS);
	return (ERROR);
}
