/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pt1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:19:41 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/18 13:35:10 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_open(char *file)
{
	int		fd;
	size_t	len;

	len = ft_strlen(file) - 4;// .ber
	if (ft_strncmp(file + len,  ".ber", 4) != 0)
		return (write(2, "Error\n", 6), -1);
	fd = open(file, O_RDONLY);
	if(fd < 0 )
		return (write(2, "Error\n", 6), -1);
	return (0);
}

int	count_line(char *file, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);

	map-> height = 0;
	line = get_next_line(fd);
	map -> width = ft_strlen(line);
	while (line != NULL)
	{
		if (map -> width != ft_strlen(line) && (line[0] != '\n'))
			return (write(2, "ErroR1\n", 7), free(line), close(fd), -1);
		if (line[0] != '\n')
			map-> height ++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (map->height);
}

char **read_map(char *file, t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	map -> grid = malloc(count_line(file, map) * sizeof(char *) + 1);
	if (!map -> grid)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		map -> grid[i] = ft_strdup(line);
		free (line);
		line = get_next_line(fd);
		i++ ;
	}
	map -> grid[i] = NULL;
	free(line);
	close (fd);
	return (map -> grid);
}
int	check_wall(t_map *map)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j] && map->grid[i][j] != '\n')
		{
			if (i == 0 && map->grid[i][j] != '1')
				return(write(2, "Error\n", 6), -1);
			if(j == 0 && map->grid[i][j] != '1')
				return(write(2, "Error\n", 6), -1);
			if((j == ft_strlen(map->grid[i])) && (map->grid[i][ft_strlen(map->grid[i])] != '1'))
				return(write(2, "Error\n", 6), -1);
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
	int e;

	i = 0;
	p = 0;
	e = 0;
	while (map -> grid[i])
	{
		j = 0;
		while (map -> grid[i][j])
		{
			if (map -> grid[i][j] == 'P')
				p = 1;
			if (map -> grid[i][j] == 'E')
				e = 1;
			if (e == 1 && p == 1)
				return (0);
			j++;
		}
		i++;
	}
	return (write(2, "Error\n", 6), -1);
}

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
	return (write(2, "Error\n", 6), -1);
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
			if (map -> grid[i][j] != 'C' || map -> grid[i][j] != 'E' ||
				map -> grid[i][j] != 'P' || map -> grid[i][j] != '1' ||
				map -> grid[i][j] != '0' || map -> grid[i][j] != '\n')
				return (write(2, "Error\n", 6)-1);
			j++;
		}
		i++;
	}
	if (map -> collectibles != 0)
		return (map -> collectibles);
	return (write(2, "Error\n", 6), -1);
}

/* int	main(int ac, char **av)
{
	t_map map;
	int	num_line;

	if (ac < 2)
		return (1);
	num_line = count_line(av[1], &map);
	if (num_line == -1)
		return (-1);
	ft_printf("Line=%d\n", num_line);
	map.grid = read_map(av[1], &map);
	num_line = check_wall(&map);
	num_line = check_pe(&map);
	ft_printf("P&E= %d\n", num_line);
	num_line = check_c(&map);
	ft_printf("C= %d\n", num_line);
} */
