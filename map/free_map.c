/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 01:24:24 by marvin            #+#    #+#             */
/*   Updated: 2021/12/24 01:24:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	free_map(t_game *game)
{
	int	y;

	y = 0;
	mlx_destroy_window(game->mlx, game->window);
	free(game->mlx);
	while (y < game->map.size.y)
	{
		free(game->map.mapready[y]);
		y++;
	}
	free(game->map.mapready);
	return (0);
}

int	free_exit(t_game *game, char *msg)
{
	printf("%s", msg);
	free_map(game);
	exit(0);
}
