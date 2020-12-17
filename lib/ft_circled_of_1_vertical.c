/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circled_of_1_vertical.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 12:41:18 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/17 16:36:21 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

/*
** ces fonctions testent:
** que la map est bien entouré de '1' verticalement
*/

int		ft_verif_1_vertical(char **map, int t_map, int i, int t)
{
	while (i < t_map - 1 && map[i][t] == ' ')
		i++;
	if (map[i][t] != '1' && map[i][t] != ' ')
		return (-1);
	t_map--;
	while (map[t_map][t] == ' ' && t_map > 0)
		t_map--;
	if (map[t_map][t] != '1' && map[i][t] != ' ')
		return (-1);
	return (0);
}

int		ft_circled_of_1_vertical(char **map, int t_map)
{
	int		i;
	int		t;

	i = 0;
	t = 0;
	while (map[i][t])
	{
		i = 0;
		if (ft_verif_1_vertical(map, t_map, i, t) == -1)
			return (-1);
		t++;
	}
	return (ft_map_is_split(map, t_map));
}
