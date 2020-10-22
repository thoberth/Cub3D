/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:59:00 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/22 17:41:28 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_start_all(t_list_map *map)
{
	ft_player(map);
	ft_map2d(map);
	ft_event(map);
	ft_raycasting(map);
	mlx_loop(map->data.mlx_ptr);
}