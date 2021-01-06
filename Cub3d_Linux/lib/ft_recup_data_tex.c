/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup_data_tex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:30:18 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/17 16:20:23 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_verif_file_tex(t_list_map *map)
{
	int	i;

	i = ft_strlen(map->map.no) - 4;
	if (ft_strcmp(&map->map.no[i], ".xpm") != 0)
		ft_return_error(map, WRONG_FILECUB);
	i = ft_strlen(map->map.we) - 4;
	if (ft_strcmp(&map->map.we[i], ".xpm") != 0)
		ft_return_error(map, WRONG_FILECUB);
	i = ft_strlen(map->map.so) - 4;
	if (ft_strcmp(&map->map.so[i], ".xpm") != 0)
		ft_return_error(map, WRONG_FILECUB);
	i = ft_strlen(map->map.ea) - 4;
	if (ft_strcmp(&map->map.ea[i], ".xpm") != 0)
		ft_return_error(map, WRONG_FILECUB);
	i = ft_strlen(map->map.sprite) - 4;
	if (ft_strcmp(&map->map.sprite[i], ".xpm") != 0)
		ft_return_error(map, WRONG_FILECUB);
}

void	ft_recup_data_tex2(t_list_map *map)
{
	map->tex.imgea = mlx_xpm_file_to_image(map->data.mlx_ptr, map->map.ea,
		&map->tex.t_ea[0], &map->tex.t_ea[1]);
	if (map->tex.imgea == NULL)
		ft_return_error(map, WRONG_FILECUB);
	map->tex.texea = mlx_get_data_addr(map->tex.imgea, &map->tex.bpp,
		&map->tex.sizeline, &map->tex.endian);
	map->tex.imgs = mlx_xpm_file_to_image(map->data.mlx_ptr, map->map.sprite,
		&map->tex.t_s[0], &map->tex.t_s[1]);
	if (map->tex.imgs == NULL)
		ft_return_error(map, WRONG_FILECUB);
	map->tex.texs = mlx_get_data_addr(map->tex.imgs, &map->tex.bpp,
		&map->tex.sizeline, &map->tex.endian);
}

void	ft_recup_data_tex(t_list_map *map)
{
	ft_verif_file_tex(map);
	map->tex.imgno = mlx_xpm_file_to_image(map->data.mlx_ptr, map->map.no,
		&map->tex.t_no[0], &map->tex.t_no[1]);
	if (map->tex.imgno == NULL)
		ft_return_error(map, WRONG_FILECUB);
	map->tex.texno = mlx_get_data_addr(map->tex.imgno, &map->tex.bpp,
		&map->tex.sizeline, &map->tex.endian);
	map->tex.imgso = mlx_xpm_file_to_image(map->data.mlx_ptr, map->map.so,
		&map->tex.t_so[0], &map->tex.t_so[1]);
	if (map->tex.imgso == NULL)
		ft_return_error(map, WRONG_FILECUB);
	map->tex.texso = mlx_get_data_addr(map->tex.imgso, &map->tex.bpp,
		&map->tex.sizeline, &map->tex.endian);
	map->tex.imgwe = mlx_xpm_file_to_image(map->data.mlx_ptr, map->map.we,
		&map->tex.t_we[0], &map->tex.t_we[1]);
	if (map->tex.imgwe == NULL)
		ft_return_error(map, WRONG_FILECUB);
	map->tex.texwe = mlx_get_data_addr(map->tex.imgwe, &map->tex.bpp,
		&map->tex.sizeline, &map->tex.endian);
	ft_recup_data_tex2(map);
}
