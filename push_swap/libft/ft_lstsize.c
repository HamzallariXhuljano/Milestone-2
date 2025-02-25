/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 20:45:33 by xhamzall          #+#    #+#             */
/*   Updated: 2024/12/01 18:17:49 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = lst;
	while (temp)
	{
		temp = temp -> next;
		i++;
	}
	return (i);
}

// int main()
// {
// 	t_list	*head = ft_lstnew("ciao");
// 	t_list	*middle = ft_lstnew("hey");
// 	t_list	*last = ft_lstnew("hola");
// 	printf("%d\n", ft_lstsize(head));
// 	head -> next = middle;
// 	middle -> next = last;
// 	printf("%d", ft_lstsize(head));
// }
