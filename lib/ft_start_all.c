/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:59:00 by thoberth          #+#    #+#             */
/*   Updated: 2020/11/30 13:02:30 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_start_all(t_list_map *map)
{
	int		bpp;
	int		endian;

	bpp = 0;
	map->map.size_line = 0;
	endian = 0;
	map->data.mlx_ptr = mlx_init();
	map->data.win_ptr = mlx_new_window(map->data.mlx_ptr, map->map.reso[0],
		map->map.reso[1], "Cub3D");
	map->data.img_ptr = mlx_new_image(map->data.mlx_ptr, map->map.reso[0],
		map->map.reso[1]);
	map->data.data_addr = mlx_get_data_addr(map->data.img_ptr, &bpp,
		&map->map.size_line, &endian);
	ft_recup_data_tex(map);
	ft_init_var(map);
	ft_raycasting(map);
	ft_event(map);
	mlx_loop(map->data.mlx_ptr);
}