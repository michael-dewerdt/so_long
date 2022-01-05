/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:14:43 by mea               #+#    #+#             */
/*   Updated: 2022/01/04 16:47:18 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checker_miss(int checker[])
{
	if (checker[0] != 1 || checker[1] != 1 || checker[2] != 1)
	{
		printf("ERROR : You need a player, at least one collectible and an \
			exit in your map.ber file.\n");
		exit(EXIT_FAILURE);
	}
	return (1);
}

int	count_collectibles(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->dofus = 0;
	while (y < game->map.size.y)
	{
		x = 0;
		while (x < game->map.size.x)
		{
			if (game->map.mapready[y][x] == 'C')
				game->dofus++;
				x++;
		}
		y++;
	}
	return (0);
}

int	count_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.size.y)
	{
		x = 0;
		while (x < game->map.size.x)
		{
			if (game->map.mapready[y][x] == 'P')
				game->player++;
				x++;
		}
		y++;
	}
	if (game->player > 1)
	{
		printf("You can't have more than 1 player at once.");
		return (2);
	}
	return (0);
}
