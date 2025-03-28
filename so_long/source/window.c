/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:31:08 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/27 16:49:08 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mlx.h"

void	*texture_creation(void *mlx, char *path, t_game *game)
{
	int width;
	int height;
	void *img = mlx_xpm_file_to_image(mlx, path, &width, &height);

	if (!img)
	{
		printf("Errore: impossibile caricare la texture %s\n", path);
		//free_matrix(game->map.grid);
		destroy_img(game);
		exit(1);
	}
	printf("Texture %s caricata con successo!\n", path);
	return img;
}
void	put_img(t_game *game)
{
	game -> wall_img = texture_creation(game -> mlx, "textures/wall_64x64.xpm", game);
	game -> back_img = texture_creation(game -> mlx, "textures/grass.xpm", game);
	game->player_img = texture_creation(game->mlx, "textures/big_naruto.xpm", game);
	game->collect_img = texture_creation(game->mlx, "textures/ramen.xpm", game);
	game->exit_img = texture_creation(game->mlx, "textures/porta.xpm", game);
}

void	put_map(t_game *game)
{
	size_t x;
	size_t y;

	if (!game->map.grid || !game->mlx || !game->win)
		return ;
	y = 0;
	while (y < game->map.height)
	{
		 x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * 64, y * 64);
			else if (game->map.grid[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->back_img, x * 64, y * 64);
			else if (game->map.grid[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player_img, x * 64, y * 64);
			else if (game->map.grid[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect_img, x * 64, y * 64);
			else if (game->map.grid[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

int key_hook(int keycode, t_game *game)
{


	printf("Tasto premuto: %d\n", keycode);
	printf("Posizione attuale: x= %d, y =%d\n", game-> map.play_x, game -> map.play_y);
	if (keycode == XK_w)
		move_player(game, game -> map.play_x, game -> map.play_y - 1);
	else if (keycode == XK_s)
		move_player(game, game -> map.play_x , game -> map.play_y + 1);
	else if (keycode == XK_a)
	{
		printf("A");
		fflush(stdout);
		move_player(game, game -> map.play_x - 1, game -> map.play_y);
	}
	else if (keycode == XK_d)
		move_player(game, game -> map.play_x + 1, game -> map.play_y);
	return (0);
}


void	move_player(t_game *game, size_t new_x, size_t new_y)
{
	char	pos;

	if (chek_move(game, new_x, new_y) == -1)
		return;
	pos = game->map.grid[new_y][new_x];
	if (pos == '1')
		return;
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
	ft_printf("%d\n", game->moves);
	put_map(game);
}


