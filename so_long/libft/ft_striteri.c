/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:45:43 by xhamzall          #+#    #+#             */
/*   Updated: 2024/11/28 17:31:44 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* static void ft_upper(unsigned int i, char *str)
{
    (void)i; // Ignora l'indice se non necessario
    if (*str >= 'a' && *str <= 'z')
        *str = *str - 32; // Converte il carattere in maiuscolo
} */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
// int main()
// {
// 	char prova[] = "CiaP";
// 	ft_striteri(prova, ft_upper);
// 	printf("%s", prova);
// }
