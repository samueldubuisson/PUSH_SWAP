/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:37:45 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/27 14:43:48 by spitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_complex(t_data *data)
{
	int order;
	int base;
	int i;

	order = 1;
	base = 2;
	i = 0;
	while (i < ft_stack_size(data->stack_a))
	{
		while (data->stack_a->value / order != 0)
			order = order * 2;
		i++;
	}
	while (order <= base)
	{
		i = 0;
		while (i < ft_stack_size(data->stack_a))
		{
			if (data->stack_a->value % 2 == 0)
				pb(data);
			else
				ra(data);
			i++;
		}
		while (i-- > 0)
			pa(data);
	}
}

/* Pour trouver nombre d'itera(data)tions
 * Pour chaque element de la liste,
 * 	jusqu'a ce que le quotient de sa valeur pa(data)r l'ordre soit egal a zero
 * 		doubler l'ordre
 * 		augmenter nbit
 * 		
 * ensuite, on remet l'ordre a 2
 * Tant que order <= base
 *	 Pour chaque element dans la liste
 *	 	Si le reste pa(data)r l'ordre est egal a 0
 *	 		push b
 *	 	Sinon
 *	 		rotate a
 *Si l'ordre
 */
