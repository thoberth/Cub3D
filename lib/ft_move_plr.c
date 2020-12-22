/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_plr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:58:30 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/21 15:12:33 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_move_front(t_list_map *map, int vitesse)
{
	map->plr.vposx += vitesse * cos(map->plr.angle_plr * (M_PI / 180));
	map->plr.vposy -= vitesse * sin(map->plr.angle_plr * (M_PI / 180));
}

void	ft_move_back(t_list_map *map, int vitesse)
{
	int	ang;

	ang = map->plr.angle_plr + 180;
	map->plr.vposx += vitesse *
		cos(ft_mod_angle2(ang) * (M_PI / 180));
	map->plr.vposy -= vitesse *
		sin(ft_mod_angle2(ang) * (M_PI / 180));
}

void	ft_move_left(t_list_map *map, int vitesse)
{
	int	ang;

	ang = map->plr.angle_plr + 90;
	map->plr.vposx += vitesse *
		cos(ft_mod_angle2(ang) * (M_PI / 180));
	map->plr.vposy -= vitesse *
		sin(ft_mod_angle2(ang) * (M_PI / 180));
}

void	ft_move_right(t_list_map *map, int vitesse)
{
	int	ang;

	ang = map->plr.angle_plr - 90;
	map->plr.vposx += vitesse *
		cos(ft_mod_angle2(ang) * (M_PI / 180));
	map->plr.vposy -= vitesse *
		sin(ft_mod_angle2(ang) * (M_PI / 180));
}

void	ft_mod_pos2(int key, t_list_map *map, int vitesse)
{
	if (key == KEY_GO_AHEAD)
		ft_move_front(map, vitesse);
	if (key == KEY_GO_BACK)
		ft_move_back(map, vitesse);
	if (key == KEY_GO_LEFT)
		ft_move_left(map, vitesse);
	if (key == KEY_GO_RIGHT)
		ft_move_right(map, vitesse);
}

void	ft_mod_pos2_bonus(int key, t_list_map *map, int vitesse)
{
	int	tmpx;
	int	tmpy;

	tmpx = map->plr.vposx;
	tmpy = map->plr.vposy;
	if (key == KEY_GO_AHEAD)
		ft_move_front(map, vitesse);
	if (key == KEY_GO_BACK)
		ft_move_back(map, vitesse);
	if (key == KEY_GO_LEFT)
		ft_move_left(map, vitesse);
	if (key == KEY_GO_RIGHT)
		ft_move_right(map, vitesse);
	if (ft_detect_wall(map, (map->plr.vposx + 16), tmpy) == 1 ||
		ft_detect_wall(map, (map->plr.vposx - 16), tmpy) == 1)
		map->plr.vposx = tmpx;
	if (ft_detect_wall(map, tmpx, (map->plr.vposy + 16)) == 1 ||
		ft_detect_wall(map, tmpx, (map->plr.vposy - 16)) == 1)
		map->plr.vposy = tmpy;
}
