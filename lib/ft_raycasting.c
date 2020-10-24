/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:43:46 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/24 18:07:08 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_init_var(t_list_map *map)
{
	if (!(map->ray.dist = malloc(sizeof(int) * (map->map.reso[0]))))
		exit(1);
	map->ray.ang_next_ray = 60 / map->map.reso[0];
}

int		ft_iswall(t_list_map *map, int i, int t)
{
	if (map->map.map[i][t] == '1')
		return (-1);
	return (0);
}

void	ft_find_dist(t_list_map *map)
{
	int		i;
	float	left_ang;
	float	inc;
	
	left_ang = map->plr.Angle_plr + 30;
	i = 0;
	while (i < map->map.reso[0])
	{
		map->ray.dist[i] = ft_dist_wall(map);
		i++;
	}
}

void	ft_raycasting(t_list_map *map)
{
	int		bpp;
	int		size_line;
	int		endian;

	bpp = 32;
	size_line = map->map.reso[0] * 4;
	endian = 0;
	map->data.img_ptr = mlx_new_image(map->data.mlx_ptr, map->map.reso[0], map->map.reso[1]);
	map->data.data_addr = mlx_get_data_addr(map->data.img_ptr, &bpp, &size_line, &endian);
	ft_init_var(map);
	ft_find_dist(map);
}