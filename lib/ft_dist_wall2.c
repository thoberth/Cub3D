/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dist_wall2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:03:14 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/17 16:43:47 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_calcul_deltah(t_list_map *map)
{
	if (map->ray.actual_ang >= 0 && map->ray.actual_ang <= 180)
	{
		map->ray.delta[0] = map->map.Tcub / tan(map->ray.actual_ang *
			(M_PI / 180));
		map->ray.delta[1] = -map->map.Tcub;
	}
	else
	{
		map->ray.delta[0] = -map->map.Tcub / tan(map->ray.actual_ang *
			(M_PI / 180));
		map->ray.delta[1] = map->map.Tcub;
	}
}

float	ft_dist_wall2h(t_list_map *map, float ax, float ay, int i)
{
	float	nx;
	float	ny;

	nx = ax + map->ray.delta[0];
	ny = ay + map->ray.delta[1];
	if (nx < 0)
		nx = 0;
	if (nx > (map->map.Tcub * map->map.t_map_x) - 1)
		nx = (map->map.Tcub * map->map.t_map_x) - 1;
	if (ft_iswall(map, nx, ny, 0) == 1 || ft_iswall(map, nx, ny, 0) == 3)
	{
		map->tex.wall_tex[i][1] = nx;
		return (ft_dist_wall3(map, nx, ny));
	}
	if (ft_iswall(map, ax, ay, 0) == 2)
	{
		map->ray.is_sprite[i][0] = 1;
		map->ray.is_sprite[i][1] = map->ray.tmp_sprite[0];
		map->ray.is_sprite[i][2] = map->ray.tmp_sprite[1];
	}
	return (ft_dist_wall2h(map, nx, ny, i));
}

void	ft_calcul_deltav(t_list_map *map)
{
	if (map->ray.actual_ang >= 90 && map->ray.actual_ang <= 270)
	{
		map->ray.delta[0] = -map->map.Tcub;
		map->ray.delta[1] = map->map.Tcub * tan(map->ray.actual_ang *
			(M_PI / 180));
	}
	else
	{
		map->ray.delta[0] = map->map.Tcub;
		map->ray.delta[1] = -map->map.Tcub * tan(map->ray.actual_ang *
			(M_PI / 180));
	}
}

float	ft_dist_wall2v(t_list_map *map, float ax, float ay, int i)
{
	float	nx;
	float	ny;

	nx = ax + map->ray.delta[0];
	ny = ay + map->ray.delta[1];
	ny = (ny < 0 ? 0 : ny);
	if (ny > ((map->map.Tcub * map->map.t_map_y) - 1))
		ny = (map->map.Tcub * map->map.t_map_y) - 1;
	if (ft_iswall(map, nx, ny, 1) == 1 || ft_iswall(map, nx, ny, 0) == 3)
	{
		map->tex.wall_tex[i][2] = ny;
		return (ft_dist_wall3(map, nx, ny));
	}
	if (ft_iswall(map, ax, ay, 1) == 2)
	{
		map->ray.is_sprite[i][0] = 1;
		map->ray.is_sprite[i][1] = map->ray.tmp_sprite[0];
		map->ray.is_sprite[i][2] = map->ray.tmp_sprite[1];
	}
	return (ft_dist_wall2v(map, nx, ny, i));
}
