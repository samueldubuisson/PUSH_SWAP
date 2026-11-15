/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 07:28:11 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/14 16:22:09 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	ft_dispatch(char c, t_flags *f, va_list *ap)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*ap, int), f));
	if (c == 's')
		return (ft_print_str(va_arg(*ap, char *), f));
	if (c == 'p')
		return (ft_print_ptr((unsigned long)va_arg(*ap, void *), f));
	if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(*ap, int), f));
	if (c == 'u')
		return (ft_print_uint(va_arg(*ap, unsigned int), f));
	if (c == 'x')
		return (ft_print_hex(va_arg(*ap, unsigned int), f, 0));
	if (c == 'X')
		return (ft_print_hex(va_arg(*ap, unsigned int), f, 1));
	if (c == '%')
		return (ft_print_percent(f));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flags	f;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			ft_init_flags(&f);
			i = ft_parse(format, i, &f, &ap);
			count += ft_dispatch(format[i], &f, &ap);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
