/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 17:10:09 by moel-aid          #+#    #+#             */
/*   Updated: 2025/11/17 17:10:13 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../cub3d.h"

int	forbidden_north_line(char *north_line)
{
	ft_putendl_fd("Error", 2);
	ft_putchar_fd(34, 2);
	ft_putstr_fd(north_line, 2);
	ft_putchar_fd(34, 2);
	ft_putendl_fd(" is forbidden north line name !", 2);
	return (ERROR);
}

int	forbidden_south_line(char *south_line)
{
	ft_putendl_fd("Error", 2);
	ft_putchar_fd(34, 2);
	ft_putstr_fd(south_line, 2);
	ft_putchar_fd(34, 2);
	ft_putendl_fd(" is forbidden south line name !", 2);
	return (ERROR);
}

int	forbidden_east_line(char *east_line)
{
	ft_putendl_fd("Error", 2);
	ft_putchar_fd(34, 2);
	ft_putstr_fd(east_line, 2);
	ft_putchar_fd(34, 2);
	ft_putendl_fd(" is forbidden east line name !", 2);
	return (ERROR);
}

int	forbidden_west_line(char *west_line)
{
	ft_putendl_fd("Error", 2);
	ft_putchar_fd(34, 2);
	ft_putstr_fd(west_line, 2);
	ft_putchar_fd(34, 2);
	ft_putendl_fd(" is forbidden west line name !", 2);
	return (ERROR);
}

int	map_row_is_short(void)
{
	ft_putendl_fd("Eroor", 2);
	ft_putendl_fd("Map row's length can't be 2 characters !", 2);
	return (ERROR);
}
