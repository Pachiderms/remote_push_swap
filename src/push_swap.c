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
    //*indexes = -1;
    if (*stack == NULL)
        return ;
    init_stack(&(*stack)->next, (parsed + 1), (indexes + 1));
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return (0);
    char    **parsed;
    t_list  *stack_a;
    t_list  *stack_b;
    int     *simplified;

    stack_a = NULL;
    stack_b = NULL;
    parsed = ft_split(argv[1], ' ');
    if (check_input(parsed) != 1)
    {
        ft_putendl_fd("Error", -1);
        return (0);
    }
    simplified = simplify_input(argv, argc);
    if (is_sorted(simplified, argc - 1) == 1)
    {
        free(stack_a);
        free(stack_b);
        free(simplified);
        return(0);
    }
    argv++;
    init_stack(&stack_a, argv, simplified);
    init_null_stack(&stack_b, ft_lstsize(stack_a));
    display_lst(stack_a, stack_b);
    if(argc - 1 <= 5)
        small_sort(&stack_a, &stack_b);
    else
        big_sort(&stack_a, &stack_b, argc - 1, get_steps(argv));
    display_lst(stack_a, stack_b);
    free(stack_a);
    free(stack_b);
    free(simplified);
    return (0);
}