/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:29:11 by xhamzall          #+#    #+#             */
/*   Updated: 2024/12/01 18:58:11 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;

	if (lst == NULL || f == NULL)
		return (NULL);
	node = NULL;
	new_lst = node;
	while (lst)
	{
		node = ft_lstnew((*f)(lst -> content));
		if (!node)
		{
			ft_lstclear(&new_lst, *del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst -> next;
	}
	return (new_lst);
}
// static void *modi(void* contetnt)
// {
// 	free(contetnt);
// 	return (contetnt = ft_strdup("yeap"));
// }

// static void del(void *content)
// {
// 	free(content);
// }

// int main()
// {
// 	t_list *head = ft_lstnew(ft_strdup("ciaoo"));
// 	t_list *second = ft_lstnew(ft_strdup("bella"));

// 	head ->next = second;
// 	t_list *temp = head;
// 	while(head)
// 	{
// 		printf("%s\n", (char *)head->content);
// 		head = head->next;
// 	}

// 	temp = ft_lstmap(temp, modi, del);
// 	while(temp)
// 	{
// 		printf("%s\n",(char *) temp->content);
// 		temp = temp->next;
// 	}
// }
