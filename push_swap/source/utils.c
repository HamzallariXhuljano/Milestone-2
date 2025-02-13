/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:03:31 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/12 22:48:49 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap	*fft_lstnew(int	content)
{
	t_swap	*newnode;

	newnode = (t_swap *)malloc(sizeof(t_swap));
	if (newnode == NULL)
		return (NULL);
	newnode -> content = content;
	newnode -> next = NULL;
	return (newnode);
}
void	free_list(t_swap *swap)
{
	t_swap	*tmp;

	while(swap)
	{
		tmp = swap;
		swap = swap->next;
		free(tmp);
	}
}
void	free_one(t_swap **swap)
{
	t_swap *tmp;

	if (swap && *swap)
	{
		tmp = *swap;
		*swap = tmp->next;
		free(tmp);
	}
}

void	print_lst(t_swap *swap)
{
	t_swap	*tmp;
	tmp = swap;
	while (tmp)
	{
		if(tmp->next == NULL)
		{
			ft_printf("%d\n",tmp -> content);
			break;
		}
		ft_printf("%d--",tmp -> content);
		tmp = tmp -> next;
	}
}

t_swap	*lastnode(t_swap **swap)
{
	t_swap	*tmp;

	tmp = *swap;
	if(!tmp || !tmp->next)
		return (NULL);
	while(tmp->next)
		tmp = tmp->next;
	return(tmp);
}

t_swap	*lastnode1(t_swap **swap)
{
	t_swap	*tmp;

	tmp = *swap;
	if(!tmp || !tmp->next)
		return (NULL);
	while(tmp->next->next)
		tmp = tmp->next;
	return(tmp);
}
int	fft_lstsize(t_swap *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

void	swap_conent(int *a, int *b)
{
	int	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

int	index_a(t_swap *a, int n)
{
	int		i;
	int		max_index;
	t_swap	*tmp;
	t_swap	*min_node;
	t_swap	*max_node;

	if (!a)
		return (0);

	i = 0;
	tmp = a;
	max_index = 0;
	min_node = a;
	max_node = a;

	// Trova i nodi con il valore minimo e massimo
	while (tmp)
	{
		if (tmp->content < min_node->content)
		{
			min_node = tmp;
		}
		if (tmp->content > max_node->content)
		{
			max_node = tmp;
			max_index = i;
		}
		// Trova la posizione corretta tra due numeri adiacenti
		if (tmp->next && tmp->content < n && tmp->next->content > n)
			return (i + 1);
		i++;
		tmp = tmp->next;
	}

	// Se `n` è più grande di tutti, inserirlo dopo il massimo
	if (n > max_node->content)
		return (max_index + 1);

	// Se `n` è più piccolo di tutti, inserirlo in prima posizione
	return (0);
}



