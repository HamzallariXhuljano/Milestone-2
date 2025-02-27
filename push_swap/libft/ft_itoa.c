/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:50:56 by xhamzall          #+#    #+#             */
/*   Updated: 2024/11/27 20:18:18 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_lennum(long nb)
{
	long	i;

	i = 0;
	if (nb <= 0)
	{
		i = 1;
		if (nb == 0)
			return (i);
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static char	*ft_putnegative(long i, long nb, char *str)
{
	long	j;

	j = 0;
	nb = -nb;
	while (i > 0)
	{
		j = nb % 10;
		str[i] = j + 48;
		nb = nb / 10;
		i--;
	}
	str[0] = '-';
	return (str);
}

static char	*ft_putpositive(long i, long n, char *str)
{
	long	j;

	j = 0;
	while (i >= 0)
	{
		j = n % 10;
		str[i] = j + 48;
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	i;
	long	nb;

	nb = n;
	i = ft_lennum(nb);
	str = malloc(i * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	i --;
	if (nb < 0)
	{
		ft_putnegative(i, nb, str);
	}
	else if (nb >= 0)
	{
		ft_putpositive(i, nb, str);
	}
	str[ft_lennum(nb)] = '\0';
	return (str);
}
// int main()
// {
// 	printf("%s\n",ft_itoa(-2147483648));
// 	printf("%d\n", ft_lennum(-2147483647));
// }
