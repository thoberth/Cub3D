/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:01:27 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/22 18:13:34 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

//fonction qui est appelé lorsque l'utlisateur utilise une touche au clavier.

void	ft_mod_angle(int key, t_list_map *map)
{
	if (key == 123)
		map->plr.Angle_plr -= 2;
	if (key == 124)
		map->plr.Angle_plr += 2;
	if (map->plr.Angle_plr > 360)
		map->plr.Angle_plr -= 360;
	if (map->plr.Angle_plr < 0)
		map->plr.Angle_plr += 360;
}

void	ft_mod_pos(int key, t_list_map *map)
{
	int		tmpx;
	int 	tmpy;

	tmpx = map->plr.Vposx / map->map.Vcubx;
	tmpy = map->plr.Vposy / map->map.Vcuby;
	if (key == 13)
		map->plr.Vposy *= 1.10;
	if (key == 0)
		map->plr.Vposx *= 1.10;
	if (key == 1)
		map->plr.Vposy *= 0.9;
	if (key == 2)
		map->plr.Vposx *= 0.9;
	if (tmpx < map->plr.Vposx / map->map.Vcubx)
		map->plr.PosplrX--;
	if (tmpx > map->plr.Vposx / map->map.Vcubx)
		map->plr.PosplrX++;
	if (tmpy < map->plr.Vposy / map->map.Vcuby)
		map->plr.PosplrY--;
	if (tmpy > map->plr.Vposy / map->map.Vcuby)
		map->plr.PosplrY++;
	ft_map2d(map);
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