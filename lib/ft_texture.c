/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:58:47 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/17 16:11:15 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	t_calc_line(t_list_map *map, int a, int *tab)
{
	map->tex.line = a;
	while (map->tex.line >= map->map.Tcub)
		map->tex.line -= map->map.Tcub;
	map->tex.line /= map->map.Tcub;
	map->tex.line *= tab[0];
	map->tex.line *= 4;
}

int		ft_texture2(t_list_map *map, int a, int i)
{
	int tab[2];

	if (map->tex.wall_tex[a][0] == 2)
	{
		tab[0] = map->tex.t_ea[0];
		tab[1] = map->tex.t_ea[1];
		ft_calc_line(map, map->tex.wall_tex[a][2], tab);
		return (ft_display_walltex(map, i, tab, map->tex.texea));
	}
	else if (map->tex.wall_tex[a][0] == 3)
	{
		tab[0] = map->tex.t_we[0];
		tab[1] = map->tex.t_we[1];
		ft_calc_line(map, map->tex.wall_tex[a][2], tab);
		return (ft_display_walltex(map, i, tab, map->tex.texwe));
	}
	return (i);
}

int		ft_texture(t_list_map *map, int a, int i)
{
	int tab[2];

	if (map->tex.wall_tex[a][0] == 0)
	{
		tab[0] = map->tex.t_no[0];
		tab[1] = map->tex.t_no[1];
		ft_calc_line(map, map->tex.wall_tex[a][1], tab);
		return (ft_display_walltex(map, i, tab, map->tex.texno));
	}
	else if (map->tex.wall_tex[a][0] == 1)
	{
		tab[0] = map->tex.t_so[0];
		tab[1] = map->tex.t_so[1];
		ft_calc_line(map, map->tex.wall_tex[a][1], tab);
		return (ft_display_walltex(map, i, tab, map->tex.texso));
	}
	return (ft_texture2(map, a, i));
}
