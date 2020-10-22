/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:52:36 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/22 17:44:09 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_write2d(t_list_map *map, int i, int t)
{
	int		cub_x;
	int		cub_y;
	int		j;
	int		a;

	cub_x = (((map->map.reso[0] / 4) * 4) / map->map.t_map_x);
	while (cub_x % 4 != 0)
		cub_x--;
	cub_y = ((map->map.reso[1] / 4) / map->map.t_map_y) * ((map->map.reso[0] / 4) * 4);
	j = (cub_y * i) + (cub_x * t);
	map->map.map[i][t] == '2' ? j += 1 : j;
	while (j < (cub_y * (i + 1)))
	{
		a = 0;
		while (a < cub_x)
		{
			map->data.data_addr_minimap[j] = (char)150;
			a += 4;
			j += 4;
		}
		j += ((map->map.reso[0] / 4) * 4) - (cub_x);
	}
}
void	ft_aff_map2d(t_list_map *map)
{
	int		i;
	int		t;

	i = 0;
	while (i < map->map.t_map_y)
	{
		t = 0;
		while (map->map.map[i][t])
		{
			if (map->map.map[i][t] == '1' || map->map.map[i][t] == '2')
				ft_write2d(map, i, t);
			t++;
		}
		i++;
	}
	ft_write2d(map, map->plr.PosplrY, map->plr.PosplrX);
}

void	ft_map2d(t_list_map *map)
{
	int		bpp;
	int		size_line;
	int		endian;

	bpp = 32;
	size_line = (map->map.reso[0] / 4) * 4;
	endian = 0;
	map->data.img_ptr_minimap = mlx_new_image(map->data.mlx_ptr, map->map.reso[0] / 4,
		map->map.reso[1] / 4);
	map->data.data_addr_minimap = mlx_get_data_addr(map->data.img_ptr_minimap, &bpp,
		&size_line, &endian);
	ft_aff_map2d(map);
	mlx_put_image_to_window(map->data.mlx_ptr, map->data.win_ptr,
		map->data.img_ptr_minimap, 0, 0);
}
