/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <tzizi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:01:58 by tzizi            #+#    #+#             */
/*   Updated: 2024/08/09 13:01:58 by tzizi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    call_rra(t_list **stack_a)
{
    reverse_rotate(stack_a);
    ft_putstr_fd("rra\n", 1);
}

void    call_rrb(t_list **stack_b)
{
    reverse_rotate(stack_b);
    ft_putstr_fd("rrb\n", 1);
}

void    call_rrr(t_list **stack_a, t_list **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    ft_putstr_fd("rrr\n", 1);
}