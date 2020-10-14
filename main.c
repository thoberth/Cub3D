/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:07:53 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/14 17:12:22 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libcub.h"

//fonction qui est appelé lorsque l'utlisateur utilise une touche au clavier.
int		deal_key(int key, t_list_ptr *ptr)
{
	ft_putnbr(key);
	return (0);
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
	/*int bpp;
	int size_line;
	int endian;

	bpp = 32; //bit par pixel = 32 car  4 caractere par pixel, 1 caractere = 8 pixel.. 8 * 4 = 32 
	size_line = map.reso[0] * 4; // largeur utlisé dans mlx_new_images * 4
	endian = 0; // toujours = 0 sur mac voir wiki*/

//	ptr.img_ptr = mlx_new_image(ptr.mlx_ptr, map.reso[0], map.reso[1]); //stocke le depart de l'image (en haut a gauche)
//	ptr.data_addr = mlx_get_data_addr(ptr.img_ptr, &bpp, &size_line, &endian); //utilise une str pour parcourir les octets de l'img
	printf("test");
	mlx_key_hook(ptr.win_ptr, deal_key, &ptr);
	mlx_loop(ptr.mlx_ptr);
	return (0);
}