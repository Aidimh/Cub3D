/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:09:59 by moel-aid          #+#    #+#             */
/*   Updated: 2025/11/17 17:10:01 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

int	id_is_duplicate(int which_dir)
{
	ft_putendl_fd("Error", 2);
	if (which_dir == 0)
		ft_putendl_fd("North direction line is duplicated", 2);
	if (which_dir == 1)
		ft_putendl_fd("South direction line is duplicated", 2);
	if (which_dir == 2)
		ft_putendl_fd("West direction line is duplicated", 2);
	if (which_dir == 3)
		ft_putendl_fd("East direction line is duplicated", 2);
	return (ERROR);
}

int	map_is_not_last(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("map must be last !", 2);
	return (ERROR);
}

int	invalid_map(char *line)
{
	free(line);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Invalid map element!", 2);
	return (ERROR);
}

int	stranger_element(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Stranger element inside the map !", 2);
	return (ERROR);
}

int	ceiling_is_missing(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Ceiling rgb line is missing", 2);
	return (ERROR);
}
