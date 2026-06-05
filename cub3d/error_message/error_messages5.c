/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:10:23 by moel-aid          #+#    #+#             */
/*   Updated: 2025/11/17 17:17:14 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

int	space_isnt_walled(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Invalid map: space not properly enclosed by walls.", 2);
	ft_putstr_fd("Hint: all spaces inside the map ", 2);
	ft_putendl_fd("must be surrounded by walls.", 2);
	return (ERROR);
}

int	malloc_failure(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Malloc failed !!", 2);
	return (ERROR);
}

int	missing_map_file(void)
{
	ft_putendl_fd("Error: missing map file argument", 2);
	return (ERROR);
}
