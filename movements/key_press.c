/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 23:46:33 by marvin            #+#    #+#             */
/*   Updated: 2021/12/23 23:46:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	print_steps(t_game *game)
{
	char	*str;

	str = ft_itoa(game->steps_count);
	mlx_string_put(game->mlx, game->window, (game->img.pos.x * IMG_SIZE) - 10,
		(game->img.pos.y * IMG_SIZE) + 5, 0x833000, str);
	free(str);
	return (0);
}

int	key_press(int key, t_game *game)
{
	int	steps;

	steps = game->steps_count;
	if (key == ESC)
		free_exit(game, "Game closed ! See you next time  !\n");
	else
		move(key, game);
	if (steps != game->steps_count)
		printf("Steps: %d\n", game->steps_count);
	push_sprites_on_window(game);
	print_steps(game);
	return (0);
}
