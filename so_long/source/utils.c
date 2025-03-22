/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:01:17 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/22 05:14:00 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix (char **mat)
{
	int	i;

	i = 0;
	if (!mat)
	{
		return ;
	}
	while(mat[i])
	{
		printf("Freeing: %p -> %s\n", mat[i], mat[i]);
		free(mat[i]);
		i ++;
	}
	free (mat);
}
