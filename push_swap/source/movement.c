/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:40:44 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/04 15:53:47 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	movement_a(t_swap **a, t_data *d)
{
	while (d->count_a > 0)
	{
		ra(a, 1);
		d->count_a--;
	}
	while (d->count_a < 0)
	{
		rra(a, 1);
		d->count_a++;
	}
}

void	movement_b(t_swap **b, t_data *d)
{
	while (d->count_b > 0)
	{
		rb(b, 1);
		d->count_b--;
	}
	while (d->count_b < 0)
	{
		rrb(b, 1);
		d->count_b++;
	}
}

void	movement(t_swap **a, t_swap **b, t_data *d)
{
	while (d->count_a != 0 && d->count_b != 0)
	{
		if (d->count_a > 0 && d->count_b > 0)
		{
			rr(a, b, 1);
			d->count_a--;
			d->count_b--;
		}
		else if (d->count_a < 0 && d->count_b < 0)
		{
			rrr(a, b, 1);
			d->count_a++;
			d->count_b++;
		}
		else
			break ;
	}
	while (d->count_a != 0)
		movement_a(a, d);
	while (d->count_b != 0)
		movement_b(b, d);
	pa(a, b, 1);
}

void	final_rotation(t_swap **a)
{
	int	min;
	int	pos_min;

	min = smallest(*a);
	pos_min = cal_index(*a, min, fft_lstsize(*a));
	while (pos_min > 0)
	{
		ra(a, 1);
		pos_min--;
	}
	while (pos_min < 0)
	{
		rra(a, 1);
		pos_min++;
	}
}
