/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:10:39 by moel-aid          #+#    #+#             */
/*   Updated: 2025/11/17 17:10:41 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

int	invalid_extension(char *filename)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(filename, 2);
	ft_putendl_fd(" wrong file type!", 2);
	return (ERROR);
}

int	file_not_found(char *filename)
{
	ft_putstr_fd("Error\n", 2);
	if (filename)
		ft_putstr_fd(filename, 2);
	ft_putendl_fd(" file not found!", 2);
	return (ERROR);
}

int	textures_not_found(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("No textures found !", 2);
	return (ERROR);
}

int	missing_direction(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("a missing direction !", 2);
	return (ERROR);
}

int	floor_is_missing(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Floor rgb line is missing", 2);
	return (ERROR);
}
