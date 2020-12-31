/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_sprite2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:43:13 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/31 15:45:40 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

int		ft_bgr_isblack(t_list_map *map, int b, int g, int r)
{
	if (map->tex.texs[b] == 0 && map->tex.texs[g] == 0 &&
		map->tex.texs[r] == 0)
		return (1);
	return (0);
}

int		ft_calcul_line_sp_v(t_list_map *map, int t, int line, int j)
{
	float	to_draw;
	int		b;

	to_draw = t - map->tex.debut_h;
	if (map->tex.debut_h < 0)
		to_draw = t;
	to_draw /= map->ray.is_sprite[j][5];
	b = to_draw * map->tex.t_s[1];
	b = line + (b * (map->tex.t_s[0] * 4));
	return (b);
}

void	ft_display_line_sp(t_list_map *map, int line, int i, int j)
{
	int		a;
	int		t;
	int		b;

	a = 0;
	t = abs(map->tex.debut_h);
	if (map->tex.debut_h >= 0)
		i += (map->map.size_line * t);
	while (a < map->ray.is_sprite[j][5] && a < map->map.reso[1])
	{
		b = ft_calcul_line_sp_v(map, t, line, j);
		if (ft_bgr_isblack(map, b, b + 1, b + 2) == 1)
			i += 3;
		else
		{
			map->data.data_addr[i++] = map->tex.texs[b++];
			map->data.data_addr[i++] = map->tex.texs[b++];
			map->data.data_addr[i++] = map->tex.texs[b++];
			map->data.data_addr[i] = map->tex.texs[b];
		}
		i += map->map.size_line - 3;
		t++;
		a++;
	}
}

int		ft_calcul_line_sp_h(t_list_map *map, int i, int j)
{
	float	res;
	int		r;

	res = i - map->tex.s_e_th[0];
	res = res / map->ray.is_sprite[j][5];
	r = res * map->tex.t_s[0];
	return (r * 4);
}

void	ft_display_sprite2(t_list_map *map, int j)
{
	int		i;
	int		a;
	int		tmp;
	int		line;

	i = map->tex.s_e_pr[0] * 4;
	a = map->tex.s_e_pr[0];
	map->tex.debut_h = (map->map.reso[1] - map->ray.is_sprite[j][5]) / 2;
	if ((map->tex.debut_h * 2) + map->ray.is_sprite[j][5] < map->map.reso[1])
		map->ray.is_sprite[j][5]++;
	while (a < map->tex.s_e_pr[1])
	{
		tmp = i + 4;
		if (map->ray.is_sprite[j][3] < map->ray.dist[a])
		{
			line = ft_calcul_line_sp_h(map, i / 4, j);
			ft_display_line_sp(map, line, i, j);
		}
		i = tmp;
		a++;
	}
}
