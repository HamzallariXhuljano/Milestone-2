/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:03:31 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/14 14:48:54 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Function to create a new node
t_swap *fft_lstnew(int content)
{
    t_swap *newnode;

    newnode = (t_swap *)malloc(sizeof(t_swap));
    if (newnode == NULL)
        return (NULL);
    newnode->content = content;
    newnode->next = NULL;
    return (newnode);
}

// Function to free the entire list
void free_list(t_swap *swap)
{
    t_swap *tmp;

    while (swap)
    {
        tmp = swap;
        swap = swap->next;
        free(tmp);
    }
}

// Function to print the list
void print_lst(t_swap *swap)
{
    t_swap *tmp;
    tmp = swap;
    while (tmp)
    {
        if (tmp->next == NULL)
        {
            ft_printf("%d\n", tmp->content);
            break;
        }
        ft_printf("%d--", tmp->content);
        tmp = tmp->next;
    }
}

// Function to find the last node in the list
t_swap *lastnode(t_swap **swap)
{
    t_swap *tmp;

    tmp = *swap;
    if (!tmp || !tmp->next)
        return (NULL);
    while (tmp->next)
        tmp = tmp->next;
    return (tmp);
}

// Function to find the second last node in the list
t_swap *lastnode1(t_swap **swap)
{
    t_swap *tmp;

    tmp = *swap;
    if (!tmp || !tmp->next)
        return (NULL);
    while (tmp->next->next)
        tmp = tmp->next;
    return (tmp);
}

// Function to calculate the size of the list
int fft_lstsize(t_swap *lst)
{
    int i;

    i = 0;
    while (lst)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}

// Function to find the correct position in stack a for an element from stack b
int index_a(t_swap *a, int n)
{
    int i;
    int min_index;
    t_swap *tmp;
    t_swap *min;

    if (!a)
        return (0);

    i = 0;
    min_index = 0;
    tmp = a;
    min = a;

    // Trova il minimo di a e il suo indice
    while (tmp)
    {
        if (tmp->content < min->content)
        {
            min = tmp;
            min_index = i;
        }
        tmp = tmp->next;
        i++;
    }

    // Se n è più piccolo del minimo, deve andare prima del minimo
    if (n < min->content)
        return (min_index);

    // Cerca la prima posizione in cui n può essere inserito
    i = 0;
    tmp = a;
    while (tmp->next)
    {
        if (tmp->content < n && tmp->next->content > n)
            return (i + 1);
        i++;
        tmp = tmp->next;
    }

    // Se non trova una posizione, inserire in fondo
    return (i + 1);
}





