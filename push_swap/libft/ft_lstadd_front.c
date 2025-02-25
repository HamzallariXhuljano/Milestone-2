/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:24:24 by xhamzall          #+#    #+#             */
/*   Updated: 2024/12/01 16:02:20 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new -> next = *lst;
	*lst = new;
}
/* int main ()
{
	t_list *head = ft_lstnew("ragazza");
	t_list *second = ft_lstnew("bella");
	t_list *last = ft_lstnew("ciao");
	t_list *temp;

	head -> next = second;
	temp = head;
	while (temp)
	{
		printf("%s\n", (char *)temp -> content);
		temp = temp -> next;
	}
	printf("\n");
	ft_lstadd_front(&head,last);
	temp = head;
	while (temp)
	{
		printf("%s\n", (char *)temp -> content);
		temp = temp -> next;
	}

} */
