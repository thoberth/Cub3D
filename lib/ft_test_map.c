/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 13:35:12 by berthetthom       #+#    #+#             */
/*   Updated: 2020/12/17 17:10:26 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

/*
** ces fonctions testent:
**-> si il y bien 1 seul indicateur de position dans la map et si tout les char
**	de la map sont correctes
**-> si la map n'est pas separes horizontalement
**-> si un espace est detecter -> ft_space_found
*/

int		ft_charmap_isgood(char c)
{
	if (c == ' ' || c == '1' || c == '2' || c == '0' || c == 'N' ||
		c == 'S' || c == 'E' || c == 'W')
		return (0);
	return (-1);
}

void	ft_info_player(t_list_map *map, int i, int t)
{
	map->plr.posplrx = t;
	map->plr.posplry = i;
	if (map->map.map[i][t] == 'N')
		map->plr.angle_plr = 90;
	if (map->map.map[i][t] == 'S')
		map->plr.angle_plr = 270;
	if (map->map.map[i][t] == 'E')
		map->plr.angle_plr = 0;
	if (map->map.map[i][t] == 'W')
		map->plr.angle_plr = 180;
}

int		ft_test_if_nsew(t_list_map *map)
{
	int		i;
	int		t;
	int		c;

	i = 0;
	c = 0;
	while (i < map->map.t_map_y)
	{
		t = 0;
		while (map->map.map[i][t])
		{
			if (map->map.map[i][t] == 'N' || map->map.map[i][t] == 'S' ||
				map->map.map[i][t] == 'E' || map->map.map[i][t] == 'W')
			{
				ft_info_player(map, i, t);
				c++;
			}
			t++;
		}
		i++;
	}
	return (c == 1 ? 0 : -1);
}

int		ft_no_acc_space(char **map, int t_map)
{
	int		i;
	int		t;

	i = 0;
	while (i < t_map)
	{
		t = 0;
		while (map[i][t] == ' ')
			t++;
		while (map[i][t])
		{
			if (map[i][t] == ' ' && ft_space_found(map, i, t, t_map) == -1)
				return (-1);
			t++;
		}
		i++;
	}
	return (ft_circled_of_1_horizontal(map, t_map) +
		ft_circled_of_1_vertical(map, t_map));
}

int		ft_test_map(t_list_map *map)
{
	int		i;
	int		t;
	char	*tmp;

	i = 0;
	while (i < map->map.t_map_y)
	{
		t = 0;
		tmp = map->map.map[i];
		if (tmp[0] == '\0')
			return (-1);
		while (tmp[t])
		{
			if (ft_charmap_isgood(tmp[t]) == -1)
				return (-1);
			t++;
		}
		i++;
	}
	return (ft_no_acc_space(map->map.map, map->map.t_map_y) +
		ft_test_if_nsew(map));
}
