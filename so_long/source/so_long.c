/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:11:33 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/22 22:30:45 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_game game;
	t_map	map;
	if (ac != 2)
		return(write(2, "Error12\n", 8), -1);

	game.mlx = mlx_init();
	if (chack_all(av[1], &map) == -1)
		return (-1);
	read_map(av[1], &game.map);
	game.win = mlx_new_window(game.mlx,  game.map.width * 64, game.map.height * 64, "so_long");
	if(!game.map.grid)
		return(write(2, "Error13\n", 8), -1);
	game.wall_img = load_texture(game.mlx, "textures/wall_64x64.xpm");
	game.back_img = load_texture(game.mlx, "textures/grass.xpm");
	game.player_img = load_texture(game.mlx, "textures/naruto2.xpm");
	game.collect_img = load_texture(game.mlx, "textures/ramen.xpm");
	game.exit_img = load_texture(game.mlx, "textures/porta.xpm");
	render_map(&game);
	mlx_loop(game.mlx);
	return (0);
}
