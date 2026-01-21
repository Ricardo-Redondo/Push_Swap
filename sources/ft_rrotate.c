/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 23:51:12 by rsao-pay          #+#    #+#             */
/*   Updated: 2026/01/19 13:56:13 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrotate(t_stack **stack)
{
	t_stack	*pos;
	t_stack	*prev;

	if (!*stack || !(*stack)->next)
		return ;
	pos = *stack;
	while (pos->next)
	{
		prev = pos;
		pos = pos->next;
	}
	pos->next = *stack;
	*stack = pos;
	prev->next = NULL;
}

void	rra(t_stack **stack_a)
{
	ft_rrotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	ft_rrotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
	write(1, "rrr\n", 4);
}
