/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:20:43 by xhamzall          #+#    #+#             */
/*   Updated: 2024/11/27 20:27:21 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = (char) c;
		i++;
	}
	return (s);
}
/*
int	main (void)
{
	int c = 41;
	unsigned char *s;
	size_t n = 4;
	printf("%s", memset(s, c, n));
}*/
