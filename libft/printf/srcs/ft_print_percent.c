/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:00:00 by student           #+#    #+#             */
/*   Updated: 2026/11/02 16:00:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
