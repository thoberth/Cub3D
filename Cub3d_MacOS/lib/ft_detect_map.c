/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 16:11:33 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/31 16:12:48 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_detect_map4(t_list_map *map, char *line, int i)
{
	if (line[i] == 'C')
	{
		map->verif.last_verif++;
		map->verif.verif_c++;
		i++;
		map->map.c[0] = ft_atoi(&line[++i]);
		while (line[i] != ',')
			i++;
		map->map.c[1] = ft_atoi(&line[++i]);
		while (line[i] != ',')
			i++;
		map->map.c[2] = ft_atoi(&line[++i]);
	}
}

void	ft_detect_map3(t_list_map *map, char *line, int i)
{
	if (line[i] == 'S')
	{
		map->verif.last_verif++;
		while (line[i] != ' ')
			i++;
		map->map.sprite = ft_strdup(&line[++i]);
	}
	if (line[i] == 'F')
	{
		map->verif.last_verif++;
		map->verif.verif_f++;
		i++;
		map->map.f[0] = ft_atoi(&line[++i]);
		while (line[i] != ',')
			i++;
		map->map.f[1] = ft_atoi(&line[++i]);
		while (line[i] != ',')
			i++;
		map->map.f[2] = ft_atoi(&line[++i]);
	}
	ft_detect_map4(map, line, i);
}

void	ft_detect_map2(t_list_map *map, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O')
	{
		map->verif.last_verif++;
		while (line[i] != ' ')
			i++;
		map->map.no = ft_strdup(&line[++i]);
	}
	if (line[i] == 'W' && line[i + 1] == 'E')
	{
		map->verif.last_verif++;
		while (line[i] != ' ')
			i++;
		map->map.we = ft_strdup(&line[++i]);
	}
	if (line[i] == 'E' && line[i + 1] == 'A')
	{
		map->verif.last_verif++;
		while (line[i] != ' ')
			i++;
		map->map.ea = ft_strdup(&line[++i]);
	}
	ft_detect_map3(map, line, i);
}

void	ft_detect_map(t_list_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'R')
	{
		map->verif.last_verif++;
		map->verif.verif_reso++;
		i++;
		map->map.reso[0] = ft_atoi(&line[++i]);
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		map->map.reso[1] = ft_atoi(&line[i]);
		ft_verif_reso(map);
	}
	if (line[i] == 'S' && line[i + 1] == 'O')
	{
		map->verif.last_verif++;
		while (line[i] != ' ')
			i++;
		map->map.so = ft_strdup(&line[++i]);
	}
	ft_detect_map2(map, line, i);
}
