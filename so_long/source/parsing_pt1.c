/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pt1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:19:41 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/29 17:46:58 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_open(char *file)
{
	int		fd;
	size_t	len;

	if (!file || ft_strlen(file) < 4)
		return (-1);
	len = ft_strlen(file) - 4;
	if (ft_strncmp(file + len, ".ber", 4) != 0)
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

int	count_line(char *file, t_map *map)
{
	int		fd;
	char	*line;

	if (check_open(file) < 0)
		return (write(2, "Error7\n", 7), -1);
	fd = open(file, O_RDONLY);
	map -> height = 0;
	line = get_next_line(fd);
	if (!line)
		return (write(2, "Error9\n", 7), close(fd), -1);
	map -> width = ft_strlen(line) -1;
	while (line)
	{
		if (map -> width != ft_strlen(line) - 1 && (line[0] != '\n'))
			return (write(2, "Error10\n", 8), free(line), close(fd), -1);
		if (line[0] != '\n')
			map-> height ++;
		else
			return (write(2, "Error11\n", 8), free(line), close(fd), -1);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (map->height);
}

char	**read_map(char *file, t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	map -> grid = malloc((count_line(file, map) + 1) * sizeof(char *));
	if (!map -> grid)
		return (free_matrix(map->grid), NULL);
	fd = check_open(file);
	if (fd < 0)
		return (free_matrix(map -> grid), write(2, "Error: open\n", 12), NULL);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		map -> grid[i] = ft_strdup(line);
		free (line);
		if (!map->grid[i])
			return (free_matrix(map -> grid), write(2, "Error1\n", 7), NULL);
		line = get_next_line(fd);
		i++ ;
	}
	map -> grid[i] = NULL;
	close (fd);
	return (map -> grid);
}

int	check_wall(t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = ft_strlen(map->grid[i]) - 2;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j] && map->grid[i][j] != '\n')
		{
			if ((i == 0) && map -> grid[i][j] != '1')
				return (-1);
			if ((i == map -> height - 1) && map->grid[i][j] != '1')
				return (-1);
			if (j == 0 && map -> grid[i][j] != '1')
				return (-1);
			if (((j == len) && (map -> grid[i][j] != '1')))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_pe(t_map *map)
{
	int	i;
	int	j;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	while (map -> grid[i])
	{
		j = 0;
		while (map -> grid[i][j])
		{
			if (map -> grid[i][j] == 'P')
				p++;
			if (map -> grid[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (e == 1 && p == 1)
		return (0);
	return (-1);
}
