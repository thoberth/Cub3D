/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:52:36 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/16 13:07:50 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_write2d(t_list_ptr *ptr, t_list_map *map, int i, int t)
{
	int		cub_x;
	int		cub_y;
	int		j;
	int		a;

	cub_x = (((map->reso[0] / 4) * 4) / map->t_map_x);
	while (cub_x % 4 != 0)
		cub_x--;
	cub_y = ((map->reso[1] / 4) / map->t_map_y) * ((map->reso[0] / 4) * 4);
	j = (cub_y * i) + (cub_x * t);
	map->map[i][t] == '2' ? j += 1 : j;
	while (j < (cub_y * (i + 1)))
	{
		a = 0;
		while (a < cub_x)
		{
			ptr->data_addr_minimap[j] = (char)150;
			a += 4;
			j += 4;
		}
		j += ((map->reso[0] / 4) * 4) - (cub_x);
	}
}

void	ft_aff_map2d(t_list_ptr *ptr, t_list_map *map)
{
	int		i;
	int		t;

	i = 0;
	while (i < map->t_map_y)
	{
		t = 0;
		while (map->map[i][t])
		{
			if (map->map[i][t] == '1' || map->map[i][t] == '2')
				ft_write2d(ptr, map, i, t);
			t++;
		}
		i++;
	}
}

void	ft_map2d(t_list_ptr *ptr, t_list_map *map)
{
	int		bpp;
	int		size_line;
	int		endian;

	bpp = 32;
	size_line = (map->reso[0] / 4) * 4;
	endian = 0;
	ptr->img_ptr_minimap = mlx_new_image(ptr->mlx_ptr, map->reso[0] / 4,
		map->reso[1] / 4);
	ptr->data_addr_minimap = mlx_get_data_addr(ptr->img_ptr_minimap, &bpp,
		&size_line, &endian);
	ft_aff_map2d(ptr, map);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr,
		ptr->img_ptr_minimap, 0, 0);
}
