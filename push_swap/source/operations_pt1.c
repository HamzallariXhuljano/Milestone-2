/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_pt1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:08:20 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/18 19:48:50 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Scambia i primi due elementi di stack a
int sa(t_swap *swap)
{
    if (!swap || !swap->next)
        return (-1);
    int tmp = swap->next->content;
    swap->next->content = swap->content;
    swap->content = tmp;
    ft_printf("sa\n");
    count++;
    return (1);
}

// Scambia i primi due elementi di stack b
int sb(t_swap *swap)
{
    if (!swap || !swap->next)
        return (-1);
    int tmp = swap->next->content;
    swap->next->content = swap->content;
    swap->content = tmp;
    ft_printf("sb\n");
    count++;
    return (1);
}

// Scambia i primi due elementi di entrambi gli stack a e b
int ss(t_swap *a, t_swap *b)
{
    if (!a || !a->next || !b || !b->next)
        return (-1);
    int tmp;
    tmp = a->next->content;
    a->next->content = a->content;
    a->content = tmp;
    tmp = b->next->content;
    b->next->content = b->content;
    b->content = tmp;
    ft_printf("ss\n");
    count++;
    return (1);
}

// Sposta il primo elemento di b su a
int pa(t_swap **a, t_swap **b)
{
    if (!b || !*b)
        return (-1);
    t_swap *tmp = *b;
    *b = (*b)->next;
    tmp->next = *a;
    *a = tmp;
    ft_printf("pa\n");
    count++;
    return (1);
}

// Sposta il primo elemento di a su b
int pb(t_swap **a, t_swap **b)
{
    if (!a || !*a)
        return (-1);
    t_swap *tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
    ft_printf("pb\n");
    count++;
    return (1);
}

// Ruota stack a (shift up)
int ra(t_swap **swap)
{
    if (!swap || !*swap || !(*swap)->next)
        return (-1);
    t_swap *first = *swap;
    t_swap *last = lastnode(swap);
    *swap = (*swap)->next;
    first->next = NULL;
    last->next = first;
    ft_printf("ra\n");
    count++;
    return (1);
}

// Ruota stack b (shift up)
int rb(t_swap **swap)
{
    if (!swap || !*swap || !(*swap)->next)
        return (-1);
    t_swap *first = *swap;
    t_swap *last = lastnode(swap);
    *swap = (*swap)->next;
    first->next = NULL;
    last->next = first;
    ft_printf("rb\n");
    count++;
    return (1);
}

// Ruota entrambi gli stack a e b
int rr(t_swap **a, t_swap **b)
{
    if (ra(a) != 1 || rb(b) != 1)
        return (-1);
    ft_printf("rr\n");
    count++;
    return (1);
}

// Ruota all'indietro stack a (shift down)
int rra(t_swap **swap)
{
    if (!swap || !*swap || !(*swap)->next)
        return (-1);
    t_swap *last = lastnode(swap);
    t_swap *nlast = lastnode1(swap);
    nlast->next = NULL;
    last->next = *swap;
    *swap = last;
    ft_printf("rra\n");
    count++;
    return (1);
}

// Ruota all'indietro stack b (shift down)
int rrb(t_swap **swap)
{
    if (!swap || !*swap || !(*swap)->next)
        return (-1);
    t_swap *last = lastnode(swap);
    t_swap *nlast = lastnode1(swap);
    nlast->next = NULL;
    last->next = *swap;
    *swap = last;
    ft_printf("rrb\n");
    count++;
    return (1);
}

// Ruota all'indietro entrambi gli stack a e b
int rrr(t_swap **a, t_swap **b)
{
    if (!a || !b || !*a || !*b || !(*a)->next || !(*b)->next)
        return (-1);
    t_swap *last_a = lastnode(a);
    t_swap *nlast_a = lastnode1(a);
    nlast_a->next = NULL;
    last_a->next = *a;
    *a = last_a;
    t_swap *last_b = lastnode(b);
    t_swap *nlast_b = lastnode1(b);
    nlast_b->next = NULL;
    last_b->next = *b;
    *b = last_b;
    ft_printf("rrr\n");
    count++;
    return (1);
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
