/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pt3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:13:11 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/31 12:56:18 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	back_tracking(int x, int y, t_map *map)
{
	if (valid_pos(x, y, map) != 0)
		return (1);
	if (map -> new_map[y][x] == 'C')
		map-> cnt_coll += 1;
	map -> new_map[y][x] = 'X';
	if (valid_pos((x + 1), y, map) == 0)
		back_tracking((x + 1), y, map);
	if (valid_pos((x - 1), y, map) == 0)
		back_tracking((x - 1), y, map);
	if (valid_pos(x, (y + 1), map) == 0)
		back_tracking(x, (y + 1), map);
	if (valid_pos(x, (y - 1), map) == 0)
		back_tracking(x, (y - 1), map);
	return (0);
}

int	validate_map(char *file, t_map *map)
{
	map -> new_map = NULL;
	if (!dup_map(file, map))
		return (write(2, "Error\n", 6), -1);
	find_pos(map);
	map ->cnt_coll = 0;
	map -> exit = 0;
	back_tracking(map->play_x, map->play_y, map);
	if ((map -> collectibles == map -> cnt_coll) && (map -> exit == 1))
		return (free_matrix(map -> new_map), map ->new_map = NULL, 0);
	else
		return (free_matrix(map -> new_map), map ->new_map = NULL, -1);
	free_matrix(map -> new_map);
	map -> new_map = NULL;
	return (0);
}

int	chack_all(char *file, t_map *map)
{
	if (count_line(file, map) == -1)
		return (-1);
	if (read_map(file, map) == NULL)
		return (write(2, "Error\n", 6), free_matrix(map->grid), -1);
	if (check_wall(map) == -1)
		return (write(2, "Error\n", 6), free_matrix(map->grid), -1);
	if (check_c(map) == -1)
		return (write(2, "Error\n",6), free_matrix(map->grid), -1);
	if (check_pe(map) == -1)
		return (write(2, "Error\n", 6), free_matrix(map->grid), -1);
	if (sign(map) == -1)
		return (write(2, "Error\n", 6), free_matrix(map->grid), -1);
	if (validate_map(file, map) == -1)
		return (write(2, "Error\n", 6), free_matrix(map->grid), -1);
	return (0);
}
// int main(int ac, char **av)
// {
//     t_map map;
//     int num_line;

//     if (ac < 2)
//         return (1);

//     num_line = count_line(av[1], &map);
//     if (num_line == -1)
//         return (-1);

//     if (chack_all(av[1], &map) == -1)
//     {
//         return (-1); // map.grid is already freed in chack_all
//     }

//     ft_printf("Line = %d\n", num_line);
//     ft_printf("PE= %d\n", check_pe(&map));
//     ft_printf("C= %d\n", map.collectibles);

//     ft_printf("Cnt_exit= %d\n", map.exit);
//     ft_printf("Cnt_coll= %d\n", map.cnt_coll);
//     fflush(stdout);

//     // Free the grid at the end of the program
//     free_matrix(map.grid);
//     return (0);
// }
