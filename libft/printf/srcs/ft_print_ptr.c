/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:01:27 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/14 16:22:57 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_ptr(unsigned long ptr, t_flags *f)
{
	int	count;
	int	len;

	count = 0;
	if (ptr == 0)
	{
		len = 5;
		if (!f->minus)
			count += ft_pad(f->width - len, ' ');
		count += ft_putstr("(nil)");
		if (f->minus)
			count += ft_pad(f->width - len, ' ');
		return (count);
	}
	len = ft_nbrlen(ptr, 16) + 2;
	if (!f->minus)
		count += ft_pad(f->width - len, ' ');
	count += ft_putstr("0x");
	count += ft_putnbr_base(ptr, "0123456789abcdef");
	if (f->minus)
		count += ft_pad(f->width - len, ' ');
	return (count);
}
