/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:54:55 by xhamzall          #+#    #+#             */
/*   Updated: 2024/12/01 18:24:46 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	temp = lst;
	while (temp -> next)
	{
		temp = temp -> next;
	}
	return (temp);
}
// int main()
// {
// 	t_list *head = ft_lstnew("Ciao");
// 	t_list *middle = ft_lstnew("Hello");
// 	t_list *last = ft_lstnew("Hola");

// 	head -> next = middle;
// 	middle -> next = last;

// 	printf("%s", ft_lstlast(head) -> content);
// }
