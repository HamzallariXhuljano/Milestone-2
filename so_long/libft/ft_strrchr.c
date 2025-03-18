/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:43:11 by xhamzall          #+#    #+#             */
/*   Updated: 2024/11/27 20:36:30 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}
/*
int main()
{
	printf("Stampato con il c STRRCHR #### ");
	printf("%s\n", strrchr("ciao", '\0'));

	printf("Stampato con il mio FT_STRRCHR **** ");
	printf("%s\n", ft_strrchr("ciao", '\0'));

}*/
