/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:54:57 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/22 17:46:00 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_player(t_list_map *map)
{
	map->map.Vcubx = (map->map.reso[0] * 4) / map->map.t_map_x;
	while (map->map.Vcubx % 4 != 0)
		map->map.Vcubx--;
	map->map.Vcuby = map->map.reso[1] / map->map.t_map_y;
	map->plr.Vposx = (map->plr.PosplrX * map->map.Vcubx) + (map->map.Vcubx / 2);
	map->plr.Vposy = (map->plr.PosplrY * map->map.Vcuby) + (map->map.Vcuby / 2);
}