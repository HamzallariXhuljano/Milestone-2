/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:31:53 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/09 00:07:15 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(int *pipefd, char **av, char **envp)
{
	int	fd;

	close(pipefd[0]);
	fd = read_file(av[1]);
	if (dup2(fd, STDIN_FILENO) == -1 || dup2(pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 child 1 faild");
		exit(EXIT_FAILURE);
	}
	close(fd);
	close(pipefd[1]);
	execution(av[2], envp);
}

void	child_two(int *pipefd, char **av, char **evnp)
{
	int	fd;

	close(pipefd[1]);
	fd = write_file(av[4]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1 || dup2(fd, STDOUT_FILENO) == -1)
	{
		perror("Dup2 child 2 faild");
		exit(EXIT_FAILURE);
	}
	close (fd);
	close(pipefd[0]);
	execution(av[3], evnp);
}

void	fater(int p_child_one, int p_child_two)
{
	if (waitpid(p_child_one, NULL, 0) == -1 || \
		waitpid(p_child_two, NULL, 0) == -1)
		ft_errors("Waitpid faild");
}
