/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:13:42 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/17 12:28:09 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_has_strategy(t_config *config)
{
	return (config->simple || config->medium
		|| config->complex || config->adaptive);
}

static int	ft_set_option(char *arg, t_config *config)
{
	if (!ft_strcmp(arg, "--bench") && !config->bench)
		return (config->bench = 1, 1);
	if (!ft_strcmp(arg, "--simple") && !ft_has_strategy(config))
		return (config->simple = 1, 1);
	if (!ft_strcmp(arg, "--medium") && !ft_has_strategy(config))
		return (config->medium = 1, 1);
	if (!ft_strcmp(arg, "--complex") && !ft_has_strategy(config))
		return (config->complex = 1, 1);
	if (!ft_strcmp(arg, "--adaptive") && !ft_has_strategy(config))
		return (config->adaptive = 1, 1);
	return (0);
}

char	***ft_parse_options(char ***parse, t_config *config)
{
	int	i;

	i = 0;
	while (parse[i] && parse[i][0]
		&& parse[i][0][0] == '-' && parse[i][0][1] == '-')
	{
		if (!ft_set_option(parse[i][0], config))
			return (NULL);
		i++;
		if (i > 2)
			return (NULL);
	}
	return (parse + i);
}
