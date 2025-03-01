/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:41:34 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/01 16:17:40 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char **matrix)
{
	int	i;
	int	j;

	j = 0;
	while (matrix[j])
	{
		i = 0;
		if (matrix[j][i] == '+' || matrix[j][i] == '-')
			i++;
		while (matrix[j][i])
		{
			if(matrix[j][i] >= '0' && matrix[j][i] <= '9')
				i++;
			else
			{
				write(2, "ERROR\n", 6);
				return(0);
			}
		}
		j++;
	}
	return (1);
}
int	duplicates(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = i + 1;
		while (matrix[j])
		{
			if (ft_atoi(matrix[i]) == ft_atoi(matrix[j]))
			{
				write(2, "ERROR\n", 6);
				return(0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
char	**two_args(char *argv)
{
	char	**matrix;

	matrix = ft_split(argv, 32);
	if (check_arg(matrix) == 0 || duplicates(matrix) == 0)
		return (free_mat(matrix), NULL);
	return (matrix);
}
char	**more_args(int argc, char **av)
{
	int	j;
	int	i;
	char	**matrix;

	i = 1;
	j = 0;
	matrix = malloc((argc) * sizeof(char *));
	if (!matrix)
		return (NULL);
	while (i < argc)
	{
		matrix[j] = ft_strdup(av[i]);
		if (!matrix[j])
			return (free_mat(matrix), NULL);
		i++;
		j++;
	}
	matrix[j] = NULL;
	if (check_arg(matrix) == 0 || duplicates(matrix) == 0)
		return (free_mat(matrix), NULL);
	return(matrix);
}

t_swap	*lstcreation(char **matrix)
{
	int		i;
	long	check;
	t_swap	*new_node;
	t_swap	*head;

	i = 0;
	new_node = NULL;
	while (matrix[i])
	{
		check = ft_atoi(matrix[i]);
		if (check > INT_MAX || check < INT_MIN)
			return (free_mat(matrix), free_list(head), NULL);
		new_node = fft_lstnew((int)check);
		if (!new_node)
			return(free_mat(matrix), free_list(head), NULL);
		if (i == 0)
			head = new_node;
		else
			fft_lstadd_back(&head, new_node);
		i++;
	}
	free_mat(matrix);
	return (head);
}

