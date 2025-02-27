/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:01:56 by xhamzall          #+#    #+#             */
/*   Updated: 2024/11/30 17:51:53 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*input;
	size_t	result;

	if (nmemb == 0 || size == 0)
	{
		return (malloc(0));
	}
	result = nmemb * size;
	if (result / nmemb != size)
		return (NULL);
	input = malloc(nmemb * size);
	if (input == NULL)
		return (NULL);
	else
		ft_bzero(input, nmemb * size);
	return (input);
}
// int main()
// {
// 	char *arr = ft_calloc(4, sizeof(char) + 1);
// 	if(arr ==  (void *)0)

// 	printf("arr = %s.", arr);
// }
