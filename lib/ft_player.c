/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:54:57 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/22 12:41:09 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_player(t_list_map *map)
{
	map->Vcubx = (map->reso[0] * 4) / map->t_map_x;
	while (map->Vcubx % 4 != 0)
		map->Vcubx--;
	map->Vcuby = map->reso[1] / map->t_map_y;
	map->Vposx = (map->PosplrX * map->Vcubx) + (map->Vcubx / 2);
	map->Vposy = (map->PosplrY * map->Vcuby) + (map->Vcuby / 2);
}