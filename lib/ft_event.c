/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:01:27 by thoberth          #+#    #+#             */
/*   Updated: 2020/11/06 15:30:07 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

//fonction qui est appelé lorsque l'utlisateur utilise une touche au clavier.

float	ft_mod_angle2(float angle)
{
	if (angle > 360)
		angle -= 360;
	if (angle < 0)
		angle += 360;
	return (angle);
}

void	ft_mod_angle(int key, t_list_map *map)
{
	if (key == 123)
		map->plr.Angle_plr += 2;
	if (key == 124)
		map->plr.Angle_plr -= 2;
	if (map->plr.Angle_plr > 360)
		map->plr.Angle_plr -= 360;
	if (map->plr.Angle_plr < 0)
		map->plr.Angle_plr += 360;
	ft_raycasting(map);
}

void	ft_mod_pos(int key, t_list_map *map)
{
	float		tmpx;
	float 	tmpy;

	tmpx = map->plr.Vposx / map->map.Tcub;
	tmpy = map->plr.Vposy / map->map.Tcub;
	if (key == 13)
		map->plr.Vposy -= map->map.Tcub / 16;
	if (key == 0)
		map->plr.Vposx -= map->map.Tcub / 16;
	if (key == 1)
		map->plr.Vposy += map->map.Tcub / 16;
	if (key == 2)
		map->plr.Vposx += map->map.Tcub / 16;
	if (tmpx < map->plr.Vposx / map->map.Tcub)
		map->plr.PosplrX++;
	if (tmpx > map->plr.Vposx / map->map.Tcub)
		map->plr.PosplrX--;
	if (tmpy < map->plr.Vposy / map->map.Tcub)
		map->plr.PosplrY++;
	if (tmpy > map->plr.Vposy / map->map.Tcub)
		map->plr.PosplrY--;
	ft_raycasting(map);
	//ft_map2d(map);
}

int		close_window(t_list_map *map)
{
	// ne pas oubliez de free
	mlx_destroy_window(map->data.mlx_ptr, map->data.win_ptr);
	exit (1);
	return (0);
}

int		deal_key(int key, t_list_map *map)
{
	if (key == 53)
		close_window(map);
	if (key == 123 || key == 124)
		ft_mod_angle(key, map);
	if (key == 13 || key == 0 || key == 1 || key == 2)
		ft_mod_pos(key, map);
	return (0);
}

void	ft_event(t_list_map *map)
{
	mlx_key_hook(map->data.win_ptr, deal_key, map);
	mlx_hook(map->data.win_ptr, 2, 0, deal_key, map);
	mlx_hook(map->data.win_ptr, 3, 0, deal_key, map);
	mlx_hook(map->data.win_ptr, 17, 1L<<17, close_window, map);
}