/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:37:19 by xhamzall          #+#    #+#             */
/*   Updated: 2024/11/27 20:38:51 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	slen;
	unsigned int	i;
	char			*str;

	slen = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (start >= slen)
		return (ft_strdup(""));
	if (len >= slen - start)
		len = slen - start;
	str = malloc(len * sizeof(char) + 1);
	i = 0;
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
// int	main()
// {
// 	printf("%s\n",ft_substr("lorem ipsum dolor sit amet", 400,20));
// }
