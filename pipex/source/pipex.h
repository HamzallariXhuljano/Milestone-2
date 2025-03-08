/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:43:54 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/08 21:39:29 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

void	free_matrix (char **matrix);
char	*make_path(char *dir, char *cmd );
char	**get_path(char **evnp);
char	*get_comand_path(char *cmd, char **path);
char	*path_evnp(char **evnp);
int		read_file(char *file);
int		write_file(char *file);
char	*find_path(char *cmd, char **envp);
void	execution(char *cmd, char **envp);
void	close_pipe(int *pipefd);
void	child_one(int *pipefd, char **av,  char **envp);
void	child_two(int *pipefd, char **av, char **evnp);
void	ft_errors(char *error);

#endif
