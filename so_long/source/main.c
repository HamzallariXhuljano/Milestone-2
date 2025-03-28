/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:54:03 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/27 16:58:11 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    // Initialize game structure
    ft_memset(&game, 0, sizeof(t_game));
    game.moves = 0;

    // Check command line arguments
    if (argc != 2)
    {
        ft_printf("Error: Usage: %s <map.ber>\n", argv[0]);
        return (1);
    }

    // Check and parse the map
    if (chack_all(argv[1], &(game.map)) == -1)
    {
        ft_printf("Error: Invalid map\n");
        return (1);
    }

    // Initialize MLX
    game.mlx = mlx_init();
    if (!game.mlx)
    {
        ft_printf("Error: Failed to initialize MLX\n");
        free_matrix(game.map.grid);
        return (1);
    }

    // Calculate window size
    int win_width = game.map.width * 64;
    int win_height = game.map.height * 64;

    // Create window
    game.win = mlx_new_window(game.mlx, win_width, win_height, "so_long");
    if (!game.win)
    {
        ft_printf("Error: Failed to create window\n");
        // Don't call destroy_img here, just clean up what we've created so far
        mlx_destroy_display(game.mlx);
        free(game.mlx);
        free_matrix(game.map.grid);
        return (1);
    }

    // Load textures
    put_img(&game);

    // Draw initial map
    put_map(&game);

    // Set up hooks
    mlx_hook(game.win, 2, 1L<<0, key_hook, &game);  // Key press
    mlx_hook(game.win, 17, 0, close_window, &game); // Window close button

    // Start game loop
    mlx_loop(game.mlx);

    // This code is never reached due to mlx_loop, but good practice
    destroy_img(&game);
    return (0);
}

// Add this function to handle window close button


// Add this function to free resources
/*void free_resources(t_game *game)
{
    if (!game)
        return;

    // Free map resources
    if (game->map.grid)
        free_matrix(game->map.grid);
    if (game->map.new_map)
        free_matrix(game->map.new_map);

    // Free MLX resources
    if (game->wall_img)
        mlx_destroy_image(game->mlx, game->wall_img);
    if (game->back_img)
        mlx_destroy_image(game->mlx, game->back_img);
    if (game->player_img)
        mlx_destroy_image(game->mlx, game->player_img);
    if (game->collect_img)
        mlx_destroy_image(game->mlx, game->collect_img);
    if (game->exit_img)
        mlx_destroy_image(game->mlx, game->exit_img);

    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
}*/
