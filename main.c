/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:56:19 by mea               #+#    #+#             */
/*   Updated: 2022/01/04 15:10:48 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_init_position(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (y < game->map.size.y)
	{
		x = 0;
		while (x <= game->map.size.x)
		{
			if (game->map.mapready[y][x] == 'P')
			{
				game->img.pos.x = x;
				game->img.pos.y = y;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	checkarg(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("You need to add a file (.ber).\n");
		return (0);
	}
	else if (!ft_strstr(argv[1], ".ber"))
	{
		printf("Invalid map extension. Use .ber");
		return (0);
	}
	else if (argc > 2)
	{
		if (!ft_strstr(argv[1], ".ber"))
		{
			printf("Invalid map extension. Use .ber");
			return (0);
		}
		else
		{
			printf("FYI : Only the first file will be used\n");
			return (1);
		}
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (!checkarg(argc, argv))
		return (0);
	get_x_y(&game, argv);
	init_map(&game, argv);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.window_size.x, \
	game.window_size.y, "so_long");
	get_init_position(&game);
	count_collectibles(&game);
	if (count_player(&game) == 2)
		return (0);
	push_sprites_on_window(&game);
	mlx_hook(game.window, X_EVENT_KEY_PRESS, 1L << 0, key_press, &game);
	mlx_loop(game.mlx);
}
