/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:52:15 by xhamzall          #+#    #+#             */
/*   Updated: 2024/11/28 21:43:47 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cntwrd(char const *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	if (str[0] != c && str[0] != '\0')
		cnt = 1;
	else if (str[i] != '\0' && str[i] == c)
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			cnt = 1;
		else
			cnt = 0;
	}
	else
		cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			cnt++;
		i++;
	}
	return (cnt);
}

static int	ft_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**ft_error_malloc(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	*temp;
	char	**dest;

	j = 0;
	temp = (char *)s;
	if (s == NULL)
		return (NULL);
	dest = malloc((ft_cntwrd(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	while (j < ft_cntwrd(s, c) && temp)
	{
		while (*temp == c)
			temp++;
		dest[j] = malloc((ft_len(temp, c) + 1) * sizeof(char));
		if (!dest[j])
			return (ft_error_malloc(dest));
		ft_strlcpy(dest[j], temp, ft_len(temp, c) + 1);
		temp += ft_len(temp, c) + 1;
		j++;
	}
	dest[j] = NULL;
	return (dest);
}

// int main()
// {
// 	char **result = ft_split("", 'a');
// 	while (*result),a
// 		printf("%s\n", *result++);
// 	return (0);
// }
