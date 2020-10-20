/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:07:53 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/20 15:21:28 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libcub.h"

int main ()
{
	t_list_map	map;

	if (ft_init_map(&map, "fstmap.cub") == -1)
		return (-1);
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, map.reso[0], map.reso[1], "Cub3D");
	ft_map2d(&map);
	ft_event(&map);
	mlx_loop(map.mlx_ptr);
	return (0);
}

/*int bpp;
int size_line;
int endian;
bpp = 32; //bit par pixel = 32 car  4 caractere par pixel, 1 caractere = 8 pixel.. 8 * 4 = 32 
size_line = map.reso[0] * 4; // largeur utlisé dans mlx_new_images * 4
endian = 0; // toujours = 0 sur mac voir wiki */