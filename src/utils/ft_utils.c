/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 16:35:20 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/19 17:33:01 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_parse(char ***parse)
{
	int	i;
	int	j;

	i = 0;
	while (parse[i])
	{
		j = 0;
		while (parse[i][j])
		{
			free(parse[i][j]);
			j++;
		}
		free(parse[i]);
		i++;
	}
	free(parse);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
