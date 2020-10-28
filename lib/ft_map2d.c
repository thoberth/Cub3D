/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berthetthomas <berthetthomas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 12:52:36 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/27 19:45:34 by berthetthom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_write2d(t_list_map *map, int i, int t)
{
	int		cub_x;
	int		cub_y;
	int		j;
	int		a;

	cub_x = map->map.size_line2d / map->map.t_map_x;
	cub_y = (map->map.reso_2d[1] / map->map.t_map_y) * map->map.size_line2d;
	j = (cub_y * i) + (cub_x * t) + map->map.size_line2d;
	map->map.map[i][t] == '2' ? j += 1 : j;
	while (j < (cub_y * (i + 1) - map->map.size_line2d))
	{
		a = 4;
		j += 4;
		while (a < (cub_x - 4))
		{
			map->data.data_addr_minimap[j] = (char)150;
			a += 4;
			j += 4;
		}
		j += 4;
		j += map->map.size_line2d - cub_x;
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

void	ft_find_reso_2d(t_list_map *map)
{
	int		verif;

	map->map.reso_2d[0] = map->map.reso[0] / 4;
	map->map.reso_2d[1] = map->map.reso[1] / 4;
	verif = 0;
	while (verif != 1)
	{
		if ((map->map.reso_2d[0] * 4) % map->map.t_map_x == 0)
		{
			if (((map->map.reso_2d[0] * 4) / map->map.t_map_x) % 4 == 0)
				verif = 1;
			else
				map->map.reso_2d[0]--;
		}
		else
			map->map.reso_2d[0]--;
	}
	while (verif != 0)
	{
		if (map->map.reso_2d[1] % map->map.t_map_y == 0)
			verif = 0;
		else
			map->map.reso_2d[1]--;
	}
}

void	ft_map2d(t_list_map *map)
{
	int		bpp;
	int		endian;

	bpp = 0;
	map->map.size_line2d = 0;
	endian = 0;
	map->data.img_ptr_minimap = mlx_new_image(map->data.mlx_ptr, map->map.reso_2d[0],
		map->map.reso_2d[1]);
	map->data.data_addr_minimap = mlx_get_data_addr(map->data.img_ptr_minimap, &bpp,
		&map->map.size_line2d, &endian);
	ft_aff_map2d(map);
	mlx_put_image_to_window(map->data.mlx_ptr, map->data.win_ptr,
		map->data.img_ptr_minimap, 0, 0);
}
