/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:01:27 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/22 15:21:24 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

//fonction qui est appelé lorsque l'utlisateur utilise une touche au clavier.

void	ft_mod_angle(int key, t_list_map *map)
{
	if (key == 123)
		map->Angle_plr -= 2;
	if (key == 124)
		map->Angle_plr += 2;
	if (map->Angle_plr > 360)
		map->Angle_plr -= 360;
	if (map->Angle_plr < 0)
		map->Angle_plr += 360;
}

void	ft_mod_pos(int key, t_list_map *map)
{
	int		tmpx;
	int 	tmpy;

	tmpx = map->Vposx / map->Vcubx;
	tmpy = map->Vposy / map->Vcuby;
	if (key == 13)
		map->Vposy += map->Vcuby / 8;
	if (key == 0)
		map->Vposx += map->Vcubx / 8;
	if (key == 1)
		map->Vposy -= map->Vcuby / 8;
	if (key == 2)
		map->Vposx -= map->Vcubx / 8;
	if (tmpx < map->Vposx / map->Vcubx)
		map->PosplrX--;
	if (tmpx > map->Vposx / map->Vcubx)
		map->PosplrX++;
	if (tmpy < map->Vposy / map->Vcuby)
		map->PosplrY--;
	if (tmpy > map->Vposy / map->Vcuby)
		map->PosplrY++;
	ft_map2d(map);
}

int		close_window(t_list_map *map)
{
	// ne pas oubliez de free
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
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
	mlx_key_hook(map->win_ptr, deal_key, map);
	mlx_hook(map->win_ptr, 2, 0, deal_key, map);
	mlx_hook(map->win_ptr, 3, 0, deal_key, map);
	mlx_hook(map->win_ptr, 17, 1L<<17, close_window, map);
}