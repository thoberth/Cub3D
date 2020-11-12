/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dist_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:59:58 by thoberth          #+#    #+#             */
/*   Updated: 2020/11/12 21:08:12 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

float		ft_dist_wall3(t_list_map *map, float nx, float ny)
{
	float result;

	result = sqrt(pow(map->plr.Vposx - nx, 2) + pow(map->plr.Vposy - ny, 2));
	return (result);
}

float		ft_dist_wallh(t_list_map *map)
{
	float 	ay;
	float	ax;

	ay = (int)(map->plr.Vposy / map->map.Tcub) * map->map.Tcub;
	if (map->ray.actual_ang < 360 && map->ray.actual_ang > 180)
		ay += map->map.Tcub;
	ax = map->plr.Vposx + (map->plr.Vposy - ay) /
		tan(map->ray.actual_ang * (M_PI / 180));
	if (ax < 0)
		ax = 0;
	if (ax > (map->map.Tcub * map->map.t_map_x) - 1)
		ax = (map->map.Tcub * map->map.t_map_x) - 1;
	ft_putstr ("new = ");
	if (ft_iswall(map, ax, ay, 0) == 1)
		return (ft_dist_wall3(map, ax, ay));
	return (ft_dist_wall2h(map, ax, ay));
}

float		ft_dist_wallv(t_list_map *map)
{
	float 	ay;
	float	ax;

	ax = (int)(map->plr.Vposx / map->map.Tcub) * map->map.Tcub;
	if (!(map->ray.actual_ang >= 90 && map->ray.actual_ang <= 270))
		ax += map->map.Tcub;
	ay = map->plr.Vposy + (map->plr.Vposx - ax) *
		tan(map->ray.actual_ang * (M_PI / 180));
	if (ay < 0)
		ay = 0;
	if (ay > ((map->map.Tcub * map->map.t_map_y) - 1))
		ay = (map->map.Tcub * map->map.t_map_y) - 1;
	if (ft_iswall(map, ax, ay, 1) == 1)
		return (ft_dist_wall3(map, ax, ay));
	return (ft_dist_wall2v(map, ax, ay));
}

/*
// N = 0, S = 1, E = 2, W = 3 
*/
float		ft_dist_wall(t_list_map *map, int i)
{
	float	a;
	float	b;

	a = ft_dist_wallv(map);
	b = ft_dist_wallh(map);
	if (a < b)
	{
		if (map->ray.actual_ang > 90 && map->ray.actual_ang < 270)
			map->ray.wall_tex[i] = 2;
		else
			map->ray.wall_tex[i] = 3;
		return (a);
	}
	if (map->ray.actual_ang > 0 && map->ray.actual_ang < 180)
		map->ray.wall_tex[i] = 0;
	else
		map->ray.wall_tex[i] = 1;
	return (b);
}