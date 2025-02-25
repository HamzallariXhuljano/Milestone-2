/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:56:00 by xhamzall          #+#    #+#             */
/*   Updated: 2024/11/27 20:35:56 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		if (little[j] == big[i])
		{
			while (little[j] != '\0' && j + i < len && little[j] == big[j + i])
			{
				j++;
			}
			if (little[j] == '\0')
				return ((char *) &big[i]);
			else
				j = 0;
		}
		i++;
	}
	return (NULL);
}
// int main()
// {
// 	printf("Mia Funzione = %s", ft_strnstr("or sit amet", "dolor", 15));
// 	//printf("Mia Funzione = %d", strnstr("ciao come", "ci", 10));
// }
