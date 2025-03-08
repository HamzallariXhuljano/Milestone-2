/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:49:20 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/08 23:59:12 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	pid_t	p_child_one;
	pid_t	p_child_two;
	int		pipefd[2];

	if (ac != 5)
	{
		ft_printf("Usage: %s infile cmd1 cmd2 outfile\n", av[0]);
		return (EXIT_FAILURE);
	}
	if (pipe(pipefd) == -1)
		ft_errors("Faild pipe");
	p_child_one = fork();
	if (p_child_one < 0)
		ft_errors("Error fork child 1");
	if (p_child_one == 0)
		child_one(pipefd, av, envp);
	p_child_two = fork();
	if (p_child_two < 0)
		ft_errors("Error fork child 2");
	if (p_child_two == 0)
		child_two(pipefd, av, envp);
	close_pipe(pipefd);
	fater(p_child_one, p_child_two);
	return (EXIT_SUCCESS);
}
