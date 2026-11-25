/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdubuiss <sdubuiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:23:34 by sdubuiss          #+#    #+#             */
/*   Updated: 2026/11/12 14:19:31 by sdubuiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	ft_line_len(t_list *lst)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (lst)
	{
		j = 0;
		while (j < (size_t) lst->len)
		{
			i++;
			if (lst->buf[j] == '\n')
				return (i);
			j++;
		}
		lst = lst->next;
	}
	return (i);
}

static char	*copy_lst(t_list *lst, size_t size)
{
	size_t	i;
	size_t	j;
	char	*ret;

	ret = malloc(size + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < size && lst)
	{
		j = 0;
		while (j < (size_t) lst->len && i < size)
		{
			ret[i] = lst->buf[j];
			i++;
			j++;
		}
		lst = lst->next;
	}
	ret[i] = '\0';
	return (ret);
}

int	ft_build_lst(t_list **lst, int fd)
{
	t_list	*new;

	if (*lst && ft_memchr((*lst)->buf, '\n', (*lst)->len))
		return (1);
	while (1)
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return (-1);
		new->next = NULL;
		new->len = read(fd, new->buf, BUFFER_SIZE);
		if (new->len == -1)
		{
			free(new);
			return (-1);
		}
		if (!(new->len))
		{
			free(new);
			return (2);
		}
		ft_lstadd_back(lst, new);
		if (ft_memchr(new->buf, '\n', new->len))
			return (1);
	}
}

static void	ft_rebuild_lst(t_list **lst)
{
	t_list	*tmp;
	char	*stock;
	size_t	len;
	size_t	i;

	while ((*lst)->next)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	stock = ft_memchr((*lst)->buf, '\n', (*lst)->len);
	stock++;
	i = stock - (*lst)->buf;
	len = (*lst)->len - i;
	ft_memmove((*lst)->buf, stock, len);
	if (len == 0)
	{
		free(*lst);
		*lst = NULL;
		return ;
	}
	(*lst)->len = len;
}

char	*get_next_line(int fd)
{
	static t_list	*lst[1024];
	int				ret;
	char			*line;
	size_t			size;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	ret = ft_build_lst(&lst[fd], fd);
	if (ret == 2 && !lst[fd])
		return (NULL);
	if (ret == -1)
	{
		ft_lstclear(&lst[fd]);
		return (NULL);
	}
	size = ft_line_len(lst[fd]);
	line = copy_lst(lst[fd], size);
	if (!line)
		return (NULL);
	if (ret == 2)
		ft_lstclear(&lst[fd]);
	else if (ret == 1)
		ft_rebuild_lst(&lst[fd]);
	return (line);
}
