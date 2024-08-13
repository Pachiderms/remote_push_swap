/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <tzizi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:56:05 by tzizi            #+#    #+#             */
/*   Updated: 2024/08/13 14:56:05 by tzizi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    call_sa(t_list **stack_a)
{
    swap(stack_a);
    ft_putstr_fd("sa\n", 1);
}

void    call_sb(t_list **stack_b)
{
    swap(stack_b);
    ft_putstr_fd("sb\n", 1);
}

void    call_ss(t_list **stack_a, t_list **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    ft_putstr_fd("ss\n", 1);
}