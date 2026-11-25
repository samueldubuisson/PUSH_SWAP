/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:00:00 by student           #+#    #+#             */
/*   Updated: 2026/11/25 19:22:46 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
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
