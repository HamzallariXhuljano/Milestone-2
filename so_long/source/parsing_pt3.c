/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pt3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 07:37:49 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/18 18:04:43 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**dup_map(char *file, t_map *map)
{
	int		i;

	i = 0;
	map->new_map = malloc((count_line(file, map)+1) * sizeof(char *));
	if (!map->new_map)
		return (NULL);
	while (map->grid[i])
	{
		map->new_map[i] = ft_strdup(map -> grid[i]);
		if(!map->new_map[i])
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

	if(!map || !map->grid)
		return;
	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x]== 'P')
			{
				map-> play_x = x;
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

	if ((x > map-> width) || (y > map -> height))//possibile errore provare con -1
		return (-1);
	if(map->new_map[y][x] == '1' || map->new_map[y][x] == 'X')
		return (-1);
	return (0);
}

int	back_tracking(int x, int y, t_map *map)
{
	if (valid_pos(x, y, map) != 0)
		return (1);
	if(map -> new_map[y][x] == 'C')
		map-> cnt_coll += 1;
	if(map -> new_map[y][x] == 'E')
		map -> exit += 1;
	map -> new_map[y][x] = 'X';
	if(valid_pos((x + 1), y, map) == 0)
		back_tracking((x + 1), y, map);
	if(valid_pos((x - 1), y, map) == 0)
		back_tracking((x - 1), y, map);
	if(valid_pos(x, (y + 1), map) == 0)
		back_tracking(x , (y + 1), map);
	if(valid_pos(x, (y - 1), map) == 0)
		back_tracking(x, (y - 1 ), map);
	return(0);

}

int	validate_map(char *file, t_map *map)
{
	if(!dup_map(file, map))
		return (write(2, "Error: dup map\n", 15), -1);
	find_pos(map);
	map ->cnt_coll = 0;
	map-> exit = 0;
	back_tracking(map->play_x, map->play_y, map);
	if ((map -> collectibles == map -> cnt_coll) && (map -> exit == 1))
		return (free_matrix(map -> new_map), 0);
	else
	{
		write(2, "Error, backtraking\n", 19);
		return(free_matrix(map -> new_map), -1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_map map;
	int	num_line;

	if (ac < 2)
		return (1);
	num_line = count_line(av[1], &map);
	if (num_line == -1)
		return (-1);
	ft_printf("Line = %d\n", num_line);
	map.grid = read_map(av[1], &map);
	num_line = check_wall(&map);
	num_line = check_pe(&map);
	ft_printf("PE= %d\n", num_line);
	num_line = check_c(&map);
	ft_printf("C= %d\n", num_line);
	num_line = validate_map(av[1],&map);
	ft_printf("Valid= %d\n", num_line);
	ft_printf("Cnt_exit= %d\n", map.exit);
	ft_printf("Cnt_coll= %d\n", map.cnt_coll);
	fflush(stdout);
	free_matrix(map.grid);
}
