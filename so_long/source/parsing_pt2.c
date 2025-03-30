/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pt2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 07:37:49 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/30 18:49:40 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_c(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map -> collectibles = 0;
	while (map -> grid[i])
	{
		j = 0;
		while (map -> grid[i][j])
		{
			if (map -> grid[i][j] == 'C')
				map -> collectibles++;
			j++;
		}
		i++;
	}
	if (map -> collectibles != 0)
		return (map -> collectibles);
	return (-1);
}

char	**dup_map(char *file, t_map *map)
{
	int		i;

	i = 0;
	map -> new_map = malloc((count_line(file, map) + 1) * sizeof(char *));
	if (!map->new_map)
		return (free_matrix(map->new_map), NULL);
	while (i < count_line(file, map))
	{
		map->new_map[i] = ft_strdup(map -> grid[i]);
		if (!map->new_map[i])
			return (free_matrix(map->new_map), NULL);
		i++;
	}
	map->new_map[i] = NULL;
	return (map->new_map);
}

void	find_pos(t_map *map)
{
	int	x;
	int	y;

	if (!map || !map->grid)
		return ;
	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map -> grid[y][x] == 'P')
			{
				map -> play_x = x;
				map -> play_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	valid_pos(size_t x, size_t y, t_map *map)
{
	if ((x >= map -> width) || (y >= map -> height))
		return (-1);
	if (map->new_map[y][x] == '1' || map->new_map[y][x] == 'X')
		return (-1);
	if (map->new_map[y][x] == 'E')
	{
		map -> exit = 1;
		return (-1);
	}
	return (0);
}

int	sign(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map -> grid[i])
	{
		j = 0;
		while (map -> grid[i][j])
		{
			if (map -> grid[i][j] == 'C' || map -> grid[i][j] == 'E' || \
				map -> grid[i][j] == 'P' || map -> grid[i][j] == '1' || \
				map -> grid[i][j] == '0' || map -> grid[i][j] == '\n')
				j++;
			else
				return (-1);
		}
		i++;
	}
	if (map -> collectibles != 0)
		return (map -> collectibles);
	return (-1);
}
