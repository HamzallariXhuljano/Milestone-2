/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:40:58 by xhamzall          #+#    #+#             */
/*   Updated: 2025/02/25 14:41:01 by xhamzall         ###   ########.fr       */
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
				break;
			}
		}
		else if (b > tmp->content && b < a->content)
		{
			pos_a = cal_index(a, a->content, fft_lstsize(a));
			break;
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
	int	i;
	t_swap	*tmp;

	d->total = INT_MAX;
	d->count_a = 0;
	d->count_b = 0;
	tmp = *b;
	i = 0;
	while(tmp)
	{
		total_moves(*a, tmp, i, d);
		i++;
		tmp = tmp->next;
	}
}



// int	main(void)
// {
// 	t_swap	*head = fft_lstnew(89);
// 	t_swap	*h2 = fft_lstnew(104);
// 	// t_swap	*h3 = fft_lstnew(94);
// 	// t_swap	*h4 = fft_lstnew(52);
// 	// t_swap	*h5 = fft_lstnew(104);
// 	// t_swap	*h6 = fft_lstnew(90);
// 	// t_swap	*h7 = fft_lstnew(60);
// 	// t_swap	*h8 = fft_lstnew(82);

// 	t_swap	*head2 = fft_lstnew(1);
// 	t_swap	*h12 = fft_lstnew(44);
// 	t_swap	*h13 = fft_lstnew(60);
// 	t_swap	*h14 = fft_lstnew(99);

// 	head->next = h2;
// 	// h2->next = h3;
// 	// h3->next = h4;
// 	// h4->next = h5;
// 	// h5->next = h6;
// 	// h6->next = h7;
// 	// h7->next = h8;

// 	head2->next = h12;
// 	h12->next = h13;
// 	h13->next = h14;

// 	// sa(head);
// 	//sb(head2);
// 	//ss(head, head2);
// 	//pa(&head, &head2);
// 	//pb(&head, &head2);
// 	//ra(&head);
// 	//rb(&head2);
// 	//rr(&head, &head2);
// 	//rra(&head);
// 	//rrr(&head, &head2);
// 	ft_printf("Before\n");
// 	print_lst(head);
// 	ft_printf("\n");
// 	print_lst(head2);
// 	ft_printf("After\n");
// 	push_all(&head, &head2);
// 	print_lst(head);
// 	ft_printf("\n");
// 	print_lst(head2);
// 	free_list(head2);
// 	free_list(head);
// }
