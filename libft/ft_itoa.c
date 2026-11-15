/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 09:29:40 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/10/23 08:27:45 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	buffer[12];
	size_t	i;
	long	nb;

	nb = n;
	i = 11;
	buffer[i] = '\0';
	if (nb < 0)
		nb = -nb;
	if (nb == 0)
		buffer[--i] = '0';
	while (nb > 0)
	{
		buffer[--i] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		buffer[--i] = '-';
	return (ft_strdup(buffer + i));
}
