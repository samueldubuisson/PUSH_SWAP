/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_duplicates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 08:10:22 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/17 13:45:21 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_skip_prefix_two(char *str)
{
	int	negative;

	negative = (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0')
		str++;
	if (!*str)
		return ("0");
	if (negative)
	{
		*(str - 1) = '-';
		return (str - 1);
	}
	return (str);
}

static int	ft_compare_numbers(char *a, char *b)
{
	a = ft_skip_prefix_two(a);
	b = ft_skip_prefix_two(b);
	return (ft_strcmp(a, b) == 0);
}

static int	ft_check_current(char ***numbers, int i, int j)
{
	int	k;
	int	z;

	k = i;
	while (numbers[k])
	{
		z = 0;
		if (k == i)
			z = j + 1;
		while (numbers[k][z])
		{
			if (ft_compare_numbers(numbers[i][j], numbers[k][z]))
				return (0);
			z++;
		}
		k++;
	}
	return (1);
}

int	ft_check_duplicates(char ***numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		j = 0;
		while (numbers[i][j])
		{
			if (!ft_check_current(numbers, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
