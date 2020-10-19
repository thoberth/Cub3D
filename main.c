/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:07:53 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/19 12:17:10 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libcub.h"

int main ()
{
	t_list_ptr	ptr;
	t_list_map	map;

	ft_init_ptr(&ptr);
	if (ft_init_map(&map, "fstmap.cub") == -1)
		return (-1);
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, map.reso[0], map.reso[1], "Cub3D");
	int bpp;
	int size_line;
	int endian;

	bpp = 32; //bit par pixel = 32 car  4 caractere par pixel, 1 caractere = 8 pixel.. 8 * 4 = 32 
	size_line = map.reso[0] * 4; // largeur utlisé dans mlx_new_images * 4
	endian = 0; // toujours = 0 sur mac voir wiki*/
	ft_map2d(&ptr, &map);
	ft_event(&ptr, &map);
	mlx_loop(ptr.mlx_ptr);
	return (0);
}