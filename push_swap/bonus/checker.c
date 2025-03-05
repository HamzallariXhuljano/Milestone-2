/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:42:45 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/05 17:02:23 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/push_swap.h"

int	operations(t_swap **a, t_swap **b, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa(*a, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(*b, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(*a, *b, 0);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(a, b, 0);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(a, b, 0);
	else
		return (write(2, "ERROR\n", 6), 0);
	return (1);
}

int	last(t_swap *a, int i)
{
	if (a && is_sorted(&a) == 1)
		return (ft_printf("OK\n"), 1);
	else if (is_sorted(&a) == 0 && i == 1)
		return (ft_printf("KO\n"), 0);
	return (0);
}

int	main(int ac, char **av)
{
	char	**matrix;
	char	*str;
	t_swap	*a;
	t_swap	*b;

	b = NULL;
	if (ac < 2)
		return (write(2, "ERROR\n", 6), 0);
	matrix = matrix_creation(ac, av, 1);
	if (matrix == NULL)
		return (0);
	a = lstcreation(matrix);
	if (!a)
		return (0);
	if (last(a, 0) == 1)
		return (free_list(a), 0);
	str = get_next_line(0);
	while (str)
	{
		if (operations(&a, &b, str) == 0)
			return (free_list(a), free_list(b), free(str), 0);
		free(str);
		str = get_next_line(0);
	}
	return (last(a, 1), free_list(a), free_list(b), free(str), 0);
}
