/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:49:20 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/01 21:38:24 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
int main()
{
	pid_t p_child_one = fork();
	pid_t p_child_two;
	if(p_child_one < 0)
	{
		perror("The creation of a child process was unsuccessful.");
		exit(1);
	}
	else if (p_child_one == 0)
	{
		ft_printf("child 1:)\n");
		exit(0);
	}
	else
	{
		p_child_two = fork();
		if(p_child_two < 0)
		{
			perror("The creation of a child process was unsuccessful.");
			exit(1);
		}
		else if (p_child_two == 0)
		{
			ft_printf("child 2\n");
			exit(0);
		}
		else
		{
			ft_printf("i'm your father\n");
		}
		waitpid(p_child_one, NULL, 0);
		waitpid(p_child_two, NULL, 0);
	}
}
/*

*/

