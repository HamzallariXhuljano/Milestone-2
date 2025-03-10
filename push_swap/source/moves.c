/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:40:58 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/04 15:52:47 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_a(t_swap *a, int b)
{
	t_swap	*tmp;
	int		pos_a;

	tmp = a;
	while (tmp)
	{
		if (tmp->next)
		{
			if (b > tmp->content && b < tmp->next->content)
			{
				pos_a = cal_index(a, tmp->next->content, fft_lstsize(a));
				break ;
			}
		}
		else if (b > tmp->content && b < a->content)
		{
			pos_a = cal_index(a, a->content, fft_lstsize(a));
			break ;
		}
		tmp = tmp->next;
	}
	if (!tmp)
		pos_a = cal_index(a, smallest(a), fft_lstsize(a));
	return (pos_a);
}

int	moves_b(t_swap *b, int i)
{
	int		moves;
	int		size_b;

	moves = 0;
	size_b = fft_lstsize(b) + i;
	if (i <= size_b / 2)
		moves = i;
	else if (i < size_b)
		moves = i - size_b;
	return (moves);
}

void	store_data(int total, int count_a, int count_b, t_data *d)
{
	d->count_a = count_a;
	d->count_b = count_b;
	d->total = ft_abs(total);
}

void	total_moves(t_swap *a, t_swap *b, int pos, t_data *d)
{
	int	total;
	int	count_a;
	int	count_b;

	count_a = moves_a(a, b->content);
	count_b = moves_b(b, pos);
	if (count_a >= 0 && count_b >= 0)
	{
		if (count_a > count_b)
			total = count_a;
		else
			total = count_b;
	}
	else if (count_a < 0 && count_b < 0)
	{
		if (count_a < count_b)
			total = count_a;
		else
			total = count_b;
	}
	else
		total = ft_abs(count_a) + ft_abs(count_b);
	if (d->total > ft_abs(total))
		store_data(total, count_a, count_b, d);
}

void	best_element(t_swap **a, t_swap **b, t_data *d)
{
	int		i;
	t_swap	*tmp;

	d->total = INT_MAX;
	d->count_a = 0;
	d->count_b = 0;
	tmp = *b;
	i = 0;
	while (tmp)
	{
		total_moves(*a, tmp, i, d);
		i++;
		tmp = tmp->next;
	}
}
