/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <tzizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:50:06 by tzizi             #+#    #+#             */
/*   Updated: 2024/07/10 17:29:51 by tzizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft_free(t_list **sa, t_list **sb, int *s)
{
    free(sa);
    free(sb);
    free(s);
    return (0);
}

void    init_null_stack(t_list **stack, size_t size)
{
    if (size == 0)
    {
        stack = NULL;
        return ;
    }
    *stack = ft_lstnew(NULL, -1);
    if (*stack == NULL)
        return ;
    init_null_stack(&(*stack)->next, size - 1);
}

void    init_stack(t_list **stack, char **parsed, int *indexes)
{
    if (*indexes == -1)
    {
        *stack = NULL;
        return ;
    }
    *stack = ft_lstnew(*parsed, *indexes);
    if (*stack == NULL)
        return ;
    init_stack(&(*stack)->next, (parsed + 1), (indexes + 1));
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return (0);
    t_list  *stack_a;
    t_list  *stack_b;
    int     *simplified;

    stack_a = NULL;
    stack_b = NULL;
    if (!check_input(argv))
    {
        ft_putendl_fd("Error", 2);
        return (0);
    }
    simplified = simplify_input(argv, argc);
    argv++;
    init_stack(&stack_a, argv, simplified);
    init_null_stack(&stack_b, ft_lstsize(stack_a));
    if(argc - 1 <= 5)
        small_sort(&stack_a, &stack_b);
    else
        big_sort(&stack_a, &stack_b);
    display_lst_noindex(stack_a, stack_b);
    return (ft_free(&stack_a, &stack_b, simplified));
}
