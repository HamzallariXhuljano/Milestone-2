/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:07:27 by xhamzall          #+#    #+#             */
/*   Updated: 2025/02/04 19:01:13 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"

typedef struct s_swap
{
	int				content;
	struct s_swap	*next;
} t_swap;

void	print_lst(t_swap *swap);
t_swap	*fft_lstnew(int	content);
int	sa(t_swap *swap);
int	sb(t_swap *swap);
void	free_list(t_swap *head);

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <ctype.h>

#endif
