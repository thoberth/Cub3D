/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:01:27 by thoberth          #+#    #+#             */
/*   Updated: 2020/11/11 15:57:59 by thoberth         ###   ########.fr       */
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
	float	tmpx;
	float 	tmpy;
	int 	vitesse;

	tmpx = map->plr.Vposx / map->map.Tcub;
	tmpy = map->plr.Vposy / map->map.Tcub;
	vitesse = map->map.Tcub / 16;
	ft_mod_pos2(key, map, vitesse);
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

void	ft_launch_map2d(t_list_map *map)
{
	if (map->data.is_2d == 0)
	{
		map->data.is_2d = 1;
		ft_map2d(map);
	}
	else
	{
		map->data.is_2d = 0;
		ft_raycasting(map);
	}
}

int		deal_key1(int key, t_list_map *map)
{
	ft_putnbr(key);
	if (key == 1)
		ft_launch_map2d(map);
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
	mlx_key_hook(map->data.win_ptr, deal_key1, map);
	mlx_hook(map->data.win_ptr, 2, 1L<<0, deal_key, map);
	mlx_hook(map->data.win_ptr, 3, 1L<<1, deal_key, map);
	mlx_hook(map->data.win_ptr, 17, 1L<<17, close_window, map);
}