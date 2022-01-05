/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:57:58 by mea               #+#    #+#             */
/*   Updated: 2022/01/04 16:47:57 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_walls(t_game game)
{
	int		y;
	int		x;

	y = 0;
	while (y < game.map.size.y)
	{
		x = 0;
		if (y == 0 || y == (game.map.size.y - 1))
		{
			while (x < game.map.size.x)
			{
				if (game.map.mapready[y][x] != '1')
					return (0);
				x++;
			}
		}
		if (game.map.mapready[y][0] != '1'
			|| game.map.mapready[y][game.map.size.x - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_principal_char(t_game game)
{
	int		checker[3];
	int		y;
	int		x;

	y = 0;
	while (y < game.map.size.y)
	{
		x = 0;
		while (x <= game.map.size.x)
		{
			if (game.map.mapready[y][x] == 'P')
				checker[0] = 1;
			if (game.map.mapready[y][x] == 'E')
				checker[1] = 1;
			if (game.map.mapready[y][x] == 'C')
				checker[2] = 1;
			x++;
		}
		y++;
	}
	checker_miss(checker);
	return (0);
}

int	check_rectangle(t_game game)
{
	int		y;

	y = 0;
	while (y < game.map.size.y)
	{
		if (game.map.size.x == game.map.size.y)
		{
			printf("ERROR : The map is not a rectangle.\n");
			exit(EXIT_FAILURE);
		}
		y++;
	}
	return (0);
}

int	check_wrong_char(t_game game)
{
	int		y;
	int		x;	

	y = 0;
	while (game.map.mapready[y])
	{
		x = 0;
		while (game.map.mapready[y][x])
		{
			if (game.map.mapready[y][x] != '0' && game.map.mapready[y][x] != '1'
				&& game.map.mapready[y][x] != 'P'
				&& game.map.mapready[y][x] != 'E'
				&& game.map.mapready[y][x] != 'C'
				&& game.map.mapready[y][x] != '\n')
			{
				printf("ERROR : Wrong char found in the map.ber file.\n");
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	checkismapvalid(t_game game)
{
	check_wrong_char(game);
	if (!check_walls(game))
	{
		printf("Error with a side wall. Check your map.ber file.\n");
		exit(EXIT_FAILURE);
	}
	check_principal_char(game);
	check_rectangle(game);
	return (0);
}
