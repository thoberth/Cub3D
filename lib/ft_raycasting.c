/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:43:46 by thoberth          #+#    #+#             */
/*   Updated: 2020/11/06 18:23:47 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_init_var(t_list_map *map)
{
	map->ray.FOV = 60;
	if (!(map->ray.dist = malloc(sizeof(float) * (map->map.reso[0]))))
		exit(1);
	map->ray.dist_to_pp = (map->map.reso[1] / 2) / tan((map->ray.FOV / 2) * (M_PI / 180));
	map->ray.ang_next_ray = map->ray.FOV / map->map.reso[0];
	map->ray.actual_ang = ft_mod_angle2(map->plr.Angle_plr + (map->ray.FOV / 2));
}

int		ft_iswall(t_list_map *map, int t, int i)
{
	if (map->map.map[i][t] == '1')
		return (1);
	return (0);
}

void	ft_find_dist(t_list_map *map)
{
	int		i;
	float	ang;

	i = 0;
	ang = map->ray.FOV / 2;
	while (i < map->map.reso[0])
	{
		map->ray.dist[i] = ft_dist_wall(map) * cos(ang * (M_PI /180));
		i++;
		map->ray.actual_ang = ft_mod_angle2(map->ray.actual_ang - map->ray.ang_next_ray);
		ang -= map->ray.ang_next_ray;
	}
}

void	ft_raycasting(t_list_map *map)
{
	int		bpp;
	int		endian;

	bpp = 0;
	map->map.size_line = 0;
	endian = 0;
	map->data.img_ptr = mlx_new_image(map->data.mlx_ptr, map->map.reso[0],
		map->map.reso[1]);
	map->data.data_addr = mlx_get_data_addr(map->data.img_ptr, &bpp,
		&map->map.size_line, &endian);
	ft_init_var(map);
	ft_find_dist(map);
	ft_display_cub(map);
	mlx_put_image_to_window(map->data.mlx_ptr, map->data.win_ptr,
		map->data.img_ptr, 0, 0);
}