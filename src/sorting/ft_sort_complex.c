/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:37:45 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/24 17:42:45 by spitte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_complex(t_data *data)
{
	int order;
	int base;
	int nbit;

	nbit = 1;
	order = 2;
	base = 2;
	while (data->stack_a)
	{
		while (data->stack_a->value / order != 0)
		{
			order = order * 2;
			nbit ++;
		}
		data = data->stack_a->next;
	}

}

/* Pour trouver nombre d'iterations
 * Pour chaque element de la liste,
 * 	jusqu'a ce que le quotient de sa valeur par l'ordre soit egal a zero
 * 		doubler l'ordre
 * 		augmenter nbit
 * 		
 * ensuite, on remet l'ordre a 2
 * Tant que order <= base
 *	 Pour chaque element dans la liste
 *	 	Si le reste par l'ordre est egal a 0
 *	 		push b
 *	 	Sinon
 *	 		rotate a
 *      
 *     /
