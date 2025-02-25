/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:15:24 by xxx               #+#    #+#             */
/*   Updated: 2024/11/27 20:30:38 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	str = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
// int main ()
// {
// 	printf("print with C function %s\n",strdup("lorem ipsum dolet"));
// 	printf("print with my function %s\n",ft_strdup("lorem ipsum  amet"));
// }
