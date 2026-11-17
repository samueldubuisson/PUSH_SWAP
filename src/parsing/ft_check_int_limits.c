/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_numbers_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 07:00:05 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/17 08:03:14 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_skip_prefix(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0')
		str++;
	return (str);
}

static int	ft_is_within_int_limits(char *str, int negative)
{
	char	*limit;
	int		i;

	if (negative)
		limit = "2147483648";
	else
		limit = "2147483647";
	i = 0;
	if (ft_strlen(str) < ft_strlen(limit))
		return (1);
	if (ft_strlen(str) > ft_strlen(limit))
		return (0);
	while (str[i])
	{
		if (str[i] > limit[i])
			return (0);
		if (str[i] < limit[i])
			return (1);
		i++;
	}
	return (1);
}

int	ft_check_int_limits(char ***numbers)
{
	int		i;
	int		j;
	int		negative;
	char	*str;

	i = 0;
	while (numbers[i])
	{
		j = 0;
		while (numbers[i][j])
		{
			negative = (numbers[i][j][0] == '-');
			str = ft_skip_prefix(numbers[i][j]);
			if (!ft_is_within_int_limits(str, negative))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
