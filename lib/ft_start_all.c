/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berthetthomas <berthetthomas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:59:00 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/27 14:18:14 by berthetthom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_start_all(t_list_map *map)
{
	ft_player(map);
	ft_find_reso_2d(map);
	ft_map2d(map);
	ft_event(map);
	ft_raycasting(map);
	mlx_loop(map->data.mlx_ptr);
}