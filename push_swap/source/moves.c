/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:30:58 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/14 16:10:07 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to calculate the number of moves required for stack a
int moves_a(t_swap *a, int pos_a)
{
    int ls_size;

    ls_size = fft_lstsize(a);
    if (pos_a > (ls_size / 2))
        return (ls_size - pos_a);
    return (pos_a);
}

// Function to calculate the number of moves required for stack b
int moves_b(t_swap *b, int i)
{
    int ls_size;

    ls_size = fft_lstsize(b);
    if (i > (ls_size / 2))
        return (ls_size - i);
    return (i);
}

// Function to calculate the total number of moves required
int total_moves(t_swap *a, t_swap *b, int pos)
{
    int count_a;
    int count_b;
    int pos_a;
    int size_a;
    int size_b;

    size_a = fft_lstsize(a);
    size_b = fft_lstsize(b);
    pos_a = index_a(a, b->content);
    count_a = moves_a(a, pos_a);
    count_b = moves_b(b, pos);

    if (((pos < (size_b / 2)) && (pos_a < (size_a / 2))) || ((pos >= (size_b / 2)) && (pos_a >= (size_a / 2))))
    {
        if (count_a > count_b)
            return (count_a);
        return (count_b);
    }
    else
        return (count_a + count_b);
}

// Function to find the best element in stack b to push to stack a
int best_element(t_swap *a, t_swap *b)
{
    int i;
    int min_move;
    int moves;
    int index;
    t_swap *tmp;

    tmp = b;
    min_move = INT_MAX; // Use INT_MAX instead of hardcoded value
    index = 0;
    i = 0;
    while (tmp)
    {
        moves = total_moves(a, tmp, i);
        if (moves < min_move)
        {
            min_move = moves;
            index = i;
        }
        i++;
        tmp = tmp->next;
    }
    return (index);
}

void rr_movement(t_swap **a, t_swap **b, t_data *d)
{
    while (d->pos_a > 0 && d->index > 0 && d->pos_a < d->size_a / 2 && d->index < d->size_b / 2)
    {
        rr(a, b);
        d->pos_a--;
        d->index--;
    }
}

void rrr_movement(t_swap **a, t_swap **b, t_data *d)
{
    while (d->index < d->size_b && d->pos_a < d->size_a)
    {
        rrr(a, b);
        d->index++;
        d->pos_a++;
    }
}

// Function to move elements in stack b to the correct position
void movement_b(t_swap **b, int index)
{
    int size;

    size = fft_lstsize(*b);
    if (index == 0)
        return;
    if (index >= (size / 2))
    {
        while (index < size)
        {
            rrb(b);
            index++;
        }
    }
    else
    {
        while (index > 0)
        {
            rb(b);
            index--;
        }
    }
}

// Function to move elements in stack a to the correct position
void movement_a(t_swap **a, int pos_a)
{
    int size;

    size = fft_lstsize(*a);
    if (pos_a == 0)
        return;

    if (pos_a <= size / 2)
    {
        while (pos_a > 0)
        {
            ra(a);
            pos_a--;
        }
    }
    else
    {
        while (pos_a < size)
        {
            rra(a);
            pos_a++;
        }
    }
}

// Function to move elements in both stacks a and b
void movement(t_swap **a, t_swap **b, t_data *d)
{
    t_swap *tem;
    int tmp;

    d->size_a = fft_lstsize(*a);
    d->size_b = fft_lstsize(*b);
    tmp = d->index;
    tem = *b;

    while (tmp > 0 && tem)
    {
        tem = tem->next;
        tmp--;
    }

    if (!tem)
    {
        d->pos_a = 0;
        return;
    }

    d->pos_a = index_a(*a, tem->content);

    // Rotate both stacks if possible
    if ((d->index < (d->size_b / 2)) && (d->pos_a < (d->size_a / 2)))
        rr_movement(a, b, d);
    else if ((d->index > (d->size_b / 2)) && (d->pos_a > (d->size_a / 2)))
        rrr_movement(a, b, d);

    // Move stack b
    movement_b(b, d->index);
    // Move stack a
    movement_a(a, d->pos_a);

    // Push the element from stack b to stack a
    pa(a, b);
}

// Function to push all elements from stack b to stack a
void push_all(t_swap **a, t_swap **b)
{
    t_data d;

    while (*b)
    {
        d.index = best_element(*a, *b);
        movement(a, b, &d);
    }
}

// Function to push all but two elements from stack a to stack b
void pb_only_two_a(t_swap **a, t_swap **b)
{
    while (*a && (*a)->next && (*a)->next->next)
    {
        pb(a, b);
    }
}

int	main(void)
{
	t_swap *head = fft_lstnew(89);
	t_swap *h2 = fft_lstnew(104);


	t_swap *h3 = fft_lstnew(94);
	t_swap *h4 = fft_lstnew(52);
	t_swap *h5 = fft_lstnew(105);
	t_swap *h6 = fft_lstnew(90);
	t_swap *h7 = fft_lstnew(60);
	t_swap *h8 = fft_lstnew(123);
	t_swap *h9 = fft_lstnew(211);
	t_swap *h10 = fft_lstnew(315);
	t_swap *h11 = fft_lstnew(400);
	t_swap *h12 = fft_lstnew(5);
	t_swap *h13 = fft_lstnew(15);
	t_swap *h14 = fft_lstnew(2);
	t_swap *h15 = fft_lstnew(199);
	t_swap *h16 = fft_lstnew(278);
	t_swap *h17 = fft_lstnew(120);
	t_swap *h18 = fft_lstnew(7);
	t_swap *h19 = fft_lstnew(99);
	t_swap *h20 = fft_lstnew(56);

	t_swap *head2 = fft_lstnew(4);

	head->next = h2;
    head2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;
    h6->next = h7;
    h7->next = h8;
    h8->next = h9;
    h9->next = h10;
    h10->next = h11;
    h11->next = h12;
    h12->next = h13;
    h13->next = h14;
    h14->next = h15;
    h15->next = h16;
    h16->next = h17;
    h17->next = h18;
    h18->next = h19;
    h19->next = h20;

	pb_only_two_a(&head, &head2);
	ft_printf("Before\n");
	print_lst(head);
	ft_printf("\n");
	print_lst(head2);
	ft_printf("After\n");
	push_all(&head, &head2);
	print_lst(head);
	ft_printf("\n");
	print_lst(head2);
	free_list(head2);
	free_list(head);
}
// if(*a && (*a)->next)
// 	{
// 		if((*a) -> content > (*a)-> next -> content)
// 			sa(*a);
// 	}
