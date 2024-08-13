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

#include "../includes/push_swap.h"

void    display_lst_noindex(t_list *stack_a, t_list *stack_b)
{
    if (stack_a == NULL && stack_b == NULL)
    {
        printf("_ _\n");
        printf("a b\n");
    }
    else
    {
        if (stack_b == NULL)
        {
            printf("%s\n", (char*)stack_a->val);
            display_lst_noindex(stack_a->next, NULL);
        }
        else if (stack_a == NULL)
        {
            printf("  %s\n", (char*)stack_b->val);
            display_lst_noindex(NULL, stack_b->next);
        }
        else
        {
            printf("%s ", (char*)stack_a->val);
            printf("%s\n", (char*)stack_b->val);
            display_lst_noindex(stack_a->next, stack_b->next);
        }
    }
}

void    display_lst(t_list *stack_a, t_list *stack_b)
{
    if (stack_a == NULL && stack_b == NULL)
    {
        printf("_ _\n");
        printf("a b\n");
    }
    else
    {
        if (stack_b == NULL)
        {
            printf("%s|%d\n", (char*)stack_a->val, stack_a->index);
            display_lst(stack_a->next, NULL);
        }
        else if (stack_a == NULL)
        {
            printf("  %s|%d\n", (char*)stack_b->val, stack_b->index);
            display_lst(NULL, stack_b->next);
        }
        else
        {
            printf("%s|%d ", (char*)stack_a->val, stack_a->index);
            printf("%s|%d\n", (char*)stack_b->val, stack_b->index);
            display_lst(stack_a->next, stack_b->next);
        }
    }
}

void    display_lst_single(t_list *stack)
{
    if (stack == NULL)
    {
        printf("_\n");
    }
    else
    {
        printf("%s|%d\n", (char*)stack->val, stack->index);
        display_lst_single(stack->next);
    }     
}