/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup_data_tex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:30:18 by thoberth          #+#    #+#             */
/*   Updated: 2020/11/19 21:02:00 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_recup_data_tex(t_list_map *map)
{
	void	*img;

	img = mlx_xpm_file_to_image(map->data.mlx_ptr, map->map.no,
		&map->tex.t_no[0], &map->tex.t_no[1]);
	map->tex.texno = mlx_get_data_addr(img, &map->tex.bpp,
		&map->tex.sizeline, &map->tex.endian);
	img = mlx_xpm_file_to_image(map->data.mlx_ptr, map->map.so,
		&map->tex.t_so[0], &map->tex.t_so[1]);
	map->tex.texso = mlx_get_data_addr(img, &map->tex.bpp,
		&map->tex.sizeline, &map->tex.endian);
	img = mlx_xpm_file_to_image(map->data.mlx_ptr, map->map.we,
		&map->tex.t_we[0], &map->tex.t_we[1]);
	map->tex.texwe = mlx_get_data_addr(img, &map->tex.bpp,
		&map->tex.sizeline, &map->tex.endian);
    img = mlx_xpm_file_to_image(map->data.mlx_ptr, map->map.ea,
		&map->tex.t_ea[0], &map->tex.t_ea[1]);
	map->tex.texea = mlx_get_data_addr(img, &map->tex.bpp,
		&map->tex.sizeline, &map->tex.endian);
	img = mlx_xpm_file_to_image(map->data.mlx_ptr, map->map.sprite,
		&map->tex.t_s[0], &map->tex.t_s[1]);
	map->tex.texs = mlx_get_data_addr(img, &map->tex.bpp,
		&map->tex.sizeline, &map->tex.endian);
}
