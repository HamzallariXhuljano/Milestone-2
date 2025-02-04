/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:19:10 by xhamzall          #+#    #+#             */
/*   Updated: 2025/02/04 19:01:48 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_swap	*fft_lstnew(int	content)
{
	t_swap	*new;

	new = malloc (sizeof(t_swap));
	if (!new)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}
int	sa(t_swap *swap)
{
	int temp;
	if (!swap || !swap->next)
		return (-1);
	temp = swap -> content;
	swap -> content = swap -> next -> content;
	swap -> next -> content = temp;
	return (1);
}
int	sb(t_swap *swap)
{
	int temp;
	if (!swap || !swap->next)
		return (-1);
	temp = swap -> content;
	swap -> content = swap -> next -> content;
	swap -> next -> content = temp;
	return (1);
}
int	ss(t_swap *a, t_swap *b)
{
	if ((sa(a) && sb(b)) == 1)
		return (1);
	else
		return (-1);
}
int	pa(t_swap *a, t_swap *b)
{
	tem
}
// Libera tutta la memoria della lista
void	free_list(t_swap *head)
{
	t_swap *temp;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
void	print_lst(t_swap *swap)
{
	t_swap *temp;
	temp = swap;
	while (temp)
	{
		if (temp -> next == NULL)
		{
			ft_printf("%d\n", temp -> content);
			break;
		}
		ft_printf("%d--", temp -> content);
		temp = temp -> next;
	}
}

int main()
{
	t_swap	*head = fft_lstnew(1);
	t_swap	*h2 = fft_lstnew(2);
	t_swap	*h3 = fft_lstnew(3);
	t_swap	*h4 = fft_lstnew(4);
	head -> next = h2;
	h2 -> next = h3;
	h3 -> next = h4;

	t_swap	*head2 = fft_lstnew(5);
	t_swap	*h22 = fft_lstnew(6);
	t_swap	*h32 = fft_lstnew(7);
	t_swap	*h42 = fft_lstnew(8);
	head2 -> next = h22;
	h22 -> next = h32;
	h32 -> next = h42;

	sa(head);
	sb(head2);

	print_lst(head);
	print_lst(head2);
	ft_printf("Dopo ss\n");
	ss(head, head2);
	print_lst(head);
	print_lst(head2);
	free_list(head);
	free_list(head2);
}
