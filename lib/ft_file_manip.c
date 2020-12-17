/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_manip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:17:36 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/17 16:27:54 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

int		ft_open(int fd)
{
	fd = open("img.bmp", O_WRONLY | O_CREAT | O_APPEND | O_TRUNC, 0644);
	if (fd == -1)
		ft_return_error();
	return (fd);
}

void	ft_close(int fd)
{
	fd = close(fd);
	if (fd == -1)
		ft_return_error();
}
