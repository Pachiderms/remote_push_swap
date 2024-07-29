/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <tzizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:48:33 by tzizi             #+#    #+#             */
/*   Updated: 2024/07/10 16:26:26 by tzizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int check_input(char **arg)
{
    /*
    error -> display "Error\n" on std error outptut
    examples : arguments not only integers, INT_MIN>arg>INT_MAX, 
                arg[x] == arg[y] {x,y} -> argv[][] 
    */
    char   *tmp;
    while (*arg != 0)
    {
        //ft_printf("%s", *arg);
        tmp = *arg;
        while (*tmp)
        {
            if (!ft_isdigit(*tmp))
                return (-1);
            tmp++;
        }
        arg++;
    }
    return (1);
}

int is_sorted(int *s, int size)
{
    int     i;

    i = 0;
    while (i + 1 < size && s[i] < s[i + 1])
    {
        i++;
    }
    return (i == size - 1);
}