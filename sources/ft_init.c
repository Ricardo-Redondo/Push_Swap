/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:39:25 by rsao-pay          #+#    #+#             */
/*   Updated: 2026/01/20 16:20:49 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_index(t_stack *stack, int size)
{
	t_stack	*max;
	t_stack	*tmp;

	while (size-- > 0)
	{
		max = NULL;
		tmp = stack;
		while (tmp)
		{
			if (!tmp->index && (max == NULL
					|| tmp->value > max->value))
				max = tmp;
			tmp = tmp->next;
		}
		if (max)
			max->index = size;
	}
}

t_stack	*ft_init(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**tmp;
	int		i;
	int		j;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		j = 0;
		while (tmp[j])
		{
			ft_lstadd_back(&stack_a, ft_atol(tmp[j]));
			j++;
		}
		ft_free_arr(tmp);
		i++;
	}
	(void)stack_a;
	return (stack_a);
}

void	ft_free_arr(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
