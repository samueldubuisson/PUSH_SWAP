/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:00:00 by student           #+#    #+#             */
/*   Updated: 2026/11/25 19:15:05 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_get_hex_base(int upper)
{
	if (upper)
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

static int	ft_get_hex_len(unsigned int n, t_flags *f)
{
	int	len;

	len = ft_nbrlen(n, 16);
	if (f->dot && f->precision == 0 && n == 0)
		return (0);
	if (f->dot && f->precision > len)
		len = f->precision;
	return (len);
}

static int	ft_print_hex_prefix(unsigned int n, t_flags *f, int upper)
{
	if (!f->hash || n == 0)
		return (0);
	if (upper)
		return (ft_putstr("0X"));
	return (ft_putstr("0x"));
}

int	ft_print_hex(unsigned int n, t_flags *f, int upper)
{
	int		count;
	int		len;
	int		prefix;
	char	*base;

	count = 0;
	base = ft_get_hex_base(upper);
	len = ft_get_hex_len(n, f);
	prefix = (f->hash && n != 0) * 2;
	if (!f->minus && (!f->zero || f->dot))
		count += ft_pad(f->width - len - prefix, ' ');
	count += ft_print_hex_prefix(n, f, upper);
	if (!f->minus && f->zero && !f->dot)
		count += ft_pad(f->width - len - prefix, '0');
	if (f->dot)
		count += ft_pad(f->precision - ft_nbrlen(n, 16), '0');
	if (!(f->dot && f->precision == 0 && n == 0))
		count += ft_putnbr_base(n, base);
	if (f->minus)
		count += ft_pad(f->width - len - prefix, ' ');
	return (count);
}
