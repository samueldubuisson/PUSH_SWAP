/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:13:58 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/17 12:02:13 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	***ft_parse_arguments(int argc, char *argv[])
{
	char	***parse;
	int		i;

	parse = ft_calloc(argc + 1, sizeof(char **));
	if (!parse)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		parse[i] = ft_split(argv[i], ' ');
		if (!parse[i])
		{
			free_parse(parse);
			return (NULL);
		}
		i++;
	}
	return (parse);
}
