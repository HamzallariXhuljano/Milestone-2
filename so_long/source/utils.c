/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:01:17 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/18 15:48:02 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix (char **mat)
{
	int	i;

	i = 0;
	if (mat == NULL)
	{
		free(mat);
		return ;
	}
	while(mat[i])
	{
		free(mat[i]);
		i ++;
	}
	free (mat);
}
