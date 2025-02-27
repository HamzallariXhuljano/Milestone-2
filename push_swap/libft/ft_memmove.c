/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:30:52 by xhamzall          #+#    #+#             */
/*   Updated: 2024/11/27 20:59:44 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char	*str_src;
	unsigned char		*str_dest;
	size_t				i;

	i = 0;
	str_dest = (unsigned char *)dest;
	str_src = (unsigned char *)src;
	if (str_dest == NULL && str_src == NULL && n > 0)
		return (NULL);
	if (str_dest < str_src)
	{
		while (i < n)
		{
			str_dest[i] = str_src[i];
			i++;
		}
	}
	else if (str_src <= str_dest)
	{
		while (n--)
		{
			str_dest[n] = str_src[n];
		}
	}
	return (dest);
}
