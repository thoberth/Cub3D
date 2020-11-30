/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dist_wall2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 20:03:14 by thoberth          #+#    #+#             */
/*   Updated: 2020/11/18 12:49:49 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

float 	ft_dist_wall2h(t_list_map *map, float ax, float ay, int i)
{
	float		dx;
	float		dy;
	float		nx;
	float		ny;

	if (map->ray.actual_ang >= 0 && map->ray.actual_ang <= 180)
	{
		dy = -map->map.Tcub;
		dx = map->map.Tcub / tan(map->ray.actual_ang * (M_PI / 180));
	}
	else
	{
		dy = map->map.Tcub;
		dx = -map->map.Tcub / tan(map->ray.actual_ang * (M_PI / 180));
	}
	nx = ax + dx;
	ny = ay + dy;
	if (nx < 0)
		nx = 0;
	if (nx > (map->map.Tcub * map->map.t_map_x) - 1)
		nx = (map->map.Tcub * map->map.t_map_x) - 1;
	if (ft_iswall(map, nx, ny, 0) == 1)
	{
		map->tex.wall_tex[i][1] = nx;
		return (ft_dist_wall3(map, nx, ny));
	}
	return (ft_dist_wall2h(map, nx, ny, i));
}

float 	ft_dist_wall2v(t_list_map *map, float ax, float ay, int i)
{
	float		dx;
	float		dy;
	float		nx;
	float		ny;

	if (map->ray.actual_ang >= 90 && map->ray.actual_ang <= 270)
	{
		dx = -map->map.Tcub;
		dy = map->map.Tcub * tan(map->ray.actual_ang * (M_PI / 180));
	}
	else
	{
		dx = map->map.Tcub;
		dy = -map->map.Tcub * tan(map->ray.actual_ang * (M_PI / 180));
	}
	nx = ax + dx;
	ny = ay + dy;
	ny = (ny < 0 ? 0 : ny); 
	if (ny > ((map->map.Tcub * map->map.t_map_y) - 1))
		ny = (map->map.Tcub * map->map.t_map_y) - 1;
	if (ft_iswall(map, nx, ny, 1) == 1)
	{
		map->tex.wall_tex[i][2] = ny;
		return (ft_dist_wall3(map, nx, ny));
	}
	return (ft_dist_wall2v(map, nx, ny, i));
}