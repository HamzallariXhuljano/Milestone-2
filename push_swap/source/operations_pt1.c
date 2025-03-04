/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_pt1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:41:26 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/04 15:48:27 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int g_move_count = 0;

int	sa(t_swap *swap, int i)
{
	int	tmp;

	if (!swap || !swap->next)
		return (-1);
	tmp = swap->next->content;
	swap->next->content = swap->content;
	swap->content = tmp;
	if (i == 1)
		ft_printf("sa\n");
	return (1);
}

int	sb(t_swap *swap, int i)
{
	int	tmp;

	if (!swap || !swap->next)
		return (-1);
	tmp = swap->next->content;
	swap->next->content = swap->content;
	swap->content = tmp;
	if (i == 1)
		ft_printf("sb\n");
	return (1);
}

int	ss(t_swap *a, t_swap *b, int i)
{
	if ((sa(a, 0) == 1) && (sb(b, 0) == 1))
	{
		if (i == 1)
			ft_printf("ss\n");
		return (1);
	}
	else
		return (-1);
}

int	pa(t_swap **a, t_swap **b, int i)
{
	t_swap	*tmp;

	if (!b || !*b)
		return (-1);
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	if (i == 1)
		ft_printf("pa\n");
	return (1);
}

int	pb(t_swap **a, t_swap **b, int i)
{
	t_swap	*tmp;

	if (!a || !*a)
		return (-1);
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (i == 1)
		ft_printf("pb\n");
	return (1);
}
