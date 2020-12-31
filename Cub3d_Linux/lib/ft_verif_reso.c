/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_reso.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:18:06 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/17 16:01:44 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_verif_reso(t_list_map *map)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	mlx_get_screen_size(map->data.mlx_ptr, &a, &b);
	b -= 50;
	map->map.reso[0] = (map->map.reso[0] > a ? a : map->map.reso[0]);
	map->map.reso[1] = (map->map.reso[1] > b ? b : map->map.reso[1]);
}
