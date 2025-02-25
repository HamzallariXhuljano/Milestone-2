/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2025/02/25 14:40:58 by xhamzall          #+#    #+#             */
/*   Updated: 2025/02/25 14:41:01 by xhamzall         ###   ########.fr       */
=======
/*   Created: 2025/02/09 19:30:58 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/19 19:10:00 by xhamzall         ###   ########.fr       */
>>>>>>> 62421d0efbe919b847e2d17532740cff192b4d44
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_a(t_swap *a, int b)
{
	t_swap	*tmp;
	int		pos_a;

<<<<<<< HEAD
	tmp = a;
=======
	if (!a)
		return (0);

	ls_size = fft_lstsize(a);

	if (pos_a < 0 || pos_a >= ls_size)
		return (0);

	if (ls_size == 1)
		return (0);

	if (pos_a > (ls_size / 2))
		return (ls_size - pos_a);
	else
		return (pos_a);
}

int moves_b(t_swap *b, int i)
{
	int ls_size;

	if (!b)
		return (0);

	ls_size = fft_lstsize(b);

	if (i < 0 || i >= ls_size)
		return (0);

	if (ls_size == 1)
		return (0);

	if (i > (ls_size / 2))
		return (ls_size - i);
	else
		return (i);
}




int find_closest_in_a(t_swap *a, int value)
{
	int closest = a->content;
	int min_diff = abs(a->content - value);
	a = a->next;

	while (a) {
		int diff = abs(a->content - value);
		if (diff < min_diff) {
			min_diff = diff;
			closest = a->content;
		}
		a = a->next;
	}

	return closest;
}



int total_moves(t_swap *a, t_swap *b, int index_b) {
    if (!b || !a)
        return (INT_MAX);

    int size_a = fft_lstsize(a);
    int size_b = fft_lstsize(b);
    int closest = find_closest_in_a(a, b->content);
    int index_aa = index_a(a, closest);
	int moves_aa = moves_a(a, index_aa);
	int moves_bb = moves_b(b, index_b);

	// Evita movimenti doppi inutili
    if ((index_b < size_b / 2 && index_aa < size_a / 2) ||
        (index_b >= size_b / 2 && index_aa >= size_a / 2)) {
		return (moves_aa > moves_bb) ? moves_aa : moves_bb;
    }

	return moves_aa + moves_bb;
}

int best_element(t_swap *a, t_swap *b)
{
	int i;
	int min_move;
	int moves;
	int index;
	t_swap *tmp;

	if (!b)
		return (-1);
	tmp = b;
	min_move = INT_MAX;
	index = 0;
	i = 0;
	if (!a)
		return (0);
>>>>>>> 62421d0efbe919b847e2d17532740cff192b4d44
	while (tmp)
	{
		if (tmp->next)
		{
			if (b > tmp->content && b < tmp->next->content)
			{
				pos_a = cal_index(a, tmp->next->content, fft_lstsize(a));
				break;
			}
		}
		else if (b > tmp->content && b < a->content)
		{
			pos_a = cal_index(a, a->content, fft_lstsize(a));
			break;
		}
		tmp = tmp->next;
	}
	if (!tmp)
		pos_a = cal_index(a, smallest(a), fft_lstsize(a));
	return (pos_a);
}

int	moves_b(t_swap *b, int i)
{
<<<<<<< HEAD
	int		moves;
	int		size_b;

	moves = 0;
	size_b = fft_lstsize(b) + i;
	if (i <= size_b / 2)
		moves = i;
	else if (i < size_b)
		moves = i - size_b;
	return (moves);
=======
	while (d->pos_a > 0 && d->index > 0)
	{
		rr(a, b);
		d->pos_a--;
		d->index--;
	}
>>>>>>> 62421d0efbe919b847e2d17532740cff192b4d44
}
void	store_data(int total, int count_a, int count_b, t_data *d)
{
<<<<<<< HEAD
	d->count_a = count_a;
	d->count_b = count_b;
	d->total = ft_abs(total);
=======
	while (d->pos_a < d->size_a && d->index < d->size_b)
	{
		rrr(a, b);
		d->pos_a++;
		d->index++;
	}
>>>>>>> 62421d0efbe919b847e2d17532740cff192b4d44
}

