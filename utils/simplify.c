/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <tzizi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:33:17 by tzizi            #+#    #+#             */
/*   Updated: 2024/07/29 11:33:17 by tzizi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int *to_int_list(char **input, int size)
{
    int i;
    int *copy;

    i = 1;
    copy = malloc((size) * sizeof(int));
    while (i < size)
    {
        copy[i - 1] = ft_atoi(input[i]);
        i++;
    }
    return(copy);
}

int    *simplify_input(char **input, int input_size)
{
    int i;
    int j;
    int index;
    int *copy;
    int *res;

    i = 0;
    copy = to_int_list(input, input_size);
    res = to_int_list(input, input_size);
    while (i < input_size - 1)
    {
        j = 0;
        index = 0;
        while (j < input_size - 1)
        {
            if (copy[i] > res[j])
            {
                index++;
            }
            j++;
        }
        copy[i] = index;
        i++;
    }
    copy[i] = -1;
    free(res);
    return (copy);
}