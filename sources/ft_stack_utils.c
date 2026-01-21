/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:21:58 by rsao-pay          #+#    #+#             */
/*   Updated: 2026/01/19 13:59:49 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_stack **stack, int value)
{
	t_stack	*pos;
	t_stack	*node;

	if (!*stack)
		*stack = ft_new_node(value);
	else
	{
		pos = *stack;
		while (pos->next)
			pos = pos->next;
		node = ft_new_node(value);
		pos->next = node;
	}
}
