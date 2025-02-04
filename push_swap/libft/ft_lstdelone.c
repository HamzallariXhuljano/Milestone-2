/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:26:01 by xhamzall          #+#    #+#             */
/*   Updated: 2024/12/01 18:07:27 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	del (lst -> content);
	free (lst);
}

// static void	del(void *content)
// {
// 	content = NULL;
// }

//  int main()
// {
// 	t_list *head = ft_lstnew("prova");
// 	t_list *second = ft_lstnew("da cancellare");

// 	head -> next = second;
// 	t_list *temp = head;
// 	while (temp)
// 	{
// 		printf("%s\n", (char *) temp -> content);
// 		temp = temp -> next;
// 	}
// 	ft_lstdelone(second, del);

// 	temp = head;
// 	while (head -> next)
// 	{
// 		printf("%s\n", (char *) head -> content);
// 		head = head -> next;
// 	}
// 	head = temp;
// 	free (head);

// }
