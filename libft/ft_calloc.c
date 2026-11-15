/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 06:15:32 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/10/21 06:55:38 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;
	size_t	n;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	n = nmemb * size;
	ret = malloc(n);
	if (!ret)
		return (NULL);
	ft_bzero(ret, n);
	return (ret);
}
