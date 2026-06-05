/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:09:26 by moel-aid          #+#    #+#             */
/*   Updated: 2025/11/17 17:09:30 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

int	empty_map(void)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd("empty map !", 2);
	return (ERROR);
}

int	map_is_short(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("map is too short or doesn't exist !", 2);
	return (ERROR);
}

int	line_isnt_start_walled(int line_index)
{
	line_index++;
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("at row '", 2);
	ft_putnbr_fd(line_index, 2);
	ft_putchar_fd(39, 2);
	ft_putchar_fd(10, 2);
	ft_putendl_fd("Line must start with 1 : (aka :) wall !", 2);
	return (ERROR);
}

int	line_isnt_end_walled(int line_index)
{
	line_index++;
	ft_putendl_fd("Error", 2);
	ft_putstr_fd("at row '", 2);
	ft_putnbr_fd(line_index, 2);
	ft_putchar_fd(39, 2);
	ft_putchar_fd(10, 2);
	ft_putendl_fd("Line must end with 1 : (aka :) wall !", 2);
	return (ERROR);
}

int	duplicated_player(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Duplicated player !", 2);
	return (ERROR);
}
