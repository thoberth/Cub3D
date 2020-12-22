/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:59:20 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/21 17:11:32 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	init_bmpfile(t_bmp *bmp, t_list_map *map)
{
	bmp->bmp_fh.bf_type[0] = 'B';
	bmp->bmp_fh.bf_type[1] = 'M';
	bmp->bmp_fh.bf_sizefile = 54 + (map->map.reso[0] * map->map.reso[1] * 4);
	bmp->bmp_fh.bf_reserved1 = 0;
	bmp->bmp_fh.bf_reserved2 = 0;
	bmp->bmp_fh.bf_offset = 54;
}

void	init_bmpinfo(t_bmp *bmp, t_list_map *map)
{
	bmp->bmp_ih.bi_hsize = 40;
	bmp->bmp_ih.bi_width = map->map.reso[0];
	bmp->bmp_ih.bi_height = map->map.reso[1];
	bmp->bmp_ih.bi_planes = 1;
	bmp->bmp_ih.bi_bpp = 32;
	bmp->bmp_ih.bi_comp = 0;
	bmp->bmp_ih.bi_sizeimg = map->map.reso[0] * map->map.reso[1] * 4;
	bmp->bmp_ih.bi_ppmx = 0;
	bmp->bmp_ih.bi_ppmy = 0;
	bmp->bmp_ih.bi_clrused = 0;
	bmp->bmp_ih.bi_clrmajor = 0;
}

void	ft_save(t_list_map *map)
{
	int		i;
	int		t;
	int		fd;
	t_bmp	bmp;

	fd = 0;
	fd = ft_open(map, fd);
	init_bmpfile(&bmp, map);
	init_bmpinfo(&bmp, map);
	write(fd, &(bmp.bmp_fh.bf_type), 14);
	write(fd, &(bmp.bmp_ih), 40);
	i = map->map.reso[1];
	t = (map->map.reso[0] * 4);
	while (--i >= 0)
		write(fd, &map->data.data_addr[i * map->map.size_line], t);
	ft_close(map, fd);
}
