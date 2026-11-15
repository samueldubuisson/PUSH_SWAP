/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 06:55:13 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/14 16:21:04 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_flags(t_flags *f)
{
	f->minus = 0;
	f->plus = 0;
	f->space = 0;
	f->zero = 0;
	f->hash = 0;
	f->width = 0;
	f->precision = 0;
	f->dot = 0;
}

static int	ft_parse_flags(const char *fmt, int i, t_flags *f)
{
	while (fmt[i] == '-' || fmt[i] == '+' || fmt[i] == ' '
		|| fmt[i] == '0' || fmt[i] == '#')
	{
		if (fmt[i] == '-')
			f->minus = 1;
		else if (fmt[i] == '+')
			f->plus = 1;
		else if (fmt[i] == ' ')
			f->space = 1;
		else if (fmt[i] == '0')
			f->zero = 1;
		else if (fmt[i] == '#')
			f->hash = 1;
		i++;
	}
	if (f->minus)
		f->zero = 0;
	return (i);
}

static int	ft_parse_width(const char *fmt, int i, t_flags *f, va_list *ap)
{
	if (fmt[i] == '*')
	{
		f->width = va_arg(*ap, int);
		if (f->width < 0)
		{
			f->minus = 1;
			f->width = -f->width;
			f->zero = 0;
		}
		i++;
	}
	else
	{
		while (fmt[i] >= '0' && fmt[i] <= '9')
		{
			f->width = f->width * 10 + (fmt[i] - '0');
			i++;
		}
	}
	return (i);
}

static int	ft_parse_precision(const char *fmt, int i, t_flags *f, va_list *ap)
{
	if (fmt[i] == '.')
	{
		f->dot = 1;
		i++;
		if (fmt[i] == '*')
		{
			f->precision = va_arg(*ap, int);
			if (f->precision < 0)
				f->dot = 0;
			i++;
		}
		else
		{
			while (fmt[i] >= '0' && fmt[i] <= '9')
			{
				f->precision = f->precision * 10 + (fmt[i] - '0');
				i++;
			}
		}
	}
	return (i);
}

int	ft_parse(const char *fmt, int i, t_flags *f, va_list *ap)
{
	i = ft_parse_flags(fmt, i, f);
	i = ft_parse_width(fmt, i, f, ap);
	i = ft_parse_precision(fmt, i, f, ap);
	return (i);
}
