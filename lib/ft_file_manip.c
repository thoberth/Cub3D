/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_manip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:17:36 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/18 11:51:05 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

int		ft_open(t_list_map *map, int fd)
{
	fd = open("img.bmp", O_WRONLY | O_CREAT | O_APPEND | O_TRUNC, 0644);
	if (fd == -1)
		ft_return_error(map, ERROR_FILE_MANIP);
	return (fd);
}

void	ft_close(t_list_map *map, int fd)
{
	fd = close(fd);
	if (fd == -1)
		ft_return_error(map, ERROR_FILE_MANIP);
}
