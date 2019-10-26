/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arkim <arkim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:51:54 by arkim             #+#    #+#             */
/*   Updated: 2019/09/05 21:34:37 by arkim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>

# include <stdio.h>

# include "libft.h"

# define BUFF_SIZE 32
# define MAX_FD 4096

int		get_next_line(const int fd, char **line);

#endif
