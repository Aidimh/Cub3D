/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:09:49 by moel-aid          #+#    #+#             */
/*   Updated: 2025/11/17 17:09:52 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

int	player_not_found(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Player was not found !", 2);
	return (ERROR);
}

int	invalid_north_path(char *north_path)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(north_path, 2);
	ft_putendl_fd(" : is invalid xpm file path!", 2);
	return (ERROR);
}

int	invalid_south_path(char *south_path)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(south_path, 2);
	ft_putendl_fd(" : is invalid xpm file path!", 2);
	return (ERROR);
}

int	invalid_west_path(char *west_path)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(west_path, 2);
	ft_putendl_fd(" : is invalid xpm file path!", 2);
	return (ERROR);
}

int	invalid_east_path(char *east_path)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(east_path, 2);
	ft_putendl_fd(" : is invalid xpm file path!", 2);
	return (ERROR);
}
