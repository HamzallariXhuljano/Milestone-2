/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:31:08 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/22 22:30:15 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mlx.h"

void	*load_texture(void *mlx, char *path)
{
	int width;
	int height;
	void *img = mlx_xpm_file_to_image(mlx, path, &width, &height);

	if (!img)
	{
		printf("Errore: impossibile caricare la texture %s\n", path);
		exit(1);
	}
	printf("Texture %s caricata con successo!\n", path);
	return img;
}

void	render_map(t_game *game)
{
	size_t x;
	size_t y;

	if (!game->map.grid || !game->mlx || !game->win)
		return ;
	y = 0;
	while (y < game->map.height)
	{
		 x = 0;
		while (x < (game->map.width))
		{
			if (game->map.grid[y][x] == '1') // Muro
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * 64, y * 64);
			else if (game->map.grid[y][x] == '0') // Sfondo
				mlx_put_image_to_window(game->mlx, game->win, game->back_img, x * 64, y * 64);
			else if (game->map.grid[y][x] == 'P') // Giocatore
				mlx_put_image_to_window(game->mlx, game->win, game->player_img, x * 64, y * 64);
			else if (game->map.grid[y][x] == 'C') // Collezionabile
				mlx_put_image_to_window(game->mlx, game->win, game->collect_img, x * 64, y * 64);
			else if (game->map.grid[y][x] == 'E') // Uscita
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

