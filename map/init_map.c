/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:05:43 by marvin            #+#    #+#             */
/*   Updated: 2021/12/21 18:05:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_x_y(t_game *game, char **argv)
{
	int		fd;
	char	*line;

	line = NULL;
	game->map.size.x = 0;
	game->map.size.y = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error with the file.");
		return (0);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->map.size.x = ft_strlen(line) - 1;
		game->map.size.y++;
	}
	free(line);
	close(fd);
	return (0);
}

int	read_map_file(t_game *game, char **argv)
{
	int		fd;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Map not found");
		return (0);
	}
	i = 0;
	while (1)
	{
		game->map.mapready[i] = malloc(sizeof(char) * game->map.size.x + 1);
		game->map.mapready[i] = get_next_line(fd);
		if (!game->map.mapready[i])
			break ;
		i++;
	}
	close(fd);
	checkismapvalid(*game);
	return (0);
}

void	init_map(t_game *game, char **argv)
{
	game->map.mapready = malloc((game->map.size.y + 1) * sizeof(char *));
	game->steps_count = 0;
	game->dofus = 0;
	read_map_file(game, argv);
	game->window_size.x = game->map.size.x * IMG_SIZE;
	game->window_size.y = game->map.size.y * IMG_SIZE;
}
