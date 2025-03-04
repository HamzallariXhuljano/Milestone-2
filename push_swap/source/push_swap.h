/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:41:54 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/04 15:37:14 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <ctype.h>
# include <limits.h>

typedef struct s_swap
{
	int				content;
	struct s_swap	*next;
}	t_swap;

typedef struct s_data
{
	int				count_a;
	int				count_b;
	int				total;
}	t_data;

t_swap		*fft_lstnew(int content);
void		free_list(t_swap *swap);
void		print_lst(t_swap *swap);
void		free_one(t_swap **swap);
t_swap		*lastnode(t_swap **swap);
t_swap		*lastnode1(t_swap **swap);
int			sa(t_swap *swap, int i);
int			sb(t_swap *swap, int i);
int			ss(t_swap *a, t_swap *b, int i);
int			pa(t_swap **a, t_swap **b, int i);
int			pb(t_swap **a, t_swap **b, int i);
int			ra(t_swap **swap, int i);
int			rb(t_swap **swap, int i);
int			rr(t_swap **a, t_swap **b, int i);
int			rra(t_swap **swap, int i);
int			rrb(t_swap **swap, int i);
int			rrr(t_swap **a, t_swap **b, int i);
int			cal_index(t_swap *a, int n, int size);
int			smallest(t_swap *swap);
int			ft_abs(int x);
int			fft_lstsize(t_swap *lst);
void		fft_lstadd_back(t_swap **lst, t_swap *new);
void		free_mat(char **matrix);
char		**more_args(int argc, char **av, int f);
char		**two_args(char *argv, int i);
int			duplicates(char **matrix, int f);
int			check_arg(char **matrix, int f);
t_swap		*lstcreation(char **matrix);
int			moves_b(t_swap *b, int i);
int			moves_a(t_swap *a, int n);
void		store_data(int total, int count_a, int count_b, t_data *d);
void		total_moves(t_swap *a, t_swap *b, int pos, t_data *d);
void		best_element(t_swap **a, t_swap **b, t_data *d);
void		movement(t_swap **a, t_swap **b, t_data *d);
void		movement_a(t_swap **a, t_data *d);
void		movement_b(t_swap **b, t_data *d);
void		final_rotation(t_swap **a);
int			is_sorted(t_swap **a);
void		two_check(t_swap **a);
int			ft_strcmp(const char *s1, const char *s2);
void		push_all(t_swap **a, t_swap **b, t_data *d);
void		three_args(t_swap **a);
char		**matrix_creation(int ac, char **av, int f);

#endif
