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
	ft_raycasting(map);
}

void	ft_mod_pos(int key, t_list_map *map)
{
	float	tmpx;
	float	tmpy;
	int		vitesse;

	tmpx = map->plr.vposx / map->map.tcub;
	tmpy = map->plr.vposy / map->map.tcub;
	vitesse = map->map.tcub / 16;
	ft_mod_pos2(key, map, vitesse);
	if (tmpx < map->plr.vposx / map->map.tcub)
		map->plr.posplrx++;
	if (tmpx > map->plr.vposx / map->map.tcub)
		map->plr.posplrx--;
	if (tmpy < map->plr.vposy / map->map.tcub)
		map->plr.posplry++;
	if (tmpy > map->plr.vposy / map->map.tcub)
		map->plr.posplry--;
	ft_raycasting(map);
}

int		close_window(t_list_map *map)
{
	ft_return_error(map, EXIT_SUCCESS);
	mlx_destroy_window(map->data.mlx_ptr, map->data.win_ptr);
	if (map->data.img_ptr != NULL)
		mlx_destroy_image(map->data.mlx_ptr, map->data.img_ptr);
	if (map->data.img_ptr_minimap != NULL)
		mlx_destroy_image(map->data.mlx_ptr, map->data.img_ptr_minimap);
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
	return (0);
}

void	ft_event(t_list_map *map)
{
	mlx_hook(map->data.win_ptr, 2, 1L << 0, deal_key, map);
	mlx_hook(map->data.win_ptr, 3, 1L << 1, deal_key, map);
	mlx_hook(map->data.win_ptr, 17, 1L << 17, close_window, map);
}
