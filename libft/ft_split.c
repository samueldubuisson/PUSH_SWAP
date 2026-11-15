/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 07:21:33 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/10/22 14:19:57 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_copy_words(char	**tab, char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			len++;
			s++;
		}
		if (len)
		{
			tab[i] = malloc(len + 1);
			if (!tab[i])
				return (i);
			ft_memcpy(tab[i], s - len, len);
			tab[i][len] = '\0';
			i++;
		}
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	count;
	size_t	i;

	if (!s)
		return (NULL);
	count = ft_words_count(s, c);
	ret = malloc((count + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	i = ft_copy_words(ret, s, c);
	if (i != count)
	{
		while (i > 0)
			free(ret[--i]);
		free(ret);
		return (NULL);
	}
	ret[count] = NULL;
	return (ret);
}
