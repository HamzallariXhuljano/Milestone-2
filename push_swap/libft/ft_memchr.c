/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:22:07 by xhamzall          #+#    #+#             */
/*   Updated: 2024/11/27 20:24:27 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*str;
	size_t				i;

	str = (unsigned const char *) s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char) c)
		{
			return ((void *) &str[i]);
		}
		i++;
	}
	return (NULL);
}
// int main()
// {
// 	printf("Funzione c ORIGINALE\n");
// 	printf("%p\n", memchr("", 'i', 5));
// 	printf("Funzione MIA\n");
// 	printf("%p", ft_memchr("", 'i', 5));
// }
