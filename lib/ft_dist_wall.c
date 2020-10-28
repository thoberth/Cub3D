/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dist_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berthetthomas <berthetthomas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:59:58 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/28 19:03:59 by berthetthom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

int		ft_dist_wall2(t_list_map *map, int ax)
{
	int result;

	result = fabs(map->plr.Vposx - ax) / cos(map->ray.actual_ang * 57.29);
	return (result);
}

int 	ft_dist_wall3(t_list_map *map, int ax, int ay)
{
	int		dx;
	int		dy;
	int		nx;
	int		ny;

	if (map->ray.actual_ang > 0 && map->ray.actual_ang < 180)
		dy = -map->map.Tcub;
	else
		dy = map->map.Tcub;
	dx = map->map.Tcub / tan(map->ray.actual_ang * 57.29);
	nx = ax + dx;
	ny = ay + dy;
	ft_putnbr(ny);
	ft_putnbr(nx);
	if (ft_iswall(map, nx / map->map.Tcub, ny / map->map.Tcub) == '1')
		return (ft_dist_wall2(map, nx));
	return (ft_dist_wall3(map, nx, ny));
}

int		ft_dist_wallh(t_list_map *map)
{
	int ay;
	int aygrid;
	int	ax;
	int axgrid;

	ay = (int)(map->plr.Vposy / map->map.Tcub) * map->map.Tcub;
	if (map->ray.actual_ang > 0 && map->ray.actual_ang < 180)
		ay -= 1;
	else
		ay += map->map.Tcub;
	aygrid = ay / map->map.Tcub;
	ax = map->plr.Vposx + (map->plr.Vposy - ay) / tan(map->ray.actual_ang * (57.29));
	axgrid = ax / map->map.Tcub;
	if (ft_iswall(map, aygrid, axgrid) == '1')
		return (ft_dist_wall2(map, ax));
	return (ft_dist_wall3(map, ax, ay));
}

int		ft_dist_wallv(t_list_map *map)
{
	return (0);
}

int		ft_dist_wall(t_list_map *map)
{
	int		a;
	int		b;

	a = ft_dist_wallv(map);
	b = ft_dist_wallh(map);
	if (a < b)
		return (a);
	return (b);
}