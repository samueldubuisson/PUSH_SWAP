/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:00:00 by student           #+#    #+#             */
/*   Updated: 2026/11/02 16:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long ptr, t_flags *f)
{
	int	count;
	int	len;

	count = 0;
	len = ft_nbrlen(ptr, 16) + 2;
	if (ptr == 0)
		len = 3;
	if (!f->minus)
		count += ft_pad(f->width - len, ' ');
	count += ft_putstr("0x");
	if (ptr == 0)
		count += ft_putchar('0');
	else
		count += ft_putnbr_base(ptr, "0123456789abcdef");
	if (f->minus)
		count += ft_pad(f->width - len, ' ');
	return (count);
}
