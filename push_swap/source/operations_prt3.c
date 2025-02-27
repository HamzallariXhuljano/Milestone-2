/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_prt3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:41:18 by xhamzall          #+#    #+#             */
/*   Updated: 2025/02/25 14:41:21 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_swap **swap, int i)
{
	t_swap	*last;
	t_swap	*nlast;

	if(!*swap|| !swap || !(*swap)->next)
		return (-1);
	last = lastnode(swap);
	nlast = lastnode1(swap);
	last->next = *swap;
	nlast->next = NULL;
	*swap = last;
	// g_move_count++;
	if (i == 1)
		ft_printf("rra\n");
	return(1);
}

int	rrb(t_swap **swap, int i)
{
	t_swap	*last;
	t_swap	*nlast;

	if(!*swap|| !swap || !(*swap)->next)
		return (-1);
	last = lastnode(swap);
	nlast = lastnode1(swap);
	last->next = *swap;
	nlast->next = NULL;
	*swap = last;
	// g_move_count++;
	if (i == 1)
		ft_printf("rrb\n");
	return(1);
}

int	rrr(t_swap **a, t_swap **b, int i)
{
	// g_move_count--;
	if((rra(a, 0) != 1) || (rrb(b, 0) != 1))
		return(-1);
	else
	{
		if (i == 1)
			ft_printf("rrr\n");
		return (1);
	}
}

