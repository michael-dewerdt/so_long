/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:03:35 by mea               #+#    #+#             */
/*   Updated: 2022/01/04 17:03:35 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move(int key, t_game *game)
{
	if ((game->map.mapready[game->img.pos.y][game->img.pos.x - 1] != '1') && \
		key == A_KEY && game->steps_count++)
		move_left(game);
	if ((game->map.mapready[game->img.pos.y][game->img.pos.x + 1] != '1') && \
		key == D_KEY && game->steps_count++)
		move_right(game);
	if ((game->map.mapready[game->img.pos.y + 1][game->img.pos.x] != '1') && \
		key == S_KEY && game->steps_count++)
		move_down(game);
	if ((game->map.mapready[game->img.pos.y - 1][game->img.pos.x] != '1') && \
		key == W_KEY && game->steps_count++)
		move_up(game);
	return (0);
}

int	move_left(t_game *game)
{
	game->map.mapready[game->img.pos.y][game->img.pos.x] = '0';
	game->img.pos.x -= 1;
	if (game->map.mapready[game->img.pos.y][game->img.pos.x] == 'C')
		game->dofus--;
	else if (game->map.mapready[game->img.pos.y][game->img.pos.x] == 'E')
	{
		if (game->dofus == 0)
		{
			printf("You made %d moves, Goodbye !\n", game->steps_count);
			free_exit(game, "\n");
			return (0);
		}
		else
		{
			game->img.pos.x += 1;
			game->steps_count--;
		}
	}
	game->map.mapready[game->img.pos.y][game->img.pos.x] = 'P';
	return (0);
}

int	move_right(t_game *game)
{	
	game->map.mapready[game->img.pos.y][game->img.pos.x] = '0';
	game->img.pos.x += 1;
	if (game->map.mapready[game->img.pos.y][game->img.pos.x] == 'C')
		game->dofus--;
	else if (game->map.mapready[game->img.pos.y][game->img.pos.x] == 'E')
	{
		if (game->dofus == 0)
		{
			printf("You made %d moves, Goodbye !\n", game->steps_count);
			free_exit(game, "\n");
			return (0);
		}
		else
		{
			game->img.pos.x -= 1;
			game->steps_count--;
		}
	}
	game->map.mapready[game->img.pos.y][game->img.pos.x] = 'P';
	return (0);
}

int	move_down(t_game *game)
{
	game->map.mapready[game->img.pos.y][game->img.pos.x] = '0';
	game->img.pos.y += 1;
	if (game->map.mapready[game->img.pos.y][game->img.pos.x] == 'C')
		game->dofus--;
	else if (game->map.mapready[game->img.pos.y][game->img.pos.x] == 'E')
	{
		if (game->dofus == 0)
		{
			printf("You made %d moves, Goodbye !\n", game->steps_count);
			free_exit(game, "\n");
			return (0);
		}
		else
		{
			game->img.pos.y -= 1;
			game->steps_count--;
		}
	}
	game->map.mapready[game->img.pos.y][game->img.pos.x] = 'P';
	return (0);
}

int	move_up(t_game *game)
{
	game->map.mapready[game->img.pos.y][game->img.pos.x] = '0';
	game->img.pos.y -= 1;
	if (game->map.mapready[game->img.pos.y][game->img.pos.x] == 'C')
		game->dofus--;
	else if (game->map.mapready[game->img.pos.y][game->img.pos.x] == 'E')
	{
		if (game->dofus == 0)
		{
			printf("You made %d moves, Goodbye !\n", game->steps_count);
			free_exit(game, "\n");
			return (0);
		}
		else
		{
			game->img.pos.y += 1;
			game->steps_count--;
		}
	}
	game->map.mapready[game->img.pos.y][game->img.pos.x] = 'P';
	return (0);
}
