/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 11:43:46 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/31 15:31:21 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_init_var(t_list_map *map)
{
	int		i;

	i = 0;
	map->map.tcub = 64;
	map->plr.vposx = (map->plr.posplrx * map->map.tcub) + (map->map.tcub / 2);
	map->plr.vposy = (map->plr.posplry * map->map.tcub) + (map->map.tcub / 2);
	map->ray.fov = 60;
	if (!(map->ray.dist = malloc(sizeof(float) * (map->map.reso[0]))))
		ft_return_error(map, ERROR_MALLOC);
	if (!(map->ray.is_sprite = malloc(sizeof(float *) * (map->map.reso[0]))))
		ft_return_error(map, ERROR_MALLOC);
	if (!(map->tex.wall_tex = malloc(sizeof(float *) * (map->map.reso[0]))))
		ft_return_error(map, ERROR_MALLOC);
	while (i < map->map.reso[0])
	{
		if (!(map->tex.wall_tex[i] = malloc(sizeof(float) * (3))))
			ft_return_error(map, ERROR_MALLOC);
		if (!(map->ray.is_sprite[i] = malloc(sizeof(float) * (6))))
			ft_return_error(map, ERROR_MALLOC);
		i++;
	}
	map->ray.dist_to_pp = (map->map.reso[1] / 2) /
		tan((map->ray.fov / 2) * (M_PI / 180));
	map->ray.ang_next_ray = (float)map->ray.fov / (float)map->map.reso[0];
}

int		ft_iswall(t_list_map *map, int t, int i, int v)
{
	t /= map->map.tcub;
	i /= map->map.tcub;
	if (map->ray.actual_ang >= 90 && map->ray.actual_ang <= 270 && v == 1)
		t -= 1;
	if (map->ray.actual_ang >= 0 && map->ray.actual_ang <= 180 && !v)
		i -= 1;
	if (t < 0 || i < 0)
		return (3);
	if (t > ((map->map.t_map_x - 1)) || i > ((map->map.t_map_y - 1)))
		return (3);
	if (map->map.map[i][t] == '2')
	{
		map->ray.tmp_sprite[0] = t;
		map->ray.tmp_sprite[1] = i;
		return (2);
	}
	if (map->map.map[i][t] == '1')
		return (1);
	return (0);
}

void	ft_init_sprite_array(t_list_map *map, int i)
{
	map->ray.is_sprite[i][0] = 0;
	map->ray.is_sprite[i][1] = 0;
	map->ray.is_sprite[i][2] = 0;
}

void	ft_find_dist(t_list_map *map)
{
	int		i;
	float	ang;

	i = 0;
	map->ray.actual_ang =
		ft_mod_angle2(map->plr.angle_plr + (map->ray.fov / 2));
	ang = map->ray.fov / 2;
	map->ray.nbr_sprite = 0;
	while (i < map->map.reso[0])
	{
		ft_init_sprite_array(map, i);
		map->ray.dist[i] = ft_dist_wall(map, i) * cos(ang * (M_PI / 180));
		if (map->ray.is_sprite[i][0] == 1)
		{
			map->ray.nbr_sprite++;
			map->ray.is_sprite[i][5] = map->ray.dist_to_pp *
				(map->map.tcub / map->ray.is_sprite[i][3]);
		}
		i++;
		map->ray.actual_ang =
			ft_mod_angle2(map->ray.actual_ang - map->ray.ang_next_ray);
		ang -= map->ray.ang_next_ray;
	}
	ft_display(map);
}

void	ft_raycasting(t_list_map *map)
{
	int		bpp;
	int		endian;

	if (map->verif.save == 0)
		mlx_clear_window(map->data.mlx_ptr, map->data.win_ptr);
	if (map->data.img_ptr == NULL)
	{
		map->data.img_ptr = mlx_new_image(map->data.mlx_ptr, map->map.reso[0],
			map->map.reso[1]);
		map->data.data_addr = mlx_get_data_addr(map->data.img_ptr, &bpp,
			&map->map.size_line, &endian);
	}
	ft_find_dist(map);
	if (map->ray.nbr_sprite > 0)
	{
		ft_sort_sprite(map);
		ft_display_sprite(map);
	}
	if (map->verif.save == 1)
	{
		ft_save(map);
		ft_return_error(map, SAVE);
	}
	mlx_put_image_to_window(map->data.mlx_ptr, map->data.win_ptr,
		map->data.img_ptr, 0, 0);
}
