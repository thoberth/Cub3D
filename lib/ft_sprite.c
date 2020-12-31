/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:03:54 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/31 15:53:53 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_sort_sprite(t_list_map *map)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (!(map->ray.sort = malloc(sizeof(int) * map->ray.nbr_sprite)))
		ft_return_error(map, ERROR_MALLOC);
	while (i < map->map.reso[0])
	{
		if (map->ray.is_sprite[i][0] == 1)
			map->ray.sort[a++] = i;
		i++;
	}
	a = 0;
	while ((a + 1) < map->ray.nbr_sprite)
	{
		while (map->ray.is_sprite[map->ray.sort[a]][4] <
			map->ray.is_sprite[map->ray.sort[a + 1]][4])
		{
			i = map->ray.sort[a];
			map->ray.sort[a] = map->ray.sort[a + 1];
			map->ray.sort[a + 1] = i;
		}
		a++;
	}
}

void	ft_calcul_sprite_ang(t_list_map *map, int i)
{
	float	adjacent;
	float	pos_spx;
	float	pos_spy;

	pos_spx = ((map->ray.is_sprite[i][1] * map->map.tcub) + map->map.tcub / 2);
	pos_spy = ((map->ray.is_sprite[i][2] * map->map.tcub) + map->map.tcub / 2);
	if (map->plr.angle_plr > 90 && map->plr.angle_plr < 270)
		adjacent = map->plr.vposx - pos_spx;
	else
		adjacent = pos_spx - map->plr.vposx;
	map->ray.is_sprite[i][4] = acos(adjacent / map->ray.is_sprite[i][3]) *
		(180 / M_PI);
	if (map->plr.angle_plr > 90 && map->plr.angle_plr < 270)
	{
		if (map->plr.vposy > pos_spy)
			map->ray.is_sprite[i][4] = 180 - map->ray.is_sprite[i][4];
		else
			map->ray.is_sprite[i][4] += 180;
	}
	else if (map->plr.vposy < pos_spy)
		map->ray.is_sprite[i][4] = 360 - map->ray.is_sprite[i][4];
}

void	ft_dist_sprite(t_list_map *map, int i)
{
	float	calcul;

	calcul = 360 / map->ray.ang_next_ray;
	map->ray.is_sprite[i][3] = ft_dist_wall3(map,
		((map->ray.is_sprite[i][1] * map->map.tcub) + map->map.tcub / 2),
		(map->ray.is_sprite[i][2] * map->map.tcub) + map->map.tcub / 2);
	ft_calcul_sprite_ang(map, i);
	map->ray.is_sprite[i][4] =
		ft_mod_angle2((map->plr.angle_plr + map->ray.fov / 2)
		- map->ray.is_sprite[i][4]) / map->ray.ang_next_ray;
	if (map->ray.is_sprite[i][4] <= calcul &&
		map->ray.is_sprite[i][4] >= calcul - 360)
		map->ray.is_sprite[i][4] -= calcul;
}

void	ft_sprite(t_list_map *map, int i)
{
	int	a;
	int b;

	a = 0;
	b = 0;
	while (a < i)
	{
		if (map->ray.tmp_sprite[0] == map->ray.is_sprite[a][1] &&
			map->ray.tmp_sprite[1] == map->ray.is_sprite[a][2])
			b++;
		a++;
	}
	if (b == 0)
	{
		map->ray.is_sprite[i][1] = map->ray.tmp_sprite[0];
		map->ray.is_sprite[i][2] = map->ray.tmp_sprite[1];
		ft_dist_sprite(map, i);
		map->ray.is_sprite[i][0] = 1;
	}
}
