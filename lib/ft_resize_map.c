/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 13:29:23 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/22 17:46:38 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

char	*ft_resize_line(char *line, int new_t)
{
	char	*res;
	int		i;

	i = 0;
	if (!(res = malloc(sizeof(char) * (new_t + 1))))
		return(NULL);
	res[new_t] = '\0';
	while(line[i])
	{
		res[i] = line[i];
		i++;
	}
	if (i < new_t)
	{
		while(i < new_t)
		{
			res[i] = ' ';
			i++;
		}
	}
	return (res);
}

char	**ft_resize_map(t_list_map *map, int t_map)
{
	int 	i;
	int		t;
	char	**res;

	i = 0;
	t = 0;
	if (!(res = malloc(sizeof(char *) * (t_map + 1))))
		return (NULL);
	res[t_map] = NULL;
	while (i < t_map)
	{
		if (ft_strlen(map->map.map[i]) > t)
			t = ft_strlen(map->map.map[i]);
		i++;
	}
	i = 0;
	map->map.t_map_x = t;
	while (i < t_map)
	{
		res[i] = ft_resize_line(map->map.map[i], t);
		i++;
	}
	return (res);
}