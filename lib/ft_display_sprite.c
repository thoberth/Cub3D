/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:56:03 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/31 15:44:11 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_display_sp_finish(t_list_map *map)
{
	int	i;

	i = 0;
	free(map->ray.sort);
	map->ray.sort = NULL;
	map->ray.nbr_sprite = 0;
	while (i < map->map.reso[0])
	{
		map->ray.is_sprite[i][0] = 0;
		map->ray.is_sprite[i][1] = 0;
		map->ray.is_sprite[i++][2] = 0;
	}
}

void	ft_display_sprite(t_list_map *map)
{
	int		a;
	int		i;

	a = 0;
	while (a < map->ray.nbr_sprite)
	{
		i = map->ray.sort[a++];
		map->tex.s_e_th[0] = map->ray.is_sprite[i][4] -
			(map->ray.is_sprite[i][5] / 2);
		if (map->tex.s_e_th[0] < 0)
			map->tex.s_e_pr[0] = 0;
		else
			map->tex.s_e_pr[0] = map->tex.s_e_th[0];
		map->tex.s_e_th[1] = map->ray.is_sprite[i][4] +
			(map->ray.is_sprite[i][5] / 2);
		if (map->tex.s_e_th[1] > map->map.reso[0])
			map->tex.s_e_pr[1] = map->map.reso[0];
		else
			map->tex.s_e_pr[1] = map->tex.s_e_th[1];
		ft_display_sprite2(map, i);
	}
	ft_display_sp_finish(map);
}
