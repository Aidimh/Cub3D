/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:09:38 by moel-aid          #+#    #+#             */
/*   Updated: 2025/11/17 17:09:43 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

int	north_direction_missing(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("North direction is missing", 2);
	return (ERROR);
}

int	west_direction_missing(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("West direction is missing", 2);
	return (ERROR);
}

int	map_is_not_fully_walled(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Map is not fully walled !", 2);
	return (ERROR);
}

int	east_direction_missing(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("East direction is missing", 2);
	return (ERROR);
}

int	south_direction_missing(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("South direction is missing", 2);
	return (ERROR);
}
