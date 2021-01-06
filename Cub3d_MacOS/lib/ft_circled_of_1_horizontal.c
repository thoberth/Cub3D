/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_circled_of_1_horizontal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:55:07 by thoberth          #+#    #+#             */
/*   Updated: 2021/01/05 01:10:06 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

/*
** ces fonctions testent:
** -> que la map est bien entouré de '1' horizontalement
*/

int		ft_verif_first1_h(char *ligne, int t)
{
	t--;
	while (t >= 0)
	{
		if (ligne[t] != ' ')
			return (-1);
		t--;
	}
	return (0);
}

int		ft_verif_last1_h(char *ligne, int t_ligne)
{
	if (ligne[t_ligne] == 't')
		return (0);
	while (t_ligne > 0 && ligne[t_ligne] != '1')
	{
		if (ligne[t_ligne] != ' ')
			return (-1);
		t_ligne--;
	}
	return (0);
}

int		ft_circled_of_1_horizontal(char **map, int t_map)
{
	int		i;
	int		t;
	int		c;
	int		res;

	i = 0;
	while (i < t_map)
	{
		res = 0;
		c = 0;
		t = 0;
		while (map[i][t])
		{
			map[i][t] == '1' ? c++ : c;
			if (c == 1)
				res = ft_verif_first1_h(map[i], t);
			else if (c > 1)
				res = ft_verif_last1_h(map[i], ft_strlen(map[i]) - 1);
			t++;
		}
		if (c == 0 || c == 1 || res == -1)
			return (-1);
		i++;
	}
	return (0);
}
