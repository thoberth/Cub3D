/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:43:46 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/17 16:22:37 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_init_var(t_list_map *map)
{
	int		i;

	i = 0;
	map->map.Tcub = 64;
	map->plr.Vposx = (map->plr.PosplrX * map->map.Tcub) + (map->map.Tcub / 2);
	map->plr.Vposy = (map->plr.PosplrY * map->map.Tcub) + (map->map.Tcub / 2);
	map->ray.fov = 60;
	if (!(map->ray.dist = malloc(sizeof(float) * (map->map.reso[0]))))
		ft_return_error();
	if (!(map->ray.is_sprite = malloc(sizeof(int *) * (map->map.reso[0]))))
		ft_return_error();
	if (!(map->tex.wall_tex = malloc(sizeof(int *) * (map->map.reso[0]))))
		ft_return_error();
	while (i < map->map.reso[0])
	{
		if (!(map->tex.wall_tex[i] = malloc(sizeof(float) * (3))))
			ft_return_error();
		if (!(map->ray.is_sprite[i] = malloc(sizeof(float) * (4))))
			ft_return_error();
		map->ray.is_sprite[i][0] = 0;
		i++;
	}
	map->ray.dist_to_pp = (map->map.reso[1] / 2) /
		tan((map->ray.fov / 2) * (M_PI / 180));
	map->ray.ang_next_ray = map->ray.fov / map->map.reso[0];
}

int		ft_iswall(t_list_map *map, int t, int i, int v)
{
	t /= map->map.Tcub;
	i /= map->map.Tcub;
	if (map->ray.actual_ang >= 90 && map->ray.actual_ang <= 270 && v == 1)
		t -= 1;
	if (map->ray.actual_ang >= 0 && map->ray.actual_ang <= 180 && !v)
		i -= 1;
	if (t < 0 || i < 0)
		return (3);
	if (t > ((map->map.t_map_x - 1)) || i > ((map->map.t_map_y - 1)))
		return (3);
	if (map->map.map[i][t] == '2')
	{
		map->ray.tmp_sprite[0] = t;
		map->ray.tmp_sprite[1] = i;
		return (2);
	}
	if (map->map.map[i][t] == '1')
		return (1);
	return (0);
}

void	ft_find_dist(t_list_map *map)
{
	int		i;
	float	ang;

	i = 0;
	map->ray.actual_ang =
		ft_mod_angle2(map->plr.Angle_plr + (map->ray.fov / 2));
	ang = map->ray.fov / 2;
	while (i < map->map.reso[0])
	{
		map->ray.dist[i] = ft_dist_wall(map, i) * cos(ang * (M_PI / 180));
		i++;
		map->ray.actual_ang =
			ft_mod_angle2(map->ray.actual_ang - map->ray.ang_next_ray);
		ang -= map->ray.ang_next_ray;
	}
}

void	ft_raycasting(t_list_map *map)
{
	ft_find_dist(map);
	ft_display(map);
	ft_sprite(map);
	mlx_put_image_to_window(map->data.mlx_ptr, map->data.win_ptr,
		map->data.img_ptr, 0, 0);
}
