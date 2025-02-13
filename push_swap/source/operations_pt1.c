/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_pt1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:08:20 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/11 00:00:38 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_swap *swap)
{
	int	tmp;

	if(!swap || !swap->next)
		return (-1);
	tmp = swap->next->content;
	swap->next->content = swap->content;
	swap->content = tmp;
	ft_printf("sa\n");
	return (1);
}
int	sb(t_swap *swap)
{
	int	tmp;

	if(!swap || !swap->next)
		return (-1);
	tmp = swap->next->content;
	swap->next->content = swap->content;
	swap->content = tmp;
	ft_printf("sb\n");
	return (1);
}
int	ss(t_swap *a, t_swap *b)
{
	if((sa(a) == 1) && (sb(b) == 1))
	{
		ft_printf("ss\n");
		return(1);
	}
	else
		return (-1);
}
int	pa(t_swap **a, t_swap **b)
{
	if (!b || !*b)
		return(-1);
	t_swap	*tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	ft_printf("pa\n");
	return(1);
}
int	pb(t_swap **a, t_swap **b)
{
	if(!a || !*a)
	return(-1);
	t_swap	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	ft_printf("pb\n");
	return(1);
}
int	ra(t_swap **swap)
{
	t_swap	*last;
	t_swap	*first;

	if(!*swap|| !swap || !(*swap)->next)
		return (-1);
	first = *swap;
	*swap = (*swap)->next;
	first->next = NULL;
	last = lastnode(swap);
	last->next = first;
	ft_printf("ra\n");
	return(1);
}
int	rb(t_swap **swap)
{
	t_swap	*last;
	t_swap	*first;

	if(!*swap|| !swap || !(*swap)->next)
		return (-1);
	first = *swap;
	*swap = (*swap)->next;
	first->next = NULL;
	last = lastnode(swap);
	last->next = first;
	ft_printf("rb\n");
	return(1);
}
int	rr(t_swap **a, t_swap **b)
{
	if((ra(a) != 1) || (rb(b) != 1))
		return(-1);
	else
	{
		ft_printf("rr\n");
		return (1);
	}
}
int	rra(t_swap **swap)
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
	ft_printf("rra\n");
	return(1);
}
int	rrb(t_swap **swap)
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
	ft_printf("rrb\n");
	return(1);
}
int	rrr(t_swap **a, t_swap **b)
{
	if((rra(a) != 1) || (rrb(b) != 1))
		return(-1);
	else
	{
		ft_printf("rrr\n");
		return (1);
	}
}

/* int	main(void)
{
	t_swap	*head = fft_lstnew(3);
	t_swap	*h2 = fft_lstnew(2);
	t_swap	*h3 = fft_lstnew(1);
	t_swap	*h4 = fft_lstnew(4);
	t_swap	*h5 = fft_lstnew(8);
	t_swap	*h6 = fft_lstnew(5);
	t_swap	*h7 = fft_lstnew(6);
	t_swap	*h8 = fft_lstnew(7);

	t_swap	*head2 = fft_lstnew(0);
	t_swap	*h12 = fft_lstnew(0);
	t_swap	*h13 = fft_lstnew(0);
	t_swap	*h14 = fft_lstnew(0);
	t_swap	*h15 = fft_lstnew(0);
	t_swap	*h16 = fft_lstnew(0);
	t_swap	*h17 = fft_lstnew(0);
	t_swap	*h18 = fft_lstnew(0);

	head->next = h2;
	h2->next = h3;
	h3->next = h4;
	h4->next = h5;
	h5->next = h6;
	h6->next = h7;
	h7->next = h8;

	head2->next = h12;
	h12->next = h13;
	h13->next = h14;
	h14->next = h15;
	h15->next = h16;
	h16->next = h17;
	h17->next = h18;

	sa(head);
	//sb(head2);
	//ss(head, head2);
	//pa(&head, &head2);
	//pb(&head, &head2);
	//ra(&head);
	//rb(&head2);
	//rr(&head, &head2);
	//rra(&head);
	//rrr(&head, &head2);
	print_lst(head);
	ft_printf("\n");
	print_lst(head2);
	free_list(head2);
	free_list(head);
} */
