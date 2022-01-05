/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:53:14 by mea               #+#    #+#             */
/*   Updated: 2022/01/04 15:16:32 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	push_sprites_on_img(t_game *game, int x, int y)
{
	if (game->map.mapready[y][x] == '1')
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/wall.xpm", &game->img.size.x, &game->img.size.y);
	else if (game->map.mapready[y][x] == '0')
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/floor.xpm", &game->img.size.x, &game->img.size.y);
	else if ((game->map.mapready[y][x] == 'E') && (game->dofus > 0))
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/exit_closed.xpm", &game->img.size.x, &game->img.size.y);
	else if ((game->map.mapready[y][x] == 'E') && (game->dofus == 0))
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/exit.xpm", &game->img.size.x, &game->img.size.y);
	else if (game->map.mapready[y][x] == 'C')
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/collectibles.xpm", &game->img.size.x, &game->img.size.y);
	else if (game->map.mapready[y][x] == 'P')
		game->img.img_ptr = mlx_xpm_file_to_image(game->mlx, \
		"./sprites/player.xpm", &game->img.size.x, &game->img.size.y);
	mlx_put_image_to_window(game->mlx, game->window, game->img.img_ptr, \
	IMG_SIZE * x, IMG_SIZE * y);
	return (0);
}

int	push_sprites_on_window(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map.size.y)
	{
		x = 0;
		while (x < game->map.size.x)
		{
			push_sprites_on_img(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
