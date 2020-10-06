/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:07:53 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/06 14:50:25 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libcub.h"

//fonction qui est appelé lorsque l'utlisateur utilise une touche au clavier.
int		deal_key(int key, t_list_ptr *ptr)
{
	return (0);
}

void	put_tex(t_list_ptr *ptr)
{
	void *tex;
	char *dat;
	int	size = 64;
	int bpp = 32;
	int size_line = 64 * 4;
	int endian = 0;

	tex = mlx_xpm_file_to_image(ptr->mlx_ptr, "pics/redbrick.xpm", &size, &size);
	//dat = mlx_get_data_addr(tex, &bpp, &size_line, &endian);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, tex, 250, 250);
}

int main ()
{
	t_list_ptr	ptr;
	t_list_map	map;
	/*int			i;

	i = 0;
	ft_init_ptr(&ptr);
	i = ft_init_map(&map, "fstmap.cub");
	if (i == -1)
		return(-1);*/
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, 1000, 1000, "premier essai");
	int bpp;
	int size_line;
	int endian;
	int posx = 250;
	int posy = 250;

	bpp = 32; //bit par pixel = 32 car  4 caractere par pixel, 1 caractere = 8 pixel.. 8 * 4 = 32 
	size_line = 1000; // largeur utlisé dans mlx_new_images * 4
	endian = 0; // toujours = 0 sur mac voir wiki

	ptr.img_ptr = mlx_new_image(ptr.mlx_ptr, posx, posy); //stocke le depart de l'image (en haut a gauche)
	ptr.data_addr = mlx_get_data_addr(ptr.img_ptr, &bpp, &size_line, &endian); //utilise une str pour parcourir les octets de l'img
	//mlx_put_image_to_window(ptr.mlx_ptr, ptr.win_ptr, ptr.img_ptr, 250, 250);
	put_tex(&ptr);
	mlx_loop(ptr.mlx_ptr);
}

