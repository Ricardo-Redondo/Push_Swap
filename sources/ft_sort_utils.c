/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:18:53 by rsao-pay          #+#    #+#             */
/*   Updated: 2026/01/19 13:58:35 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_biggest_index(t_stack *stack)
{
	int		biggest;
	t_stack	*tmp;

	biggest = INT_MIN;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > biggest)
			biggest = tmp->index;
		tmp = tmp->next;
	}
	return (biggest);
}

int	ft_count_nodes(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	ft_is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_max_bits(int biggest_index)
{
	int	max_bits;

	max_bits = 0;
	while (biggest_index > 0)
	{
		biggest_index >>= 1;
		max_bits++;
	}
	return (max_bits);
}
