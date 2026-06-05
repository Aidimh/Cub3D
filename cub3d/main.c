/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ouaj <mel-ouaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:15:54 by mel-ouaj          #+#    #+#             */
/*   Updated: 2025/11/26 16:42:22 by mel-ouaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	initilaize_data(t_game *game)
{
	int	i;

	i = 0;
	game->player.index = 0;
	game->line_length = 0;
	game->config.map.map_grid = malloc((sizeof(char *) * MAX_HEIGHT));
	if (!game->config.map.map_grid)
		return (ERROR);
	while (i < MAX_HEIGHT)
	{
		game->config.map.map_grid[i] = NULL;
		i++;
	}
	return (SUCCESS);
}

int	error_free(t_game *game)
{
	free_all_data(game);
	free(game);
	return (ERROR);
}

int	free_mlx_loop(t_game *game)
{
	free_array(game->config.map.map_grid);
	cleanup_mlx(game);
	return (ERROR);
}

void	mlx_hook_ini(t_game *game)
{
	mlx_hook(game->data->mlx_window, 2, 1L << 0, keypress, game);
	mlx_hook(game->data->mlx_window, 3, 1L << 1, keyrelease, game);
	mlx_hook(game->data->mlx_window, 17, 1L << 17, close_win, game);
	mlx_loop_hook(game->data->mlx, keyhook, &game->config);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac < 2)
		return (missing_map_file());
	if (av[1][0] == '\0' || !av[1])
		return (file_not_found(av[1]));
	game = malloc(sizeof(t_game));
	ft_bzero(game, sizeof(t_game));
	if (!game)
		return (ERROR);
	ft_bzero(game, sizeof(t_game));
	game->data = malloc(sizeof(t_data));
	ft_bzero((game->data), sizeof(t_data));
	if (initilaize_data(game) != SUCCESS)
		return (error_free(game));
	if (parse_map(game, av[1]) != SUCCESS)
		return (free_mlx_loop(game));
	game->data->map = game->config.map.map_grid;
	map_dimensions(game);
	draw_map(game);
	mlx_hook_ini(game);
	mlx_loop(game->data->mlx);
	free_all_data(game);
	free(game);
	return (SUCCESS);
}
