/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 08:22:58 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/14 16:21:16 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(char c, t_flags *f)
{
	int	count;

	count = 0;
	if (!f->minus)
		count += ft_pad(f->width - 1, ' ');
	count += ft_putchar(c);
	if (f->minus)
		count += ft_pad(f->width - 1, ' ');
	return (count);
}
