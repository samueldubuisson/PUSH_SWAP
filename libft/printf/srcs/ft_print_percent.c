/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 14:09:24 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/14 16:22:45 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_percent(t_flags *f)
{
	int	count;

	count = 0;
	if (!f->minus && !f->zero)
		count += ft_pad(f->width - 1, ' ');
	if (!f->minus && f->zero)
		count += ft_pad(f->width - 1, '0');
	count += ft_putchar('%');
	if (f->minus)
		count += ft_pad(f->width - 1, ' ');
	return (count);
}
