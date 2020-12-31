/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:24:51 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/31 16:19:15 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

int		ft_display_fctex(t_list_map *map, int v, int i)
{
	int	t;

	t = 0;
	while (t < map->dis.t_fc)
	{
		map->data.data_addr[i++] = (v ? map->map.f[0] : map->map.c[0]);
		map->data.data_addr[i++] = (v ? map->map.f[1] : map->map.c[1]);
		map->data.data_addr[i++] = (v ? map->map.f[2] : map->map.c[2]);
		i += map->map.size_line - 3;
		t++;
	}
	return (i);
}

int		ft_display_walltex2(t_list_map *map, int i, int *tab, char *str)
{
	float	t;
	float	j;
	int		r;
	int		v;

	v = (map->dis.t_wall - map->map.reso[1]) / 2;
	t = v;
	while (t < map->map.reso[1] + v)
	{
		j = t / map->dis.t_wall;
		r = tab[1] * j;
		r *= (tab[0] * 4);
		r += map->tex.line;
		map->data.data_addr[i++] = str[r++];
		map->data.data_addr[i++] = str[r++];
		map->data.data_addr[i++] = str[r++];
		map->data.data_addr[i] = str[r];
		i += map->map.size_line - 3;
		t++;
	}
	return (i);
}

int		ft_display_walltex(t_list_map *map, int i, int *tab, char *str)
{
	float	t;
	float	j;
	int		r;

	t = 0;
	if (map->dis.t_wall > map->map.reso[1])
		return (ft_display_walltex2(map, i, tab, str));
	while (t < map->dis.t_wall)
	{
		if (t > 0)
		{
			j = t / map->dis.t_wall;
			r = tab[1] * j;
			r = (r * (tab[0] * 4)) + map->tex.line;
		}
		else
			r = map->tex.line;
		map->data.data_addr[i++] = str[r++];
		map->data.data_addr[i++] = str[r++];
		map->data.data_addr[i++] = str[r++];
		map->data.data_addr[i] = str[r];
		i += map->map.size_line - 3;
		t++;
	}
	return (i);
}

void	ft_display(t_list_map *map)
{
	int	i;
	int	a;
	int	tmp;

	i = 0;
	a = 0;
	while (a < map->map.reso[0])
	{
		tmp = i + 4;
		if (map->ray.dist[a] < 1)
			map->ray.dist[a] = 1;
		map->dis.t_wall = (map->map.tcub / map->ray.dist[a]) *
			map->ray.dist_to_pp;
		map->dis.t_fc = (map->map.reso[1] - map->dis.t_wall) / 2;
		map->dis.t_fc = map->dis.t_fc < 0 ? 0 : map->dis.t_fc;
		if (map->dis.t_wall + (map->dis.t_fc * 2) < map->map.reso[1])
			map->dis.t_wall++;
		i = (map->dis.t_wall > map->map.reso[1] ? i :
			ft_display_fctex(map, 1, i));
		i = ft_texture(map, a, i);
		i = (map->dis.t_wall > map->map.reso[1] ? i :
			ft_display_fctex(map, 0, i));
		i = tmp;
		a++;
	}
}
