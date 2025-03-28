/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:11:33 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/28 22:43:01 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_window(t_game *game)
{
	int		win_width;
	int		win_height;

	win_width = game -> map.width * 64;
	win_height = game -> map.height * 64;
	game -> win = mlx_new_window(game -> mlx, win_width, win_height, "so_long");
	if (!game->win)
	{
		mlx_destroy_display(game -> mlx);
		free(game -> mlx);
		free_matrix(game -> map.grid);
		return (-1);
	}
	return (0);
}

int main(int ac, char **av)
{
	t_game	game;


	ft_memset(&game, 0, sizeof(t_game));
	game.moves = 0;
	if (ac != 2)
		return (write(2, "Error\n", 6), -1);
	if(chack_all(av[1], &game.map) == -1)
		return (-1);
	game.mlx = mlx_init();
	if(!game.mlx)
		return (write(2, "Error\n", 6), free_matrix(game.map.grid),-1);
	create_window(&game);
	put_img(&game);
	put_map(&game);
	mlx_hook(game.win, 2, 1L<<0, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	destroy_img(&game);
	return(0);
}
