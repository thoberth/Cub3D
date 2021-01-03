/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 14:59:00 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/17 16:14:31 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

int		ft_hook_for_screen(t_list_map *map)
{
	mlx_put_image_to_window(map->data.mlx_ptr, map->data.win_ptr,
		map->data.img_ptr, 0, 0);
	return (1);
}

void	ft_start_all(t_list_map *map, char *str)
{
	map->data.mlx_ptr = mlx_init();
	ft_init_map(map, str);	
	ft_recup_data_tex(map);
	ft_init_var(map);
	if (map->verif.save == 1)
		ft_raycasting(map);
	else
	{
		map->data.win_ptr = mlx_new_window(map->data.mlx_ptr, map->map.reso[0],
			map->map.reso[1], "Cub3D");
		ft_raycasting(map);
	}
	mlx_hook(map->data.win_ptr, 2, 1L << 0, deal_key, map);
	mlx_hook(map->data.win_ptr, 3, 1L << 1, do_nothing, (void*)0);
	mlx_hook(map->data.win_ptr, 33, 1L << 17, close_window, map);
	mlx_loop_hook(map->data.mlx_ptr, ft_hook_for_screen, map);
	mlx_loop(map->data.mlx_ptr);
}
