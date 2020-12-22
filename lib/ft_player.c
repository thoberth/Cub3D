/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:54:57 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/17 17:12:07 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_player(t_list_map *map)
{
	map->map.tcub = 64;
	map->plr.vposx = (map->plr.posplrx * map->map.tcub) + (map->map.tcub / 2);
	map->plr.vposy = (map->plr.posplry * map->map.tcub) + (map->map.tcub / 2);
}
