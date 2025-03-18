/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:32:40 by xhamzall          #+#    #+#             */
/*   Updated: 2024/12/01 17:29:03 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}

// static void del(void *content)
// {
// 	free(content);
// 	content = ft_strdup("yesssah");
// }

// int main()
// {
// 	t_list *head = ft_lstnew(ft_strdup("ciao"));
// 	t_list *second = ft_lstnew(ft_strdup("ciao1"));
// 	t_list *last = ft_lstnew(ft_strdup("ciao2"));
// 	t_list	*temp;

// 	head -> next = second;
// 	second -> next = last;
// 	temp = head;
// 	while (temp)
// 	{
// 		printf("%s\n", (char *)temp -> content);
// 		temp = temp -> next;
// 	}

// 	temp = head;
// 	ft_lstiter(head, del);

// 	if (head == NULL)
// 	{
// 		printf("probabilmente funziona");
// 	}
// 	else
// 	{
// 		while (head)
// 		{
// 			printf("%s\n", (char *)head -> content);
// 			head = head -> next;
// 		}
// 	}
// }
