/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:09:39 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/14 16:22:34 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_sign(long n, t_flags *f)
{
	if (n < 0)
		return (1);
	if (f->plus || f->space)
		return (1);
	return (0);
}

static void	ft_print_sign(long n, t_flags *f, int *count)
{
	if (n < 0)
		*count += ft_putchar('-');
	else if (f->plus)
		*count += ft_putchar('+');
	else if (f->space)
		*count += ft_putchar(' ');
}

static int	ft_get_int_len(t_flags *f, unsigned long nb)
{
	int	len;

	len = ft_nbrlen(nb, 10);
	if (f->dot && f->precision == 0 && nb == 0)
		return (0);
	if (f->dot && f->precision > len)
		len = f->precision;
	return (len);
}

int	ft_print_int(long n, t_flags *f)
{
	int				count;
	int				len;
	int				sign;
	unsigned long	nb;

	count = 0;
	sign = ft_get_sign(n, f);
	if (n < 0)
		nb = -n;
	else
		nb = n;
	len = ft_get_int_len(f, nb);
	if (!f->minus && (!f->zero || f->dot))
		count += ft_pad(f->width - len - sign, ' ');
	ft_print_sign(n, f, &count);
	if (!f->minus && f->zero && !f->dot)
		count += ft_pad(f->width - len - sign, '0');
	if (f->dot)
		count += ft_pad(f->precision - ft_nbrlen(nb, 10), '0');
	if (!(f->dot && f->precision == 0 && n == 0))
		count += ft_putnbr_base(nb, "0123456789");
	if (f->minus)
		count += ft_pad(f->width - len - sign, ' ');
	return (count);
}
