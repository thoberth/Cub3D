/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_plr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:58:30 by thoberth          #+#    #+#             */
/*   Updated: 2020/11/12 20:07:51 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void    ft_move_front(t_list_map *map, int vitesse)
{
	int		tmpx;
	int		tmpy;

	tmpx = map->plr.Vposx;
	tmpy = map->plr.Vposy;
    map->plr.Vposx += vitesse * cos(map->plr.Angle_plr * (M_PI / 180));
	map->plr.Vposy -= vitesse * sin(map->plr.Angle_plr * (M_PI / 180));
	
}

void    ft_move_back(t_list_map *map, int vitesse)
{
	int		ang;

	ang = map->plr.Angle_plr + 180;
    map->plr.Vposx += vitesse * 
		cos(ft_mod_angle2(ang) * (M_PI / 180));
	map->plr.Vposy -= vitesse * 
		sin(ft_mod_angle2(ang) * (M_PI / 180));
}

void    ft_move_left(t_list_map *map, int vitesse)
{
	int		ang;

	ang = map->plr.Angle_plr + 90;
    map->plr.Vposx += vitesse * 
		cos(ft_mod_angle2(ang) * (M_PI / 180));
	map->plr.Vposy -= vitesse * 
		sin(ft_mod_angle2(ang) * (M_PI / 180));
}

void    ft_move_right(t_list_map *map, int vitesse)
{
	int		ang;

	ang = map->plr.Angle_plr - 90;
    map->plr.Vposx += vitesse * 
		cos(ft_mod_angle2(ang) * (M_PI / 180));
	map->plr.Vposy -= vitesse * 
		sin(ft_mod_angle2(ang) * (M_PI / 180));
}

void	ft_mod_pos2(int key, t_list_map *map, int vitesse)
{
	int		tmpx;
	int		tmpy;

	tmpx = map->plr.Vposx;
	tmpy = map->plr.Vposy;
	if (key == 13)
        ft_move_front(map, vitesse);
	if (key == 1)
        ft_move_back(map, vitesse);
	if (key == 0)
	   ft_move_left(map, vitesse);
	if (key == 2)
    	ft_move_right(map, vitesse);
	if (ft_detect_wall(map, (map->plr.Vposx + 16), tmpy) == 1 ||
		ft_detect_wall(map, (map->plr.Vposx - 16), tmpy) == 1)
			map->plr.Vposx = tmpx;
	if (ft_detect_wall(map, tmpx, (map->plr.Vposy + 16)) == 1 ||
		ft_detect_wall(map, tmpx, (map->plr.Vposy - 16)) == 1)
			map->plr.Vposy = tmpy;
}