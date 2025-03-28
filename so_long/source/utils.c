/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:01:17 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/28 22:48:13 by xhamzall         ###   ########.fr       */
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
		ft_printf("GG YOU WIN!!!\n");
		close_window(game);
	}
}
int	check_img(char *file)
{
	int		fd;
	size_t	len;

	if (!file || ft_strlen(file) < 4)
		return (-1);
	len = ft_strlen(file) - 4;// .ber
	if (ft_strncmp(file + len,  ".xpm", 4) != 0)
		return (-1);
	fd = open(file, O_RDONLY);
	if(fd < 0 )
		return (-1);
	return (fd);
}
int close_window(t_game *game)
{
    //free_resources(game);
	destroy_img(game);
    exit(0);
    return (0);
}
