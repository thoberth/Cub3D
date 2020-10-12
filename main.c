/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:07:53 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/12 16:59:01 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libcub.h"

//fonction qui est appelé lorsque l'utlisateur utilise une touche au clavier.
int		deal_key(int key, t_list_ptr *ptr)
{
	return (0);
}

void	display_map(t_list_ptr *ptr, t_list_map *map)
{
	int i = 0;
	// CHAR 0 1 2 3
	// CLR	B G R A
	while (i < map->reso[0] * 4 * map->reso[1])
	{
		ptr->data_addr[i] = 0x66;
		i += (map->reso[0] / map->t_map_x) * 4;
	}
	i = 0;
	while (i < map->reso[0] * 4 * map->reso[1])
	{
		i += (map->reso[0] * 4) * (map->reso[1] / map->t_map_y);
		for (int t = 0 ; t < map->reso[0] * 4 && i < map->reso[0] * 4 * map->reso[1] ; t++)
			ptr->data_addr[i++] = 0x66;
	}

	
}

int main ()
{
	t_list_ptr	ptr;
	t_list_map	map;

	ft_init_ptr(&ptr);
	if (ft_init_map(&map, "fstmap.cub") == -1)
		return(-1);
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, map.reso[0], map.reso[1], "Cub3D");
	int bpp;
	int size_line;
	int endian;

	bpp = 32; //bit par pixel = 32 car  4 caractere par pixel, 1 caractere = 8 pixel.. 8 * 4 = 32 
	size_line = map.reso[0] * 4; // largeur utlisé dans mlx_new_images * 4
	endian = 0; // toujours = 0 sur mac voir wiki

	ptr.img_ptr = mlx_new_image(ptr.mlx_ptr, map.reso[0], map.reso[1]); //stocke le depart de l'image (en haut a gauche)
	ptr.data_addr = mlx_get_data_addr(ptr.img_ptr, &bpp, &size_line, &endian); //utilise une str pour parcourir les octets de l'img
	display_map(&ptr, &map);
	mlx_put_image_to_window(ptr.mlx_ptr, ptr.win_ptr, ptr.img_ptr, 0, 0);
	mlx_loop(ptr.mlx_ptr);
	return (0);
}
