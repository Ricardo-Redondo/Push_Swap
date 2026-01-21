/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 00:00:14 by rsao-pay          #+#    #+#             */
/*   Updated: 2026/01/19 13:58:03 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2 || (argc == 2 || !argv[1][0]))
		return (0);
	ft_parser(argc, argv);
	stack_a = ft_init(argc, argv);
	stack_b = NULL;
	if (!ft_is_sorted(&stack_a))
	{
		ft_set_index (stack_a, ft_count_nodes(stack_a));
		ft_sorter(&stack_a, &stack_b);
	}
	ft_free_list(&stack_a);
	ft_free_list(&stack_b);
	return (0);
}
