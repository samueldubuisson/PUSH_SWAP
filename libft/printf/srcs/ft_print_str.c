/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 11:18:59 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/14 16:23:08 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str(char *s, t_flags *f)
{
	int	count;
	int	len;
	int	i;

	count = 0;
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (f->dot && f->precision < len)
		len = f->precision;
	if (!f->minus)
		count += ft_pad(f->width - len, ' ');
	i = 0;
	while (i < len)
	{
		count += ft_putchar(s[i]);
		i++;
	}
	if (f->minus)
		count += ft_pad(f->width - len, ' ');
	return (count);
}
