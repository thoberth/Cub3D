/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:07:53 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/13 15:29:19 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libcub.h"

//fonction qui est appelé lorsque l'utlisateur utilise une touche au clavier.
int		deal_key(int key, t_list_ptr *ptr)
{
	return (0);
}

//aff les lignes verticalles de la map
void 	display_map2(t_list_ptr *ptr, t_list_map *map)
{
	int i;
	int t;

	i = 0;
	while (i < map->reso[0] * 4 * map->reso[1])
	{
		t = 0;
		i += (map->reso[0] * 4) * (map->reso[1] / map->t_map_y);
		while (t < map->reso[0] * 4 && i < map->reso[0] * 4 * map->reso[1])
		{
			ptr->data_addr[++i] = (char)128;
			t++;
		}
	}
}

//aff les lignes horizontalles de la map
void	display_map(t_list_ptr *ptr, t_list_map *map)
{
	int i;
	int	t;
	// CHAR 0 1 2 3
	// CLR	B G R A
	i = 0;
	while (i < map->reso[0] * 4 * map->reso[1])
	{
		t = 0;
		i += (map->reso[0] / map->t_map_x) * 4;
		while (t < map->reso[0] * 4 && i < map->reso[0] * 4 * map->reso[1])
		{
			i += (map->reso[0] / map->t_map_x) * 4;
			ptr->data_addr[i] = (char)255;
			t++;
		}
	}
	display_map2(ptr, map);
}

int main ()
{
	t_list_ptr	ptr;
	t_list_map	map;

	ft_init_ptr(&ptr);
	if (ft_init_map(&map, "fstmap.cub") == -1)
		return(-1);
	ft_putnbr(map.t_map_x);
	ft_putchar('\n');
	ft_putnbr(map.t_map_y);
	ft_putchar('\n');
	ft_putnbr((map.reso[0] / map.t_map_x) * 4);
	ft_putchar('\n');
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
