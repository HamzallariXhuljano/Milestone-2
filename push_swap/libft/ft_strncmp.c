/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:50:32 by xhamzall          #+#    #+#             */
/*   Updated: 2024/11/27 20:34:48 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] != s2[i])
		{
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		}
		i++;
	}
	if (i < n)
	{
		return (((unsigned char)s1[i] - (unsigned char)s2[i]));
	}
	return (0);
}
// int main()
// {
// 	printf("La mia funzione stampa #### %d\n", ft_strncmp("", "", 5));
// 	printf("La funzione di c stampa **** %d", strncmp("", ", 5));
// }
