/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 22:44:36 by xhamzall          #+#    #+#             */
/*   Updated: 2024/12/01 18:23:49 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)-> next;
		del((*lst)-> content);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
// static void del (void *content)
// {
// 	content = NULL ;
// }

// int main()
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
// 	ft_lstclear(&head, del);

// 	if (head == NULL)
// 	 	printf("tutto clear");
// 	free(head);
// }
