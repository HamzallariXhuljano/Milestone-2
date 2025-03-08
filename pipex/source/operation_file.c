/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:29:26 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/08 20:23:02 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//file input
int read_file(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error input file");
		exit(EXIT_FAILURE);
	}
	return(fd);
}
//file output
int write_file(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC , 0644 );
	if (fd < 0)
	{
		perror("Error output file");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
