/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzizi <tzizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 12:50:02 by tzizi             #+#    #+#             */
/*   Updated: 2024/07/10 17:25:16 by tzizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 

# include "../printf/src/ft_printf.h"

typedef struct s_list
{
	void			*val;
	struct s_list	*next;
	int				index;
}   t_list;

//utils
int    *simplify_input(char **input, int input_size);
int get_steps(char **input);
int is_sorted(int *s, int size);

//sort
void	big_sort(t_list **s_a, t_list **s_b, int size, int steps);
void    small_sort(t_list **s_a, t_list **s_b);

int		push_swap(t_list *stack);
int		check_input(char **arg);
void    swap(t_list **stack);
void    push(t_list **dest, t_list **src);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void    display_lst(t_list *stack_a, t_list *stack_b);
void    display_lst_single(t_list *stack);
void    del_last(t_list **stack);

//call
void    call_ra(t_list **stack_a);
void    call_rb(t_list **stack_b);
void    call_rr(t_list **stack_a, t_list **stack_b);

void    call_rra(t_list **stack_a);
void    call_rrb(t_list **stack_b);
void    call_rrr(t_list **stack_a, t_list **stack_b);

//t_list
t_list	*ft_lstnew(void *_val, int _index);
void	ft_lstadd_front(t_list **stack, t_list *new);
int		ft_lstsize(t_list *stack);
t_list	*ft_lstlast(t_list *stack);
void	ft_lstadd_back(t_list **stack, t_list *new);

#endif