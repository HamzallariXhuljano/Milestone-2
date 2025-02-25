/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:42:38 by xhamzall          #+#    #+#             */
/*   Updated: 2024/11/27 20:33:27 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;
	size_t	j;

	x = 0;
	i = ft_strlen(dst);
	j = i;
	if (size <= i)
	{
		return (size + ft_strlen(src));
	}
	while (i < size - 1 && src[x] != '\0')
	{
		dst[i] = src[x];
		x++;
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src) + j);
}

/*int main()
{
    char dst[20] = "Hello, ";
    const char *src = "World!";
    size_t result;
    result =ft_strlcat(dst, src, 20);
    printf("Resulting string: %s\n", dst);
    printf("Total length: %zu\n", result);

    return 0;
}*/
