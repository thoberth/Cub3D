/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:54:57 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/17 16:06:03 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_player(t_list_map *map)
{
	map->map.Tcub = 64;
	map->plr.Vposx = (map->plr.PosplrX * map->map.Tcub) + (map->map.Tcub / 2);
	map->plr.Vposy = (map->plr.PosplrY * map->map.Tcub) + (map->map.Tcub / 2);
}
