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

#include "../includes/push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	i = 0;
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while ((s11[i] || s22[i])
		&& (s11[i] == s22[i]))
		i++;
	return (s11[i] - s22[i]);
}

int ft_is_number(char *arg)
{
    int i;

    i = 0;
    if (arg[i] == '-' || arg[i] == '+')
        i++;
    while (arg[i] && ft_isdigit(arg[i]) != 0)
        i++;
    return (arg[i] == '\0' && ft_isdigit(arg[i - 1]));
}
int duplicates(char **args)
{
    int i;
    int j;

    i = 1;
    while (args[i])
    {
        j = 1;
        while (args[j])
        {
            if (j != i && ft_strcmp(args[i], args[j]) == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int ft_is_zero(char *arg)
{
    int i;

    i = 0;
    if (arg[i] == '-' || arg[i] == '+')
        i++;
    while (arg[i] && arg[i] == '0')
        i++;
    return (arg[i] == '\0');
}
int check_input(char **args)
{
    int i;

    int zeros;
    i = 1;
    zeros = 0;
    while (args[i])
    {
        if (!ft_is_number(args[i]))
        {
            printf("not a number %s\n", args[i]);
            return (0);
        }
        zeros += ft_is_zero(args[i]);
        i++;
    }
    if (duplicates(args))
    {
        printf("duplicates\n");
        return (0);
    }
    if (zeros > 1)
    {
        printf("zeros > 1 : %d\n", zeros);
        return (0);
    }
    return (1);
}

int is_sorted(t_list *s)
{
    if (!s)
        return (1);
    if (s->next != NULL)
    {
        if (s->next->index < s->index)
            return (0);
    }
    return (is_sorted(s->next));
}