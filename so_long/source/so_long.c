/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:11:33 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/27 14:53:45 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        return (write(2, "Error: invalid arguments\n", 25), 1);
    if (chack_all(argv[1], &game.map) == -1)
        return (1);

    game.mlx = mlx_init();
    if (!game.mlx)
        return (write(2, "Error: mlx initialization failed\n", 33), 1);

    game.win = mlx_new_window(game.mlx, game.map.width * 64, game.map.height * 64, "so_long");
    if (!game.win)
        return (write(2, "Error: window creation failed\n", 31), 1);

    put_img(&game);
    put_map(&game);

    mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
    mlx_hook(game.win, 17, 0, (void *)exit, 0);
    mlx_loop(game.mlx);

    free_matrix(game.map.grid);
    return (0);
}*/
