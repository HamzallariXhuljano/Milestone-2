/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:49:20 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/01 16:38:40 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
int main(int ac, char **av, char **envp)
{
	pid_t p = fork();
	if(p < 0)
	{
		perror("The creation of a child process was unsuccessful.");
		exit(1);
	}
}
