/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dist_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:59:58 by thoberth          #+#    #+#             */
/*   Updated: 2020/11/06 18:27:32 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

float		ft_dist_wall3(t_list_map *map, int nx, int ny)
{
	float result;

	result = sqrt(pow(map->plr.Vposx - nx, 2) + pow(map->plr.Vposy - ny, 2));
	return (result);
}

float 	ft_dist_wall2h(t_list_map *map, int ax, int ay)
{
	int		dx;
	int		dy;
	int		nx;
	int		ny;

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
	if (ft_iswall(map, nx / map->map.Tcub, ny / map->map.Tcub) == 1)
		return (ft_dist_wall3(map, nx , ny));
	return (ft_dist_wall2h(map, nx, ny));
}

float 	ft_dist_wall2v(t_list_map *map, int ax, int ay)
{
	int		dx;
	int		dy;
	int		nx;
	int		ny;

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
	if (ny < 0)
		ny = 0;
	if (ny > ((map->map.Tcub * map->map.t_map_y) - 1))
		ny = (map->map.Tcub * map->map.t_map_y) - 1;
	if (ft_iswall(map, nx / map->map.Tcub, ny / map->map.Tcub) == 1)
		return (ft_dist_wall3(map, nx, ny));
	return (ft_dist_wall2v(map, nx, ny));
}

float		ft_dist_wallh(t_list_map *map)
{
	int ay;
	int aygrid;
	int	ax;
	int axgrid;

	ay = (int)(map->plr.Vposy / map->map.Tcub) * map->map.Tcub;
	if (map->ray.actual_ang >= 0 && map->ray.actual_ang <= 180)
		ay -= 1;
	else
		ay += map->map.Tcub;
	ax = map->plr.Vposx + (map->plr.Vposy - ay) / tan(map->ray.actual_ang * (M_PI / 180));
	if (ax < 0)
		ax = 0;
	if (ax > (map->map.Tcub * map->map.t_map_x) - 1)
		ax = (map->map.Tcub * map->map.t_map_x) - 1;
	aygrid = ay / map->map.Tcub;
	axgrid = ax / map->map.Tcub;
	if (ft_iswall(map, axgrid, aygrid) == 1)
		return (ft_dist_wall3(map, ax, ay));
	return (ft_dist_wall2h(map, ax, ay));
}

float		ft_dist_wallv(t_list_map *map)
{
	int ay;
	int aygrid;
	int	ax;
	int axgrid;

	ax = (int)(map->plr.Vposx / map->map.Tcub) * map->map.Tcub;
	if (map->ray.actual_ang >= 90 && map->ray.actual_ang <= 270)
		ax -= 1;
	else
		ax += map->map.Tcub;
	ay = map->plr.Vposy + (map->plr.Vposx - ax) * tan(map->ray.actual_ang * (M_PI / 180));
	if (ay < 0)
		ay = 0;
	if (ay > ((map->map.Tcub * map->map.t_map_y) - 1))
		ay = (map->map.Tcub * map->map.t_map_y) - 1;
	axgrid = ax / map->map.Tcub;
	aygrid = ay / map->map.Tcub;
	if (ft_iswall(map, axgrid, aygrid) == 1)
		return (ft_dist_wall3(map, ax, ay));
	return (ft_dist_wall2v(map, ax, ay));
}

float		ft_dist_wall(t_list_map *map)
{
	float	a;
	float	b;

	a = ft_dist_wallv(map);
	b = ft_dist_wallh(map);
	if (a < b)
		return (a);
	return (b);
}