void	total_moves(t_swap *a, t_swap *b, int pos, t_data *d)
{
<<<<<<< HEAD
	int	total;
	int	count_a;
	int	count_b;

	count_a = moves_a(a, b->content);
	count_b = moves_b(b, pos);
	if (count_a >= 0 && count_b >= 0)
	{
		if (count_a > count_b)
			total = count_a;
		else
			total = count_b;
	}
	else if (count_a < 0 && count_b < 0)
	{
		if (count_a < count_b)
			total = count_a;
		else
			total = count_b;
=======
    int size;

    size = fft_lstsize(*b);
    if (index == 0)
        return;
    if (index >= (size / 2))
    {
        while (index < size)
        {
            rrb(b);
            ft_printf("rrb\n"); // Debugging output
            index++;
        }
    }
    else
    {
        // Rotate up (rb)
        while (index > 0)
        {
            rb(b);
            ft_printf("rb\n"); // Debugging output
            index--;
        }
    }
}

void movement_a(t_swap **a, int pos_a)
{
	int size;

	if (!a || !*a)
		return;

	size = fft_lstsize(*a);
	if (pos_a == 0)
		return;

	if (pos_a < size / 2)
	{
		// Rotate up (ra)
		while (pos_a > 0)
		{
			ra(a);
			pos_a--;
		}
>>>>>>> 62421d0efbe919b847e2d17532740cff192b4d44
	}
	else
		total = ft_abs(count_a) + ft_abs(count_b);
	if (d->total > ft_abs(total))
		store_data(total, count_a, count_b, d);
}
<<<<<<< HEAD

void	best_element(t_swap **a, t_swap **b, t_data *d)
=======
void movement(t_swap **a, t_swap **b, t_data *d)
>>>>>>> 62421d0efbe919b847e2d17532740cff192b4d44
{
	int	i;
	t_swap	*tmp;

<<<<<<< HEAD
	d->total = INT_MAX;
	d->count_a = 0;
	d->count_b = 0;
	tmp = *b;
	i = 0;
	while(tmp)
	{
		total_moves(*a, tmp, i, d);
=======
	d->size_a = fft_lstsize(*a);
	d->size_b = fft_lstsize(*b);
	tmp = d->index;
	tem = *b;

	while (tmp > 0 && tem)
	{
		tem = tem->next;
		tmp--;
	}

	if (!tem)
	{
		d->pos_a = 0;
		return;
	}

	d->pos_a = index_a(*a, tem->content);

	// Prima facciamo tutte le rotazioni comuni
	if (d->index <= (d->size_b / 2) && d->pos_a <= (d->size_a / 2))
	{
		rr_movement(a, b, d);
	}
	else if (d->index > (d->size_b / 2) && d->pos_a > (d->size_a / 2))
		rrr_movement(a, b, d);

	// Poi gestiamo le rotazioni singole
	movement_b(b, d->index);
	movement_a(a, d->pos_a);

	pa(a, b);
}

void final_rotation(t_swap **a) {
	t_swap *tmp = *a;
	int min = tmp->content;
	int min_index = 0;
	int i = 0;
	int size = fft_lstsize(*a);

	while (tmp) {
		if (tmp->content < min) {
			min = tmp->content;
			min_index = i;
		}
		tmp = tmp->next;
>>>>>>> 62421d0efbe919b847e2d17532740cff192b4d44
		i++;
		tmp = tmp->next;
	}
<<<<<<< HEAD
}



// int	main(void)
// {
// 	t_swap	*head = fft_lstnew(89);
// 	t_swap	*h2 = fft_lstnew(104);
// 	// t_swap	*h3 = fft_lstnew(94);
// 	// t_swap	*h4 = fft_lstnew(52);
// 	// t_swap	*h5 = fft_lstnew(104);
// 	// t_swap	*h6 = fft_lstnew(90);
// 	// t_swap	*h7 = fft_lstnew(60);
// 	// t_swap	*h8 = fft_lstnew(82);

// 	t_swap	*head2 = fft_lstnew(1);
// 	t_swap	*h12 = fft_lstnew(44);
// 	t_swap	*h13 = fft_lstnew(60);
// 	t_swap	*h14 = fft_lstnew(99);

// 	head->next = h2;
// 	// h2->next = h3;
// 	// h3->next = h4;
// 	// h4->next = h5;
// 	// h5->next = h6;
// 	// h6->next = h7;
// 	// h7->next = h8;

// 	head2->next = h12;
// 	h12->next = h13;
// 	h13->next = h14;

// 	// sa(head);
// 	//sb(head2);
// 	//ss(head, head2);
// 	//pa(&head, &head2);
// 	//pb(&head, &head2);
// 	//ra(&head);
// 	//rb(&head2);
// 	//rr(&head, &head2);
// 	//rra(&head);
// 	//rrr(&head, &head2);
// 	ft_printf("Before\n");
// 	print_lst(head);
// 	ft_printf("\n");
// 	print_lst(head2);
// 	ft_printf("After\n");
// 	push_all(&head, &head2);
// 	print_lst(head);
// 	ft_printf("\n");
// 	print_lst(head2);
// 	free_list(head2);
// 	free_list(head);
// }
=======

	if (min_index <= size / 2) {
		while (min_index-- > 0)
			ra(a);
	} else {
		while ((size - min_index) > 0) {
			rra(a);
			min_index++;
		}
	}
}


void push_all(t_swap **a, t_swap **b)
{
	t_data d;
	while (*b) {
		d.index = best_element(*a, *b);
		movement(a, b, &d);
	}
	final_rotation(a);
}

void pb_only_two_a(t_swap **a, t_swap **b)
{
	// Push elements from stack 'a' to stack 'b' until only two elements remain in 'a'
	while (*a && (*a)->next && (*a)->next->next)
	{
		pb(a, b);
	}
	if(*a && (*a)->content > (*a)->next->content)
		sa(*a);
}
int count = 0;
int main(int ac, char **av)
{
	t_swap *head = NULL;
	t_swap *head2 = NULL;
	t_swap *new_node;
	int i, num;

	if (ac < 2)
	{
		ft_printf("Usage: %s num1 num2 num3 ...\n", av[0]);
		return (1);
	}

	// Creazione della lista 'a' con i numeri forniti da argv
	for (i = ac - 1 ; i > 0; i--)
	{
		num = atoi(av[i]); // Converti il numero
		new_node = fft_lstnew(num); // Crea un nuovo nodo
		if (!new_node)
		{
			free_list(head);
			ft_printf("Error: Memory allocation failed\n");
			return (1);
		}
		new_node->next = head;
		head = new_node;
	}

	// Esegui le operazioni di push_swap
	print_lst(head);
	pb_only_two_a(&head, &head2);
	push_all(&head, &head2);

	// Stampa lo stato finale delle liste (se hai una funzione di stampa)
	print_lst(head);
	// ft_printf("\n");
	// print_lst(head2);
	ft_printf("%d", count);
	// Libera la memoria
	free_list(head2);
	free_list(head);
	return (0);
}

// if(*a && (*a)->next)
// 	{
// 		if((*a) -> content > (*a)-> next -> content)
// 			sa(*a);
// 	}
>>>>>>> 62421d0efbe919b847e2d17532740cff192b4d44
