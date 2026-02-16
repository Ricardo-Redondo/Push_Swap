/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 21:52:27 by rsao-pay          #+#    #+#             */
/*   Updated: 2026/02/16 14:02:27 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_num(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

long	ft_atol(const char *ptr)
{
	long	sum;
	long	sign;

	sum = 0;
	sign = 1;
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			sign *= -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		sum = (sum * 10) + (*ptr - '0');
		if (sum * sign < INT_MIN || sum * sign > INT_MAX)
			return (INT_MAX + 1L);
		ptr++;
	}
	return (sign * sum);
}

int	ft_double_check(char **argv)
{
	int	i;
	int	j;
	int	len;

	len = ft_count_args(argv);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atol(argv[j]) == ft_atol(argv[i]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_parser(int argc, char **argv)
{
	char	**nums;
	int		i;
	int		j;
	long	tmp;

	i = 1;
	while (i < argc)
	{
		nums = ft_split(argv[i], ' ');
		j = 0;
		while (nums[j])
		{
			tmp = ft_atol(nums[j]);
			if (tmp > INT_MAX)
				send_error();
			if (ft_double_check(nums))
				send_error();
			if (!ft_check_num(nums[j]))
				send_error();
			j++;
		}
		ft_free_arr(nums);
		i++;
	}
}
