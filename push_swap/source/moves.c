/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 19:30:58 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/16 17:36:57 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Add debug prints to functions
int moves_a(t_swap *a, int pos_a)
{
	int ls_size;

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



int total_moves(t_swap *a, t_swap *b, int index_b)
{
	int moves_b;
	int moves_a;
	int closest;
	int index_a;
	int combined_moves;
	int remaining_moves;
	if (!b || !a)
		return (INT_MAX);
	// Find the closest number in Stack A
	closest = find_closest_in_a(a, b->content);
	index_a = 0;
	// Find the position of the closest number in Stack A
	t_swap *tmp = a;
	while (tmp && tmp->content != closest)
	{
		index_a++;
		tmp = tmp->next;
	}
	// Calculate moves for Stack B
	if (index_b <= fft_lstsize(b) / 2)
		moves_b = index_b;
	else
		moves_b = fft_lstsize(b) - index_b;
	// Calculate moves for Stack A
	if (index_a <= fft_lstsize(a) / 2)
		moves_a = index_a;
	else
		moves_a = fft_lstsize(a) - index_a;
	// Optimize by combining rotations
	if ((index_b < fft_lstsize(b) / 2 && index_a < fft_lstsize(a) / 2) )
	{
		// Both stacks can be rotated in the same direction (rr or rrr)
		if (moves_a < moves_b)
			combined_moves = moves_a;
		else
			combined_moves = moves_b;
		remaining_moves = abs(moves_a - moves_b);
		return abs((combined_moves + remaining_moves));
	}
	else
		return abs((moves_a + moves_b));
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
	while (tmp)
	{
		moves = total_moves(a, tmp, i);
		if (moves < min_move)
		{
			min_move = moves;
			index = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (index);
}





void rr_movement(t_swap **a, t_swap **b, t_data *d)
{
	while (d->pos_a > 0 && d->index > 0 && d->pos_a < d->size_a / 2 && d->index < d->size_b / 2)
	{
		rr(a, b);
		d->pos_a--;
		d->index--;
	}
}

void rrr_movement(t_swap **a, t_swap **b, t_data *d)
{
	while (d->index < d->size_b && d->pos_a < d->size_a)
	{
		rrr(a, b);
		d->index++;
		d->pos_a++;
	}
}

void movement_b(t_swap **b, int index)
{
	int size;

	size = fft_lstsize(*b);
	if (index == 0)
		return;
	if (index >= (size / 2))
	{
		while (index < size)
		{
			rrb(b);
			index++;
		}
	}
	else
	{
		while (index > 0)
		{
			rb(b);
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

	if (pos_a <= size / 2)
	{
		// Rotate up (ra)
		while (pos_a > 0)
		{
			ra(a);
			pos_a--;
		}
	}
	else
	{
		// Rotate down (rra)
		while (size - pos_a > 0)
		{
			rra(a);
			pos_a++;
		}
	}
}

void movement(t_swap **a, t_swap **b, t_data *d)
{
	t_swap *tem;
	int tmp;

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

	// Ottimizzare i movimenti
	if ((d->index <= (d->size_b / 2)) && (d->pos_a <= (d->size_a / 2)))
		rr_movement(a, b, d);
	else if ((d->index > (d->size_b / 2)) && (d->pos_a > (d->size_a / 2)))
		rrr_movement(a, b, d);

	movement_b(b, d->index);
	movement_a(a, d->pos_a);

	pa(a, b);
}
void final_rotation(t_swap **a)
{
	t_swap *tmp = *a;
	int min = tmp->content;
	int min_index = 0;
	int i = 0;

	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			min_index = i;
		}
		tmp = tmp->next;
		i++;
	}

	int size = fft_lstsize(*a);

	if (min_index <= size / 2)
	{
		while (min_index--)
			ra(a);
	}
	else
	{
		while (size - min_index++)
			rra(a);
	}
}


void push_all(t_swap **a, t_swap **b)
{
	t_data d;

	while (*b)
	{
		d.index = best_element(*a, *b);
		movement(a, b, &d);

	}
   final_rotation(a);
}

void pb_only_two_a(t_swap **a, t_swap **b)
{
	while (*a && (*a)->next && (*a)->next->next)
	{
		pb(a, b);
	}
	if(*a && (*a)->content > (*a)->next->content)
		sa(*a);
}
int count = 0;
int	main(void)
{
	t_swap *head = fft_lstnew(89);
	t_swap *h2 = fft_lstnew(104);


	t_swap *h3 = fft_lstnew(94);
	t_swap *h4 = fft_lstnew(52);
	t_swap *h5 = fft_lstnew(105);
	t_swap *h6 = fft_lstnew(90);
	t_swap *h7 = fft_lstnew(60);
	t_swap *h8 = fft_lstnew(123);
	t_swap *h9 = fft_lstnew(211);
	t_swap *h10 = fft_lstnew(315);
	t_swap *h11 = fft_lstnew(400);
	t_swap *h12 = fft_lstnew(5);
	t_swap *h13 = fft_lstnew(15);
	t_swap *h14 = fft_lstnew(2);
	t_swap *h15 = fft_lstnew(199);
	t_swap *h16 = fft_lstnew(278);
	t_swap *h17 = fft_lstnew(120);
	t_swap *h18 = fft_lstnew(7);
	t_swap *h19 = fft_lstnew(99);
	t_swap *h20 = fft_lstnew(56);
	t_swap *h21 = fft_lstnew(67);
	t_swap *h22 = fft_lstnew(188);
	t_swap *h23 = fft_lstnew(240);
	t_swap *h24 = fft_lstnew(33);
	t_swap *h25 = fft_lstnew(81);
	t_swap *h26 = fft_lstnew(177);
	t_swap *h27 = fft_lstnew(23);
	t_swap *h28 = fft_lstnew(142);
	t_swap *h29 = fft_lstnew(301);
	t_swap *h30 = fft_lstnew(87);
	t_swap *h31 = fft_lstnew(214);
	t_swap *h32 = fft_lstnew(45);
	t_swap *h33 = fft_lstnew(68);
	t_swap *h34 = fft_lstnew(329);
	t_swap *h35 = fft_lstnew(500);
	t_swap *h36 = fft_lstnew(99);
	t_swap *h37 = fft_lstnew(312);
	t_swap *h38 = fft_lstnew(275);
	t_swap *h39 = fft_lstnew(190);
	t_swap *h40 = fft_lstnew(147);
	t_swap *h41 = fft_lstnew(178);
	t_swap *h42 = fft_lstnew(222);
	t_swap *h43 = fft_lstnew(420);
	t_swap *h44 = fft_lstnew(78);
	t_swap *h45 = fft_lstnew(56);
	t_swap *h46 = fft_lstnew(134);
	t_swap *h47 = fft_lstnew(88);
	t_swap *h48 = fft_lstnew(273);
	t_swap *h49 = fft_lstnew(55);
	t_swap *h50 = fft_lstnew(321);
	t_swap *h51 = fft_lstnew(412);
	t_swap *h52 = fft_lstnew(287);
	t_swap *h53 = fft_lstnew(91);
	t_swap *h54 = fft_lstnew(33);
	t_swap *h55 = fft_lstnew(100);
	t_swap *h56 = fft_lstnew(205);
	t_swap *h57 = fft_lstnew(319);
	t_swap *h58 = fft_lstnew(227);
	t_swap *h59 = fft_lstnew(411);
	t_swap *h60 = fft_lstnew(365);
	t_swap *h61 = fft_lstnew(92);
	t_swap *h62 = fft_lstnew(276);
	t_swap *h63 = fft_lstnew(37);
	t_swap *h64 = fft_lstnew(111);
	t_swap *h65 = fft_lstnew(293);
	t_swap *h66 = fft_lstnew(220);
	t_swap *h67 = fft_lstnew(17);
	t_swap *h68 = fft_lstnew(244);
	t_swap *h69 = fft_lstnew(379);
	t_swap *h70 = fft_lstnew(99);
	t_swap *h71 = fft_lstnew(187);
	t_swap *h72 = fft_lstnew(65);
	t_swap *h73 = fft_lstnew(382);
	t_swap *h74 = fft_lstnew(278);
	t_swap *h75 = fft_lstnew(211);
	t_swap *h76 = fft_lstnew(499);
	t_swap *h77 = fft_lstnew(269);
	t_swap *h78 = fft_lstnew(123);
	t_swap *h79 = fft_lstnew(301);
	t_swap *h80 = fft_lstnew(172);
	t_swap *h81 = fft_lstnew(408);
	t_swap *h82 = fft_lstnew(193);
	t_swap *h83 = fft_lstnew(261);
	t_swap *h84 = fft_lstnew(357);
	t_swap *h85 = fft_lstnew(445);
	t_swap *h86 = fft_lstnew(90);
	t_swap *h87 = fft_lstnew(212);
	t_swap *h88 = fft_lstnew(330);
	t_swap *h89 = fft_lstnew(83);
	t_swap *h90 = fft_lstnew(110);
	t_swap *h91 = fft_lstnew(270);
	t_swap *h92 = fft_lstnew(198);
	t_swap *h93 = fft_lstnew(501);
	t_swap *h94 = fft_lstnew(432);
	t_swap *h95 = fft_lstnew(305);
	t_swap *h96 = fft_lstnew(57);
	t_swap *h97 = fft_lstnew(145);
	t_swap *h98 = fft_lstnew(72);
	t_swap *h99 = fft_lstnew(358);
	t_swap *h100 = fft_lstnew(412);

	t_swap *head2 = NULL;

	head->next = h2;
	h2-> next = h3;
	h3->next = h4;
	h4->next = h5;
	h5->next = h6;
	h6->next = h7;
	h7->next = h8;
	h8->next = h9;
	h9->next = h10;
	h10->next = h11;
	h11->next = h12;
	h12->next = h13;
	h13->next = h14;
	h14->next = h15;
	h15->next = h16;
	h16->next = h17;
	h17->next = h18;
	h18->next = h19;
	h19->next = h20;
	h20->next = h21;
	h21->next = h22;
	h22->next = h23;
	h23->next = h24;
	h24->next = h25;
	h25->next = h26;
	h26->next = h27;
	h27->next = h28;
	h28->next = h29;
	h29->next = h30;
	h30->next = h31;
	h31->next = h32;
	h32->next = h33;
	h33->next = h34;
	h34->next = h35;
	h35->next = h36;
	h36->next = h37;
	h37->next = h38;
	h38->next = h39;
	h39->next = h40;
	h40->next = h41;
	h41->next = h42;
	h42->next = h43;
	h43->next = h44;
	h44->next = h45;
	h45->next = h46;
	h46->next = h47;
	h47->next = h48;
	h48->next = h49;
	h49->next = h50;
	h50->next = h51;
	h51->next = h52;
	h52->next = h53;
	h53->next = h54;
	h54->next = h55;
	h55->next = h56;
	h56->next = h57;
	h57->next = h58;
	h58->next = h59;
	h59->next = h60;
	h60->next = h61;
	h61->next = h62;
	h62->next = h63;
	h63->next = h64;
	h64->next = h65;
	h65->next = h66;
	h66->next = h67;
	h67->next = h68;
	h68->next = h69;
	h69->next = h70;
	h70->next = h71;
	h71->next = h72;
	h72->next = h73;
	h73->next = h74;
	h74->next = h75;
	h75->next = h76;
	h76->next = h77;
	h77->next = h78;
	h78->next = h79;
	h79->next = h80;
	h80->next = h81;
	h81->next = h82;
	h82->next = h83;
	h83->next = h84;
	h84->next = h85;
	h85->next = h86;
	h86->next = h87;
	h87->next = h88;
	h88->next = h89;
	h89->next = h90;
	h90->next = h91;
	h91->next = h92;
	h92->next = h93;
	h93->next = h94;
	h94->next = h95;
	h95->next = h96;
	h96->next = h97;
	h97->next = h98;
	h98->next = h99;
	h99->next = h100;
	h100->next = NULL;

	pb_only_two_a(&head, &head2);
	//ft_printf("Before\n");
	//print_lst(head);
	//ft_printf("\n");
	//print_lst(head2);
	//ft_printf("After\n");
	push_all(&head, &head2);
	//print_lst(head);
	//ft_printf("\n");
	ft_printf("mosse totali = %d\n", count);
	print_lst(head);
	free_list(head2);
	free_list(head);
}
// if(*a && (*a)->next)
// 	{
// 		if((*a) -> content > (*a)-> next -> content)
// 			sa(*a);
// 	}
