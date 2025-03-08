/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:44:41 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/08 22:29:28 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execution(char *cmd, char **envp)
{
	char	**av;
	char	*path;

	av = ft_split(cmd, ' ');
	if (!av)
	{
		perror("Faild split operation");
		exit (EXIT_FAILURE);
	}
	path = find_path(av[0], envp);
	if (!path)
	{
		free_matrix (av);
		// perror("Comand execution Faild");
		exit(EXIT_FAILURE);
	}
	execve(path, av, envp);
	perror("Execution failed");
	free(path);
	free_matrix(av);
	exit(EXIT_FAILURE);
}

void	free_matrix (char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i++]);
	}
	free(matrix);
}

void	close_pipe(int *pipefd)
{
	if (close(pipefd[0]) == -1)
		perror ("Faild to read");
	if (close(pipefd[1]) == -1)
		perror("faild to close write");
}

void	ft_errors(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}
