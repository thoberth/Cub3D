/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:56:38 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/17 17:16:46 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

int		ft_detect_wall(t_list_map *map, int x, int y)
{
	x /= map->map.tcub;
	y /= map->map.tcub;
	if (map->map.map[y][x] == '1')
		return (1);
	return (0);
}
