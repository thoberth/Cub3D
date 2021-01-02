/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_is_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:14:28 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/17 16:44:37 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

/*
** ces fonctions testent:
** que la map n'est pas séparé verticalement
*/

int		ft_last1(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i > 0 && str[i] != '1')
		i--;
	return (i);
}

int		ft_map_is_split2(char **map, int i, int t, int t_map)
{
	if (map[i][t] == ' ' && i == t_map - 1)
		return (-1);
	while (map[i][t - 1] == ' ' && t > 1)
		t--;
	while (map[i][t] == ' ' && t < ft_strlen(map[i]))
	{
		if (i < t_map && map[i + 1][t] == ' ')
			return (ft_map_is_split2(map, i + 1, t, t_map));
		t++;
	}
	return (0);
}

int		ft_map_is_split(char **map, int t_map)
{
	int	i;
	int	t;
	int	compt;

	i = 0;
	t = 0;
	while (map[i][t] != '1')
		t++;
	while (t < ft_last1(map[i]))
	{
		while (map[i][t] != ' ' && t < ft_last1(map[i]))
			t++;
		if (map[i][t] == ' ' && t < ft_last1(map[i]))
			compt = ft_map_is_split2(map, i, t, t_map);
		while (map[i][t] == ' ')
			t++;
	}
	ft_putnbr(compt);
	return ((compt < 0) ? -1 : 0);
}
