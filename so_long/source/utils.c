/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:01:17 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/27 15:24:32 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix (char **mat)
{
	int	i;

	i = 0;
	if (!mat)
	{
		return ;
	}
	while(mat[i])
	{
		free(mat[i]);
		i ++;
	}
	free (mat);
}

int	chek_move(t_game *game, size_t new_x, size_t new_y)
{
	if (!game || !game->map.grid)
		return (-1);
	if (new_x >= game->map.width || new_y >= game->map.height)
		return (-1);
	if (game->map.grid[new_y] == NULL)
		return (-1);
	return (0);
}

void	win_exit(t_game *game)
{
	if(game->map.collectibles == 0)
	{
		ft_printf("GG\n");
		close_window(game);
	}
}
