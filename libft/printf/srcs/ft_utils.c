/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 07:40:03 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/14 16:23:31 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_nbrlen(unsigned long n, int base)
{
	int	len;

	len = 1;
	while (n >= (unsigned long)base)
	{
		n /= base;
		len++;
	}
	return (len);
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	int	count;
	int	b;

	count = 0;
	b = ft_strlen(base);
	if (n >= (unsigned long)b)
		count += ft_putnbr_base(n / b, base);
	count += ft_putchar(base[n % b]);
	return (count);
}

int	ft_pad(int count, char c)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_putchar(c);
		i++;
	}
	if (count > 0)
		return (count);
	else
		return (0);
}
