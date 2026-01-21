/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:15:41 by rsao-pay          #+#    #+#             */
/*   Updated: 2026/01/19 13:57:19 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack **stack)
{
	int	biggest;

	biggest = ft_find_biggest_index(*stack);
	if ((*stack)->index == biggest)
		ra(stack);
	else if ((*stack)->next->index == biggest)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_count_nodes(*stack_a);
	while (size--)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	ft_sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	biggest_index;
	int	max_bits;
	int	i;
	int	j;

	biggest_index = ft_find_biggest_index(*stack_a);
	max_bits = ft_max_bits(biggest_index);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j <= biggest_index)
		{
			if ((*stack_a)->index >> i & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

void	ft_sorter(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_count_nodes(*stack_a);
	if (!ft_is_sorted(stack_a) && size <= 3)
		ft_sort_three(stack_a);
	else if (!ft_is_sorted(stack_a) && size <= 5)
		ft_sort_five(stack_a, stack_b);
	else if (!ft_is_sorted(stack_a))
		ft_radix_sort(stack_a, stack_b);
	else
	{
		free(stack_a);
		free(stack_b);
	}
}
