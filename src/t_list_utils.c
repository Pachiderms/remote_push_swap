/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:43:15 by marvin            #+#    #+#             */
/*   Updated: 2024/07/11 17:43:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	ft_lstsize(t_list *stack)
{
	if (stack == NULL)
		return (0);
	else if (stack->next == NULL)
		return (1);
	else
		return (1 + ft_lstsize(stack->next));
}

t_list	*ft_lstnew(void *_val)
{
	t_list	*node;

    if (_val == NULL)
    {
        return (NULL);
    }
	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
    node->val = _val;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *stack)
{
	if (stack == NULL)
		return (NULL);
	else if (stack->next == NULL)
		return (stack);
	else
		return (ft_lstlast(stack->next));
}

void	ft_lstadd_front(t_list **stack, t_list *new)
{
	t_list	*temp;

	temp = *stack;
	*stack = new;
	new->next = temp;
}

void	ft_lstadd_back(t_list **stack, t_list *new)
{
	if (*stack == NULL)
		*stack = new;
	else
		ft_lstlast(*stack)->next = new;
}