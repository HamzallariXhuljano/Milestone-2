/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:09:06 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/22 03:46:26 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define IMG_WIN

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <ctype.h>
# include <limits.h>

typedef	struct s_map
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
int	check_wall(t_map *map);
int	check_pe(t_map *map);
int		check_open(char *file);
int		count_line(char *file, t_map *map);
char **read_map(char *file, t_map *map);
int	check_c(t_map *map);
void	init(t_game *game);
void	free_matrix (char **mat);
int	back_tracking(int x, int y, t_map *map);
int	validate_map(char *file, t_map *map);
char	**dup_map(char *file, t_map *map);
void	find_pos(t_map *map);
int	valid_pos(size_t x, size_t y, t_map *map);
int	sign(t_map *map);
int	chack_all(char *file, t_map *map);
void	*load_texture(void *mlx, char *path);
void load_map(t_game *game, char *filename);
void render_map(t_game *game);

#endif
