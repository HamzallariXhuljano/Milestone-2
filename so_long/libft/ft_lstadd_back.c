/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:06:26 by xhamzall          #+#    #+#             */
/*   Updated: 2024/12/01 18:45:45 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp -> next = new;
}
// int main()
// {
// 	t_list	*head = ft_lstnew("ciao");
// 	t_list	*second = ft_lstnew("come");
// 	t_list	*add_last = ft_lstnew("stai?");
// 	t_list	*temp = NULL;

// 	head -> next = second;
// 	temp = head;

// 	while (temp)
// 	{
// 		printf("%s\n", (char *)temp -> content);
// 		temp = temp -> next;
// 	}

// 	temp = head;
// 	ft_lstadd_back(&temp, add_last);

// 	while(temp)
// 	{
// 		printf("%s\n", (char *) temp -> content);
// 		temp = temp -> next;
// 	}

// }
