/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <tzizi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:10:10 by tzizi            #+#    #+#             */
/*   Updated: 2024/08/13 17:10:10 by tzizi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    call_pa(t_list **stack_a, t_list **stack_b)
{
    push(stack_a, stack_b);
    ft_putendl_fd("pa", 1);
}

void    call_pb(t_list **stack_b, t_list **stack_a)
{
    push(stack_b, stack_a);
    ft_putendl_fd("pb", 1);
}