/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:31:08 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/22 03:59:13 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mlx.h"

void    *load_texture(void *mlx, char *path)
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

void render_map(t_game *game)
{
    if (!game->map.grid || !game->mlx || !game->win)
    {
        printf("Errore: mappa o finestra non inizializzata!\n");
        return;
    }

    for (size_t y = 0; y < game->map.height; y++)
    {
        for (size_t x = 0; x < game->map.width; x++)
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
        }
    }
}

// int main(int argc, char **argv)
// {
//     if (argc != 2)
//     {
//         printf("Uso corretto: ./so_long map.ber\n");
//         return (1);
//     }

//     t_game game;

//     game.mlx = mlx_init();

//     load_map(&game, argv[1]);  // Legge la mappa prima di creare la finestra

//     game.win = mlx_new_window(game.mlx, game.map.width * 64, game.map.height * 64, "so_long");

//     // Controlla se la mappa è stata caricata correttamente
//     if (!game.map.grid)
//     {
//         printf("Errore: mappa non valida!\n");
//         return (1);
//     }

//     // Carica le immagini
//     game.wall_img = load_texture(game.mlx, "textures/wall_64x64.xpm");
//     game.back_img = load_texture(game.mlx, "textures/grass.xpm");
//     game.player_img = load_texture(game.mlx, "textures/naruto2.xpm");
//     game.collect_img = load_texture(game.mlx, "textures/ramen.xpm");
//     game.exit_img = load_texture(game.mlx, "textures/porta.xpm");

//     // Aggiungi controlli per evitare segfault
//     if (!game.wall_img || !game.back_img || !game.collect_img || !game.exit_img)
//     {
//         printf("Errore: una o più immagini non sono state caricate correttamente.\n");
//         return (1);
//     }

//     // Disegna la mappa
//     render_map(&game);

//     mlx_loop(game.mlx);
//     return (0);
// }
