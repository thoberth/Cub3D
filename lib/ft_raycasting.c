/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:43:46 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/22 17:41:13 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_raycasting(t_list_map *map)
{
	int		bpp;
	int		size_line;
	int		endian;

	bpp = 32;
	size_line = map->map.reso[0] * 4;
	endian = 0;
	map->data.img_ptr = mlx_new_image(map->data.mlx_ptr, map->map.reso[0], map->map.reso[1]);
	map->data.data_addr = mlx_get_data_addr(map->data.img_ptr, &bpp, &size_line, &endian);
	
}