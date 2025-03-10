/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:41:41 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/10 17:06:32 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_args(t_swap **a)
{
	if ((*a)->content > (*a)->next->content \
		&& (*a)->next->content > (*a)->next->next->content)
	{
		sa(*a, 1);
		rra(a, 1);
	}
	else if ((*a)->next->content > (*a)->content \
		&& (*a)->content > (*a)->next->next->content)
		rra(a, 1);
	else if ((*a)->content > (*a)->next->next->content
		&& (*a)->next->next->content > (*a)->next->content)
		ra(a, 1);
	else if ((*a)->next->content > (*a)->next->next->content
		&& (*a)->next->next->content > (*a)->content)
	{
		sa(*a, 1);
		ra(a, 1);
	}
	else if ((*a)->next->next->content > (*a)->content \
		&& (*a)->content > (*a)->next->content)
		sa (*a, 1);
}

int	is_sorted(t_swap **a, t_swap **b)
{
	t_swap	*tmp;

	if (b)
		return 0;
	tmp = *a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	two_check(t_swap **a)
{
	t_swap	*tmp;

	tmp = *a;
	if (tmp->content > tmp->next->content)
		sa(*a, 1);
}

void	push_all(t_swap **a, t_swap **b, t_data *d)
{
	while (*b)
	{
		best_element(a, b, d);
		movement(a, b, d);
	}
}
