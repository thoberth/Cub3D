/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_found.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:14:01 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/05 12:40:39 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

/* ces fonctions testent:
-> que tout la map n'a pas d'espace accessible
*/
int 	ft_verif_prev_line(char **map, int i, int t)
{
	while (i > 0 && map[i][t] == ' ')
		i--;
	if (map[i][t] != '1' && i != 0)
		return (-1);
	return (0);
}

int		ft_verif_next_line(char **map, int i, int t, int t_map)
{
	while (i < t_map && map[i][t] == ' ')
		i++;
	if (i != t_map && map[i][t] != '1')
		return (-1);
	return (0);
}

int		ft_test_space(char **map, int i, int t, int t_map)
{
	int		tmp;
	int 	tmp2;

	tmp = t;
	tmp2 = t;
	while (map[i][tmp] && map[i][tmp] == ' ')
		tmp++;
	while (map[i][tmp2] > 0 && map[i][tmp2] == ' ')
		tmp2--;
	if (map[i][tmp] != '1' || map[i][tmp2] != '1')
		return (-1);
	if (ft_verif_prev_line(map, i, t) == -1)
		return (-1);
	if (ft_verif_next_line(map, i, t, t_map) == -1)
		return (-1);
	return (0);
}

int     ft_space_found(char **map, int i, int t, int t_map)
{
    int		tmp;
	int		verif;

	tmp = t;
	verif = 0; // verif si le ' ' est en fin de ligne.
	while (map[i][tmp])
	{
		if (map[i][tmp] != ' ')
			verif++;
		tmp++;
	}
	if (verif == 0)
		return (0);
    return (ft_test_space(map, i, t, t_map));
}