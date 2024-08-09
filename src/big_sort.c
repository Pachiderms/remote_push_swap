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

int get_steps(char **input)
{
    int     max_steps;

    max_steps = 0;
    input++;
    while (*input)
    {
        if ((int)ft_strlen(*input) > max_steps)
            max_steps = (int)ft_strlen(*input);
        input++;
    }
    return (max_steps);
}

void    step(t_list **s_a, t_list **s_b, int step)
{
    if(*s_a == NULL)
        return ;
    else
    {
        if(((*s_a)->index & step) == 0)
        {
            push(s_b, s_a);
            ft_putendl_fd("pb", 1);
        }
        else
        {
            call_ra(s_a);
        }
    }
}

int ft_pow(int i)
{
    if (i == 0)
        return (1);
    else
        return (2 * ft_pow(i - 1));
}

void    big_sort(t_list **s_a, t_list **s_b, int size, int steps)
{
    int i;
    int j;
    
    j = 0;
    while (j < steps)
    {
        i = size;
        while (i-- > 0)
            step(s_a, s_b, ft_pow(j));
        while (*s_b != NULL)
        {
            push(s_a, s_b);
            ft_putendl_fd("pa", 1);
        }
        j++;
    }
}