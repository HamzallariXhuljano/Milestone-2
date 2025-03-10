/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:42:02 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/06 14:01:36 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap	*fft_lstnew(int content)
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

	while (swap)
	{
		tmp = swap;
		swap = swap->next;
		free(tmp);
	}
}

void	free_one(t_swap **swap)
{
	t_swap	*tmp;

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
		if (tmp->next == NULL)
		{
			ft_printf("%d\n", tmp -> content);
			break ;
		}
		ft_printf("%d--", tmp -> content);
		tmp = tmp -> next;
	}
}

t_swap	*lastnode(t_swap **swap)
{
	t_swap	*tmp;

	if (!swap || !*swap)
		return (NULL);
	tmp = *swap;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
