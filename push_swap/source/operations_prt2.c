/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_prt2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:41:05 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/04 15:51:33 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_swap **swap, int i)
{
	t_swap	*last;
	t_swap	*first;

	if (!*swap || !swap || !(*swap)->next)
		return (-1);
	first = *swap;
	*swap = (*swap)->next;
	first->next = NULL;
	last = lastnode(swap);
	last->next = first;
	if (i == 1)
		ft_printf("ra\n");
	return (1);
}

int	rb(t_swap **swap, int i)
{
	t_swap	*last;
	t_swap	*first;

	if (!*swap || !swap || !(*swap)->next)
		return (-1);
	first = *swap;
	*swap = (*swap)->next;
	first->next = NULL;
	last = lastnode(swap);
	last->next = first;
	if (i == 1)
		ft_printf("rb\n");
	return (1);
}

int	rr(t_swap **a, t_swap **b, int i)
{
	if ((ra(a, 0) != 1) || (rb(b, 0) != 1))
		return (-1);
	else
	{
		if (i == 1)
			ft_printf("rr\n");
		return (1);
	}
}
