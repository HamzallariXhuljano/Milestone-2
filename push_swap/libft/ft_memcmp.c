/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:47:27 by xhamzall          #+#    #+#             */
/*   Updated: 2024/11/27 20:25:04 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*str_s1;
	unsigned const char	*str_s2;
	size_t				i;

	str_s1 = (unsigned const char *) s1;
	str_s2 = (unsigned const char *) s2;
	i = 0;
	while (i < n)
	{
		if (str_s1[i] != str_s2[i])
		{
			return (str_s1[i] - str_s2[i]);
		}
		i++;
	}
	return (0);
}

// int main ()
// {

// 	printf("Funzione MIA\n");
// 	printf("%d\n", ft_memcmp("ciao", "c", 4));
// 	printf("Funzione in C\n");
// 	printf("%d\n", memcmp("ciao", "c", 4));
// }
