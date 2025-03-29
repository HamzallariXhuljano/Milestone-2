/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textur_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:42:54 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/29 17:51:08 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_to_win(t_game *game, size_t x, size_t y)
{
	if (game -> map.grid[y][x] == '1')
		mlx_put_image_to_window(game->mlx,
			game->win, game->wall_img, x * 64, y * 64);
	else if (game->map.grid[y][x] == '0')
		mlx_put_image_to_window(game->mlx,
			game->win, game->back_img, x * 64, y * 64);
	else if (game->map.grid[y][x] == 'P')
		mlx_put_image_to_window(game->mlx,
			game->win, game->player_img, x * 64, y * 64);
	else if (game->map.grid[y][x] == 'C')
		mlx_put_image_to_window(game->mlx,
			game->win, game->collect_img, x * 64, y * 64);
	else if (game->map.grid[y][x] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->win, game->exit_img, x * 64, y * 64);
}
