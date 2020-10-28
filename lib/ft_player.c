/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berthetthomas <berthetthomas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:54:57 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/28 18:03:14 by berthetthom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_player(t_list_map *map)
{
	map->map.Tcub = 64;
	map->plr.Vposx = (map->plr.PosplrX * map->map.Tcub) + (map->map.Tcub / 2);
	map->plr.Vposy = (map->plr.PosplrY * map->map.Tcub) + (map->map.Tcub / 2);
}