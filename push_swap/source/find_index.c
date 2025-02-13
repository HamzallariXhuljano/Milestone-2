/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:15:31 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/10 20:56:47 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* int	*int_a(t_swap *a)
{
	int	ls_size;
	int	*stack;
	int	i;

	i = 0;
	ls_size = fft_lstsize(a);
	stack = malloc((ls_size + 2) * sizeof(int));
	ft_bzero(stack, ls_size);
	while(a->next)
	{
		stack[i] = a->content;
		i++;
		a = a->next;
	}
	stack[i] = '\0';
	i++;
	stack[i] = '\0';
	return (stack);
}


void	sort_a(int n, int *stack)
{
	int	i;
	int	sorted;

	i = 0;
	sorted = 1;
	while(stack[i])
		i++;
	stack[i] = num;
	while(sorted != 0)
	{
		sorted = 0;
		i = 0;
		while(stack[i] && stack[i + 1])
		{
			if(stack[i] > stack[i + 1])
			{
				sorted = 1;
				swap(&stack[i], &stack[i + 1]);
			}
			i++;
		}
	}
}
int	index_a(t_swap *a, int n)
{
	int	i;
	int	*stack;

	i = 0;
	stack = int_a(a);
	sort_a(num, stack);
	while(stack[i])
	{
		if(stack[i] == num)
		{
			free(stack);
			return (i);
		}
		i++;
	}
	ft_printf("NUM NOT FOUND");
	free(stack);
	return(-1);
} */


/* int	main(void)
{
	t_swap	*head = fft_lstnew(3);
	t_swap	*h2 = fft_lstnew(2);
	t_swap	*h3 = fft_lstnew(1);
	t_swap	*h4 = fft_lstnew(4);
	t_swap	*h5 = fft_lstnew(8);
	t_swap	*h6 = fft_lstnew(5);
	t_swap	*h7 = fft_lstnew(9);
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
	// print_lst(head);
	// ft_printf("\n");
	// print_lst(head2);
	int	j = index_a(head, 5);
	ft_printf("%d", j);
	free_list(head2);
	free_list(head);
} */
