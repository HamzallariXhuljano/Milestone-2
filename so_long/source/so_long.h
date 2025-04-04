/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:09:06 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/29 17:51:28 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "mlx.h"

# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <ctype.h>
# include <limits.h>

typedef struct s_map
{
	char	**grid;
	char	**new_map;
	size_t	width;
	size_t	height;
	int		play_x;
	int		play_y;
	int		collectibles;
	int		cnt_coll;
	int		exit;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	void	*player_img;
	void	*wall_img;
	void	*back_img;
	void	*collect_img;
	void	*exit_img;
	int		moves;
}	t_game;

int		close_win(t_game *game);
int		check_wall(t_map *map);
int		check_pe(t_map *map);
int		check_open(char *file);
int		count_line(char *file, t_map *map);
int		check_c(t_map *map);
int		back_tracking(int x, int y, t_map *map);
int		valid_pos(size_t x, size_t y, t_map *map);
int		sign(t_map *map);
int		chack_all(char *file, t_map *map);
int		key_hook(int keycode, t_game *game);
int		validate_map(char *file, t_map *map);
int		chek_move(t_game *game, size_t new_x, size_t new_y);
int		close_window(t_game *game);
void	init(t_game *game);
void	free_matrix(char **mat);
void	find_pos(t_map *map);
void	put_map(t_game *game);
void	*texture_creation(void *mlx, char *path, t_game *game);
void	put_img(t_game *game);
void	move_player(t_game *game, size_t new_x, size_t new_y);
void	win_exit(t_game *game);
void	destroy_img(t_game *game);
void	destroy_win(t_game *game);
void	img_to_win(t_game *gmae, size_t x, size_t y);
char	**read_map(char *file, t_map *map);
char	**dup_map(char *file, t_map *map);

#endif
