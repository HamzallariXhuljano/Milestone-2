/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:31:08 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/31 12:55:00 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*texture_creation(void *mlx, char *path, t_game *game)
{
	int		width;
	int		height;
	void	*img;

	img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!img)
	{
		write(2, "Error\n", 6);
		destroy_img(game);
		exit(1);
	}
	return (img);
}

void	put_img(t_game *game)
{
	game -> wall_img = texture_creation(game -> mlx,
			"textures/wall_64x64.xpm", game);
	game -> back_img = texture_creation(game -> mlx,
			"textures/grass.xpm", game);
	game->player_img = texture_creation(game->mlx,
			"textures/big_naruto.xpm", game);
	game->collect_img = texture_creation(game->mlx,
			"textures/ramen.xpm", game);
	game->exit_img = texture_creation(game->mlx,
			"textures/porta.xpm", game);
}

void	put_map(t_game *game)
{
	size_t	x;
	size_t	y;

	if (!game->map.grid || !game->mlx || !game->win)
		return ;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			img_to_win(game, x, y);
			x++;
		}
		y++;
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == XK_w)
		move_player(game, game -> map.play_x, game -> map.play_y - 1);
	else if (keycode == XK_s)
		move_player(game, game -> map.play_x, game -> map.play_y + 1);
	else if (keycode == XK_a)
		move_player(game, game -> map.play_x - 1, game -> map.play_y);
	else if (keycode == XK_d)
		move_player(game, game -> map.play_x + 1, game -> map.play_y);
	else if (keycode == XK_Escape)
		close_window(game);
	return (0);
}

void	move_player(t_game *game, size_t new_x, size_t new_y)
{
	char	pos;

	if (chek_move(game, new_x, new_y) == -1)
		return ;
	pos = game->map.grid[new_y][new_x];
	if (pos == '1')
		return ;
	if (pos == 'E')
	{
		win_exit(game);
		return ;
	}
	if (pos == 'C')
	{
		game->map.collectibles--;
		game->map.grid[new_y][new_x] = '0';
	}
	game->map.grid[game->map.play_y][game->map.play_x] = '0';
	game->map.grid[new_y][new_x] = 'P';
	game->map.play_x = new_x;
	game->map.play_y = new_y;
	game->moves++;
	ft_printf("Mosse: %d\n", game->moves);
	put_map(game);
}
