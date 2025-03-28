/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:40:09 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/27 16:34:15 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void destroy_img(t_game *game)
{
	if (game -> back_img)
		mlx_destroy_image(game-> mlx, game -> back_img);
	if (game -> wall_img)
		mlx_destroy_image(game-> mlx, game -> wall_img);
	if (game -> player_img)
		mlx_destroy_image(game-> mlx, game -> player_img);
	if (game -> collect_img)
		mlx_destroy_image(game-> mlx, game -> collect_img);
	if (game -> exit_img)
		mlx_destroy_image(game-> mlx, game -> exit_img);
	destroy_win(game);
}

void	destroy_win(t_game *game)
{
	if (!game)
		return;
	if (game->map.grid)
		free_matrix(game->map.grid);
	if(game->map.new_map)
		free_matrix(game->map.new_map);
	if (game -> win)
		mlx_destroy_window(game -> mlx, game -> win);
	if (game -> mlx)
	{
		mlx_destroy_display(game -> mlx);
		free (game -> mlx);
	}
}
