/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:23:59 by xhamzall          #+#    #+#             */
/*   Updated: 2024/11/27 20:38:05 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_strchr(set, s1[j - 1]))
		j--;
	len = j - i;
	str = malloc(len * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	len = 0;
	while (i < j)
		str[len++] = s1[i++];
	str[len] = '\0';
	return (str);
}
// int	main()
// {
// 	printf("pROVA %s\n", ret);
// }
