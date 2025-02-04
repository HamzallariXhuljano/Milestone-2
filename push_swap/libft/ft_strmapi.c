/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 01:05:11 by xhamzall          #+#    #+#             */
/*   Updated: 2024/11/28 15:57:16 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// static char	 ft_upper(unsigned int i, char c)
// {
// 	if ( c >= 'a' && c <= 'z')
// 		c = c - 32;
// 	return c;
// }
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	len;
	unsigned int	i;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = (f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
// int main()
// {
// 	char	*str = "Ciao come stai!!";
// 	printf("%s", ft_strmapi(str, ft_upper));
// }
