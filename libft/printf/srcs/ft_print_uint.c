/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:49:19 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/14 16:23:20 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_uint(unsigned int n, t_flags *f)
{
	int	count;
	int	len;

	count = 0;
	len = ft_nbrlen(n, 10);
	if (f->dot && f->precision == 0 && n == 0)
		len = 0;
	if (f->dot && f->precision > len)
		len = f->precision;
	if (!f->minus && (!f->zero || f->dot))
		count += ft_pad(f->width - len, ' ');
	if (!f->minus && f->zero && !f->dot)
		count += ft_pad(f->width - len, '0');
	if (f->dot)
		count += ft_pad(f->precision - ft_nbrlen(n, 10), '0');
	if (!(f->dot && f->precision == 0 && n == 0))
		count += ft_putnbr_base(n, "0123456789");
	if (f->minus)
		count += ft_pad(f->width - len, ' ');
	return (count);
}
