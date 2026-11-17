/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:59:36 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/17 12:01:33 by sdubuiss         ###   ########.fr       */
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
