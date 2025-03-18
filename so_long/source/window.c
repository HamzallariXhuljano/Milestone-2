/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:52:23 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/15 21:29:29 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_game *game)
{
	if (game -> win)
		mlx_destroy_window(game -> mlx, game -> win);
	exit(0);
	return (0);
}

 void	init(t_game *game)
{
	game -> mlx = mlx_init();

	if (!game -> mlx)
	{
		ft_printf("Error\n");
		exit (1);
	}
	game -> win = mlx_new_window(game -> mlx, 500, 500, "first_tray");
	if (!game -> win)
	{
		ft_printf("Error\n");
		exit (1);
	}
	mlx_hook(game -> win, 17, 0, close_win, game);
}

