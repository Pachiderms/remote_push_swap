/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <tzizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:49:59 by tzizi             #+#    #+#             */
/*   Updated: 2024/07/10 17:29:07 by tzizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void    display_lst(t_list *stack_a, t_list *stack_b)
{
    if (stack_a == NULL && stack_b == NULL)
    {
        ft_printf("_ _\n");
        ft_printf("a b\n");
    }
    else
    {
        if (stack_b == NULL)
        {
            ft_printf("%s \n", stack_a->val);
            display_lst(stack_a->next, NULL);
        }
        else if (stack_a == NULL)
        {
            ft_printf("  %s\n", stack_b->val);
            display_lst(NULL, stack_b->next);
        }
        else
        {
            ft_printf("%s ", stack_a->val);
            ft_printf("%s\n", stack_b->val);
            display_lst(stack_a->next, stack_b->next);
        }
    }
}

void    display_lst_single(t_list *stack)
{
    if (stack == NULL)
    {
        ft_printf("_\n");
    }
    else
    {
        ft_printf("%s\n", stack->val);
        display_lst_single(stack->next);
    }     
}