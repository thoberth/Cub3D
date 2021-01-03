/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dist_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:59:58 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/28 12:25:48 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

float	ft_dist_wall3(t_list_map *map, float nx, float ny)
{
	float	result;

	result = sqrt(pow(map->plr.vposx - nx, 2) + pow(map->plr.vposy - ny, 2));
	return (result);
}

float	ft_dist_wallh(t_list_map *map, int i)
{
	float	ax;
	float	ay;

	ay = (int)(map->plr.vposy / map->map.tcub) * map->map.tcub;
	if ((map->ray.actual_ang < 360 && map->ray.actual_ang >= 180))
		ay += map->map.tcub;
	ax = map->plr.vposx + (map->plr.vposy - ay) /
		tan(map->ray.actual_ang * (M_PI / 180));
	if (ax < 0)
		ax = 0;
	if (ax > (map->map.tcub * map->map.t_map_x) - 1)
		ax = (map->map.tcub * map->map.t_map_x) - 1;
	if (ft_iswall(map, ax, ay, 0) == 1 || ft_iswall(map, ax, ay, 0) == 3)
	{
		map->tex.wall_tex[i][1] = ax;
		return (ft_dist_wall3(map, ax, ay));
	}
	if (ft_iswall(map, ax, ay, 0) == 2)
		ft_sprite(map, i);
	ft_calcul_deltah(map);
	return (ft_dist_wall2h(map, ax, ay, i));
}

float	ft_dist_wallv(t_list_map *map, int i)
{
	float	ax;
	float	ay;

	ax = (int)(map->plr.vposx / map->map.tcub) * map->map.tcub;
	if (!(map->ray.actual_ang > 90 && map->ray.actual_ang <= 270))
		ax += map->map.tcub;
	ay = map->plr.vposy + (map->plr.vposx - ax) *
		tan(map->ray.actual_ang * (M_PI / 180));
	if (ay < 0)
		ay = 0;
	if (ay > ((map->map.tcub * map->map.t_map_y) - 1))
		ay = (map->map.tcub * map->map.t_map_y) - 1;
	if (ft_iswall(map, ax, ay, 1) == 1 || ft_iswall(map, ax, ay, 1) == 3)
	{
		map->tex.wall_tex[i][2] = ay;
		return (ft_dist_wall3(map, ax, ay));
	}
	if (ft_iswall(map, ax, ay, 1) == 2)
		ft_sprite(map, i);
	ft_calcul_deltav(map);
	return (ft_dist_wall2v(map, ax, ay, i));
}

/*
** N = 0, S = 1, E = 2, W = 3
*/

float	ft_dist_wall(t_list_map *map, int i)
{
	float	a;
	float	b;

	a = ft_dist_wallv(map, i);
	b = ft_dist_wallh(map, i);
	if (a < b)
	{
		if (map->ray.actual_ang > 90 && map->ray.actual_ang < 270)
			map->tex.wall_tex[i][0] = 3;
		else
			map->tex.wall_tex[i][0] = 2;
		return (a);
	}
	if (map->ray.actual_ang > 0 && map->ray.actual_ang < 180)
		map->tex.wall_tex[i][0] = 0;
	else
		map->tex.wall_tex[i][0] = 1;
	return (b);
}
