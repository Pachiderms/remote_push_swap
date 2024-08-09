/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <tzizi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:50:07 by tzizi            #+#    #+#             */
/*   Updated: 2024/08/09 12:50:07 by tzizi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    call_ra(t_list **stack_a)
{
    rotate(stack_a);
    ft_putstr_fd("ra\n", 1);
}

void    call_rb(t_list **stack_b)
{
    rotate(stack_b);
    ft_putstr_fd("rb\n", 1);
}

void    call_rr(t_list **stack_a, t_list **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_putstr_fd("rr\n", 1);
}