/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <tzizi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:46:48 by tzizi            #+#    #+#             */
/*   Updated: 2024/07/29 14:46:48 by tzizi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_steps(t_list *stack)
{
    int j;
    int     max_steps;

    max_steps = 0;
    while (stack)
    {
        j = 0;
        while (stack->index >> j)
            j++;
        if (j > max_steps)
            max_steps = j;
        stack = stack->next;
    }
    return (max_steps);
}

void    big_sort(t_list **s_a, t_list **s_b)
{
    int i;
    int j;
    int size;
    int steps;
    
    j = 0;
    size = ft_lstsize(*s_a);
    steps = get_steps(*s_a);
    while (j < steps)
    {
        i = 0;
        while (i++ < size)
        {
            if((((*s_a)->index >> j) & 1) == 1)
                call_ra(s_a);
            else
                call_pb(s_b, s_a);
        }
        while (*s_b != NULL)
            call_pa(s_a, s_b);
        j++;
    }
}
