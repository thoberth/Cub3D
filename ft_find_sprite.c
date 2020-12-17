/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 10:52:08 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/15 14:45:38 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

float   ft_find_sprite1h(t_list_map *map, int i)
{
	float	ax;
	float 	ay;

	ay = (int)(map->plr.Vposy / map->map.Tcub) * map->map.Tcub;
	if (map->ray.actual_ang < 360 && map->ray.actual_ang > 180)
		ay += map->map.Tcub;
	ax = map->plr.Vposx + (map->plr.Vposy - ay) /
		tan(map->ray.actual_ang * (M_PI / 180));
	if (ax < 0)
		ax = 0;
	if (ax > (map->map.Tcub * map->map.t_map_x) - 1)
		ax = (map->map.Tcub * map->map.t_map_x) - 1;
	if (ft_iswall(map, ax, ay, 0) == 2)
	{
		map->ray.is_sprite[i][0] = 1;
		map->ray.is_sprite[i][1] = ft_dist_wall3(map, ax, ay);
	}
	ft_calcul_deltah(map);
	return (ft_find_spriteh2(map, ax, ay, i));
}

float 	ft_find_sprite2h(t_list_map *map, float ax, float ay, int i)
{
	float		nx;
	float		ny;

	nx = ax + map->ray.delta[0];
	ny = ay + map->ray.delta[1];
	if (nx < 0)
		nx = 0;
	if (nx > (map->map.Tcub * map->map.t_map_x) - 1)
		nx = (map->map.Tcub * map->map.t_map_x) - 1;
	if (ft_iswall(map, ax, ay, 0) == 2)
	{
		map->ray.is_sprite[i][0] = 1;
		map->ray.is_sprite[i][1] = ft_dist_wall3(map, ax, ay);
	}
	return (ft_dist_wall2h(map, nx, ny, i));
}

float   ft_find_sprite(t_list_map *map, int i)
{
    float   a;
    float   b;

    a = ft_find_sprite1h(map, i);
    b = ft_find_spritev1(map, i);
    if (a < b)
        return (a);
    return (b);
}