/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 20:17:46 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/17 13:41:36 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_valid_char(char *str, int pos)
{
	if (str[pos] >= '0' && str[pos] <= '9')
		return (1);
	if (pos == 0 && (str[pos] == '+' || str[pos] == '-')
		&& str[pos + 1] >= '0' && str[pos + 1] <= '9')
		return (1);
	return (0);
}

static int	ft_check_syntax(char ***numbers)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	while (numbers[i])
	{
		j = 0;
		while (numbers[i][j])
		{
			z = 0;
			while (numbers[i][j][z])
			{
				if (!ft_is_valid_char(numbers[i][j], z))
					return (0);
				z++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_parse_numbers(char ***numbers)
{
	if (!ft_check_syntax(numbers))
		return (0);
	if (!ft_check_int_limits(numbers))
		return (0);
	if (!ft_check_duplicates(numbers))
		return (0);
	return (1);
}
