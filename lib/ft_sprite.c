/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:03:54 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/17 17:10:48 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_display_sprite(t_list_map *map, int i)
{
	float dist;

	dist = ft_dist_wall3(map,
		((map->ray.is_sprite[i][1] * map->map.tcub) + map->map.tcub / 2),
		(map->ray.is_sprite[i][2] * map->map.tcub) + map->map.tcub / 2) *
		cos((map->ray.fov / 2) * (M_PI / 180));
	dist = (map->map.tcub / dist) * map->ray.dist_to_pp;
}

void	ft_sprite(t_list_map *map)
{
	int i;
	int tmp[2];

	i = 0;
	tmp[0] = 0;
	tmp[1] = 0;
	while (++i < map->map.reso[0])
	{
		if (map->ray.is_sprite[i][0] == 1 &&
			tmp[0] != map->ray.is_sprite[i][1] &&
			tmp[1] != map->ray.is_sprite[i][2])
		{
			tmp[0] = map->ray.is_sprite[i][1];
			tmp[1] = map->ray.is_sprite[i][2];
			ft_display_sprite(map, i);
		}
	}
}
