/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mea <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:38:05 by mea               #+#    #+#             */
/*   Updated: 2022/01/04 16:39:34 by mea              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17

# if defined(__APPLE__) && defined(__MACH__)
#  define LEFT_KEY				123	
#  define RIGHT_KEY				124	
#  define UP_KEY				126
#  define DOWN_KEY				125	
#  define A_KEY					0
#  define S_KEY					1
#  define D_KEY					2
#  define W_KEY					13
#  define ESC 					53

# else
#  define LEFT_KEY				65361
#  define RIGHT_KEY				65363
#  define UP_KEY				65362
#  define DOWN_KEY				65364
#  define A_KEY					97
#  define W_KEY					119
#  define S_KEY					115
#  define D_KEY					100
#  define ESC					65307
# endif

# include <mlx.h>
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"

# define IMG_SIZE 64

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_map
{
	char		**mapready;
	t_vector	size;
}				t_map;

typedef struct s_img
{
	void		*img_ptr;
	char		*spt_path;
	t_vector	size;
	t_vector	pos;
	int			*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_vector	window_size;
	t_map		map;
	long		steps;
	t_img		img;
	int			dofus;
	int			player;
	int			steps_count;
}				t_game;

int		get_x_y(t_game *game, char **argv);
void	init_map(t_game *game, char **argv);
void	init_tilemap(t_game *game);
int		checkarg(int argc, char **argv);
int		read_map_file(t_game *game, char **file);
int		checkismapvalid(t_game game);
char	**alloc_columns(char *file);
int		file_linecount(char *file);
int		linecount(char **map);
int		push_sprites_on_window(t_game *game);
int		push_sprites_on_img(t_game *game, int x, int y);
int		count_collectibles(t_game *game);
int		count_player(t_game *game);
int		key_press(int key, t_game *game);
int		free_map(t_game *game);
int		free_exit(t_game *game, char *msg);
int		print_steps(t_game *game);
int		move(int key, t_game *game);
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);
int		check_walls(t_game game);
int		check_principal_char(t_game game);
int		check_rectangle(t_game game);
int		check_wrong_char(t_game game);
int		checker_miss(int checker[]);

#endif