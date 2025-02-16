/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:03:31 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/16 16:00:02 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Function to create a new node
t_swap *fft_lstnew(int content)
{
	t_swap *newnode;

	newnode = (t_swap *)malloc(sizeof(t_swap));
	if (newnode == NULL)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

// Function to free the entire list
void free_list(t_swap *swap)
{
	t_swap *tmp;

	while (swap)
	{
		tmp = swap;
		swap = swap->next;
		free(tmp);
	}
}

// Function to print the list
void print_lst(t_swap *swap)
{
	t_swap *tmp;
	tmp = swap;
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			ft_printf("%d\n", tmp->content);
			break;
		}
		ft_printf("%d--", tmp->content);
		tmp = tmp->next;
	}
}

// Function to find the last node in the list
t_swap *lastnode(t_swap **swap)
{
	t_swap *tmp;

	tmp = *swap;
	if (!tmp || !tmp->next)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

// Function to find the second last node in the list
t_swap *lastnode1(t_swap **swap)
{
	t_swap *tmp;

	tmp = *swap;
	if (!tmp || !tmp->next)
		return (NULL);
	while (tmp->next->next)
		tmp = tmp->next;
	return (tmp);
}

// Function to calculate the size of the list
int fft_lstsize(t_swap *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// Function to find the correct position in stack a for an element from stack b
int index_a(t_swap *a, int n)
{
	int i = 0;
	int insert_index = 0;
	t_swap *tmp = a;
	t_swap *min = a;
	t_swap *max = a;

	if (!a)
		return (0);

	// Find min and max elements in stack A
	while (tmp)
	{
		if (tmp->content < min->content)
			min = tmp;
		if (tmp->content > max->content)
			max = tmp;
		tmp = tmp->next;
	}

	// If n is smaller than min OR greater than max, insert after max (before min)
	if (n < min->content || n > max->content)
	{
		tmp = a;
		while (tmp->content != max->content)
		{
			insert_index++;
			tmp = tmp->next;
		}
		return (insert_index + 1); // Insert after max
	}

	// Find the correct sorted position (first element greater than n)
	i = 0;
	tmp = a;
	while (tmp->next)
	{
		if (tmp->content < n && tmp->next->content > n)
			return (i + 1);
		i++;
		tmp = tmp->next;
	}

	return (i + 1);
}







