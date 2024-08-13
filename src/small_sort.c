/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <tzizi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:31:33 by tzizi            #+#    #+#             */
/*   Updated: 2024/08/09 13:31:33 by tzizi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int find_max(t_list *stack)
{
    int index;

    index = stack->index;
    while (stack)
    {
        if (stack->index > index)
            index = stack->index;
        stack = stack->next;
    }
    return (index);
}

int find_min(t_list *stack)
{
    int     min;
    int     index;
    t_list  *tmp;

    min = stack->index;
    index = 0;
    tmp = stack;
    while (stack)
    {
        if (stack->index < min)
        {
            min = stack->index;
        }
        stack = stack->next;
    }
    while (tmp && tmp->index != min)
    {
        index++;
        tmp = tmp->next;
    }
    return (index);
}

void    small_sort_3(t_list **stack)
{
    int max;

    if (is_sorted(*stack))
        return ;
    max = find_max(*stack);
    if ((*stack)->index == max)
		call_ra(stack);
	else if ((*stack)->next->index == max)
		call_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		call_sa(stack);
}

void    small_sort_4(t_list **stack_a, t_list **stack_b)
{
    int min;

    min = find_min(*stack_a);
    if (min == 1)
        call_ra(stack_a);
    else if (min == 2)
    {
        call_ra(stack_a);
        call_ra(stack_a);
    }
    else if (min == 3)
        call_rra(stack_a);
    if (is_sorted(*stack_a))
        return ;
    call_pb(stack_b, stack_a);
    small_sort_3(stack_a);
    call_pa(stack_a, stack_b);
}

void    small_sort_5(t_list **stack_a, t_list **stack_b)
{
    int min;

    min = find_min(*stack_a);
    if (min == 1)
        call_ra(stack_a);
    else if (min == 2)
    {
        call_ra(stack_a);
        call_ra(stack_a);
    }
    else if (min == 3)
    {
        call_rra(stack_a);
        call_rra(stack_a);
    }
    else if (min == 4)
        call_rra(stack_a);
    if (is_sorted(*stack_a))
        return ;
    call_pb(stack_b, stack_a);
    small_sort_4(stack_a, stack_b);
    call_pa(stack_a, stack_b);
}

void    small_sort(t_list **stack_a, t_list **stack_b)
{
    int size;

    size = ft_lstsize(*stack_a);
    if (size < 2 || is_sorted(*stack_a))
        return ;
    if (size <= 3)
        small_sort_3(stack_a);
    if (size == 4)
        small_sort_4(stack_a, stack_b);
    if (size == 5)
        small_sort_5(stack_a, stack_b);
}
