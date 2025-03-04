/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:42:23 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/04 03:51:56 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

int	cal_index(t_swap *a, int n, int size)
{
	int		i;
	t_swap	*tmp;

	tmp = a;
	i = 0;
	while (tmp)
	{
		if (tmp->content == n && i <= size / 2)
			return (i);
		else if (tmp->content == n && i > size / 2)
			return (i - size);
		i++;
		tmp = tmp->next;
	}
	return(-555);
}

void	free_mat(char **matrix)
{
	int	i;

	i = 0;
	if (matrix == NULL)
		return (free(matrix));
	while (matrix[i] != NULL)
		i++;
	if (matrix[i] == NULL)
		i--;
	while (i >= 0)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
	return ;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	**matrix_creation(int ac, char **av, int i)
{
	char	**matrix;
	int	j;

	if(!av[1] || !av[1][0] || ((av[1][0] == '-' || av[1][0] == '+') &&!(av[1][1] >= '0' && av[1][1] <= '9')))
		return(NULL);
	j = 0;
	while(!(av[1][j] >= '0' && av[1][j] <= '9'))
	 	j++;
	if(!av[1][j])
		return (NULL);
	if (ac == 2)
	{
		matrix = two_args(av[1], i);
	}
	else
		matrix = more_args(ac, av, i);
	return (matrix);
}

