/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detect_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 16:11:33 by thoberth          #+#    #+#             */
/*   Updated: 2021/01/03 12:31:15 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_recup_info_f_c(t_list_map *map, char *line, int i, int dest[3])
{
	while (line[i] == ' ')
		i++;
	dest[0] = ft_atoi(&line[i]);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] == ' ')
		i++;
	line[i] == ',' ? i++ : ft_return_error(map, WRONG_FILECUB);
	while (line[i] == ' ')
		i++;
	dest[1] = ft_atoi(&line[i]);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] == ' ')
		i++;
	line[i] == ',' ? i++ : ft_return_error(map, WRONG_FILECUB);
	while (line[i] == ' ')
		i++;
	dest[2] = ft_atoi(&line[i]);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (line[i] != '\0')
		ft_return_error(map, WRONG_FILECUB);
}

void	ft_detect_map4(t_list_map *map, char *line, int i)
{
	if (line[i] == 'C' && line[i + 1] == ' ')
	{
		i++;
		map->verif.last_verif++;
		map->verif.verif_c++;
		ft_recup_info_f_c(map, line, i, map->map.c);
	}
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
	{
		i += 3;
		map->verif.last_verif++;
		while (line[i] == ' ')
			i++;
		map->map.ea = ft_strdup(&line[i]);
	}
}

void	ft_detect_map3(t_list_map *map, char *line, int i)
{
	if (line[i] == 'S' && line[i + 1] == ' ')
	{
		i += 2;
		map->verif.last_verif++;
		while (line[i] == ' ')
			i++;
		map->map.sprite = ft_strdup(&line[i]);
	}
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
	{
		i += 3;
		map->verif.last_verif++;
		while (line[i] == ' ')
			i++;
		map->map.so = ft_strdup(&line[i]);
	}
	else if (line[i] == 'F' && line[i + 1] == ' ')
	{
		i++;
		map->verif.last_verif++;
		map->verif.verif_f++;
		ft_recup_info_f_c(map, line, i, map->map.f);
	}
	else
		ft_detect_map4(map, line, i);
}

void	ft_detect_map2(t_list_map *map, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
	{
		i += 3;
		map->verif.last_verif++;
		while (line[i] == ' ')
			i++;
		map->map.no = ft_strdup(&line[i]);
	}
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
	{
		i += 3;
		map->verif.last_verif++;
		while (line[i] == ' ')
			i++;
		map->map.we = ft_strdup(&line[i]);
	}
	else
		ft_detect_map3(map, line, i);
}

void	ft_detect_map(t_list_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'R' && line[i + 1] == ' ')
	{
		i++;
		map->verif.last_verif++;
		map->verif.verif_reso++;
		while (line[i] == ' ')
			i++;
		map->map.reso[0] = ft_atoi(&line[i]);
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		while (line[i] == ' ')
			i++;
		map->map.reso[1] = ft_atoi(&line[i]);
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		line[i] != '\0' ? ft_return_error(map, WRONG_FILECUB) : 0;
		ft_verif_reso(map);
	}
	else
		ft_detect_map2(map, line, i);
}
