/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:34:17 by rsao-pay          #+#    #+#             */
/*   Updated: 2026/02/16 14:03:13 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

//	Parsing
int		ft_check_num(char *argv);
long	ft_atol(const char *ptr);
void	ft_parser(int argc, char **argv);
int		ft_double_check(char **argv);

//	Utils for link list
t_stack	*ft_new_node(int value);
void	ft_lstadd_back(t_stack **stack, int value);

// Initialization
t_stack	*ft_init(int argc, char **argv);
void	ft_set_index(t_stack *stack, int size);

//	Moves
void	ft_swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	ft_push(t_stack **from, t_stack **to);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

void	ft_rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	ft_rrotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//	Extras
void	send_error(void);
void	ft_free_list(t_stack **stack);
int		ft_count_args(char **argv);
char	**ft_split(char const *s, char c);
void	ft_free_arr(char **s);

//	Radix sort
//	Sorting
void	ft_sort_three(t_stack **stack);
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_sorter(t_stack **stack_a, t_stack **stack_b);

//	Sorting utils
int		ft_find_biggest_index(t_stack *stack);
int		ft_count_nodes(t_stack *stack);
int		ft_is_sorted(t_stack **stack);
int		ft_max_bits(int biggest_index);

#endif