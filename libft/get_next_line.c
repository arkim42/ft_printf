/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 22:14:08 by arkim             #+#    #+#             */
/*   Updated: 2019/08/12 17:57:49 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		find_endl(char **res, char **line)
{
	char	*tmp;
	int		len;

	len = 0;
	while ((*res)[len] != '\0' && (*res)[len] != '\n')
		len++;
	if ((*res)[len] == '\n')
	{
		*line = ft_strsub(*res, 0, len);
		len++;
		tmp = ft_strdup((*res) + len);
		free(*res);
		*res = tmp;
		if ((*res)[0] == '\0')
			ft_strdel(res);
	}
	else
	{
		*line = ft_strdup(*res);
		ft_strdel(res);
	}
	return (1);
}

static int		func(const int fd, int size, char **res, char **line)
{
	if (ft_strchr(*res, '\n') || size == 0)
		return (find_endl(res, line));
	else if (size > 0)
		return (get_next_line(fd, line));
	else
		return (-1);
}

int				get_next_line(const int fd, char **line)
{
	int			size;
	static char	*res[MAX_FD];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	if ((size = read(fd, buff, BUFF_SIZE)) < 0)
		return (-1);
	buff[size] = '\0';
	if (res[fd] == NULL)
		res[fd] = ft_strdup(buff);
	else
	{
		tmp = ft_strjoin(res[fd], buff);
		free(res[fd]);
		res[fd] = tmp;
	}
	if (size == 0 && res[fd][0] == '\0')
		return (0);
	return (func(fd, size, &res[fd], line));
}
