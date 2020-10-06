/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:30:19 by thoberth          #+#    #+#             */
/*   Updated: 2020/09/18 11:35:59 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_1test(int fd, char **line, char **tmp)
{
	int		i;
	char	*ptr;

	if ((tmp[fd]) && (ft_test_if_n(tmp[fd]) > 0))
	{
		i = ft_test_if_n(tmp[fd]);
		ptr = tmp[fd];
		line[0] = ft_strdup_gnl(ptr, (i - 1));
		if (i <= ft_strlen(ptr))
		{
			tmp[fd] = ft_strdup_gnl(ptr + i, ft_strlen(ptr) - i);
			free(ptr);
			ptr = NULL;
		}
		return (1);
	}
	return (0);
}

int		ft_2test(char **line, char **tmp, int fd)
{
	if (tmp[fd] && ft_strlen(tmp[fd]) == 1 && tmp[fd][0] == '\n')
	{
		free(tmp[fd]);
		tmp[fd] = NULL;
		line[0] = ft_strdup_gnl("\0", 1);
		return (1);
	}
	return (0);
}

int		end(int fd, char **line, char **tmp)
{
	if (tmp[fd])
	{
		line[0] = ft_strdup_gnl(tmp[fd], ft_strlen(tmp[fd]));
		free(tmp[fd]);
		tmp[fd] = NULL;
	}
	else
		line[0] = ft_strdup_gnl("\0", 1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int				taille_lu;
	char			buf[BUFFER_SIZE + 1];
	static char		*tmp[OPEN_MAX];// tableau de string ou t[1] est le premier fd ouvert etc

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0
		|| read(fd, buf, 0) < 0)
		return (-1);
	if (ft_2test(line, tmp, fd) == 1)
		return (1);
	if (ft_1test(fd, line, tmp) == 1)
		return (1);
	while ((taille_lu = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[taille_lu] = '\0';
		if (tmp[fd])
			tmp[fd] = ft_strjoin_gnl(tmp[fd], buf, taille_lu);
		else
			tmp[fd] = ft_strdup_gnl(buf, taille_lu);
		if (ft_1test(fd, line, tmp) == 1)
			return (1);
	}
	return (end(fd, line, tmp));
}
