/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:01:27 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/31 15:50:21 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

/*
** fonction qui est appelé lorsque l'utlisateur utilise une touche au clavier.
*/

void	ft_mod_angle(int key, t_list_map *map)
{
	if (key == KEY_TURN_LEFT)
		map->plr.angle_plr += 2;
	if (key == KEY_TURN_RIGHT)
		map->plr.angle_plr -= 2;
	if (map->plr.angle_plr > 360)
		map->plr.angle_plr -= 360;
	if (map->plr.angle_plr < 0)
		map->plr.angle_plr += 360;
}

void	ft_mod_pos(int key, t_list_map *map)
{
	float	tmpx;
	float	tmpy;
	int		max_x;
	int		max_y;
	int		vitesse;

	tmpx = map->plr.vposx;
	tmpy = map->plr.vposy;
	max_x = map->map.t_map_x * map->map.tcub;
	max_y = map->map.t_map_y * map->map.tcub;
	vitesse = map->map.tcub / 16;
	ft_mod_pos2(key, map, vitesse);
	if (map->plr.vposx <= 0)
		map->plr.vposx = tmpx;
	if (map->plr.vposx >= max_x)
		map->plr.vposx = tmpx;
	if (map->plr.vposy <= 0)
		map->plr.vposy = tmpy;
	if (map->plr.vposy >= max_y)
		map->plr.vposx = tmpy;
}

int		close_window(t_list_map *map)
{
	ft_return_error(map, EXIT_SUCCESS);
	return (0);
}

int		deal_key(int key, t_list_map *map)
{
	if (key == KEY_ESC)
		close_window(map);
	if (key == KEY_TURN_LEFT || key == KEY_TURN_RIGHT)
		ft_mod_angle(key, map);
	if (key == KEY_GO_AHEAD || key == KEY_GO_BACK || key == KEY_GO_LEFT ||
		key == KEY_GO_RIGHT)
		ft_mod_pos(key, map);
	ft_raycasting(map);
	return (0);
}

int		do_nothing(void)
{
	return (0);
}
