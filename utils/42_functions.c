/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:51:41 by marvin            #+#    #+#             */
/*   Updated: 2024/07/11 18:51:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    swap(t_list **stack)
{
    t_list  *tmp;
    t_list  *tmp2;

    if (ft_lstsize(*stack) < 2)
        return ;
    tmp = NULL;
    tmp2 = NULL;
    tmp = (*stack)->next;
    (*stack)->next = NULL;
    tmp2 = *stack;
    tmp2->next = tmp->next;
    tmp->next = tmp2;
    (*stack) = tmp;
    (*stack)->next = tmp2;
}

void    push(t_list **dest, t_list **src)
{
    t_list  *tmp;

    if (ft_lstsize(*src) < 1)
        return ;
    tmp = *src;
    *src = (*src)->next;
    tmp->next = NULL;
    if (dest != NULL)
        ft_lstadd_front(dest, tmp);
    else
        ft_lstadd_back(dest, tmp);
}

void    rotate(t_list **stack)
{
    t_list  *tmp;
    //addback the first elem
    tmp = *stack;
    //rotate -> set to next
    *stack = (*stack)->next;
    tmp->next = NULL;
    ft_lstadd_back(stack, tmp);
    //gg
}

void    del_last(t_list **stack)
{
    if (*stack == NULL)
        return ;
    if ((*stack)->next == NULL)
    {
        *stack = NULL;
        return ;
    }
    else
        del_last(&(*stack)->next);
}

void    reverse_rotate(t_list **stack)
{
    //get the last elem
    t_list *last = ft_lstlast(*stack);
    //delete last elem
    del_last(stack);
    //addfront last elem
    ft_lstadd_front(stack, last);
}