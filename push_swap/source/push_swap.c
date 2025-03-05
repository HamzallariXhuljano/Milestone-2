/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:41:48 by xhamzall          #+#    #+#             */
/*   Updated: 2025/03/05 14:22:50 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**matrix;
	t_swap	*a;
	t_swap	*b;
	t_data	d;

	b = NULL;
	if (ac < 2 || (av[1][0] == '\0'))
		return (0);
	matrix = matrix_creation(ac, av, 1);
	if (matrix == NULL)
		return (0);
	a = lstcreation(matrix);
	if (!a || (a && !(a -> next)))
		return (free_list(a), 0);
	if (fft_lstsize(a) == 3)
		return (three_args(&a), free_list(a), 0);
	while (a && a->next->next && (is_sorted(&a) == 0))
		pb(&a, &b, 1);
	two_check(&a);
	push_all(&a, &b, &d);
	final_rotation(&a);
	if (is_sorted(&a) == 0)
		write(2, "ERROR1\n", 6);
	return (free_list(a), 0);
}
