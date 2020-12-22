/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 13:21:32 by berthetthom       #+#    #+#             */
/*   Updated: 2020/12/21 10:10:54 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_free(t_list_map *map)
{
	int	i;

	i = 0;
	if (map->map.map != NULL)
	{
		while (i < map->map.t_map_y)
		{
			if (map->map.map[i] != NULL)
				free(map->map.map[++i]);
		}
		free(map->map.map);
	}
	i = 0;
	if (map->ray.dist != NULL)
		free(map->ray.dist);
	if (map->ray.is_sprite != NULL)
	{
		while (i < map->map.reso[0])
		{
			if (map->ray.is_sprite[i] != NULL)
				free(map->ray.is_sprite[++i]);
		}
	}
	i = 0;
	if (map->tex.wall_tex != NULL)
	{
		while (i < map->map.reso[0])
		{
			if (map->tex.wall_tex[i] != NULL)
				free(map->tex.wall_tex[++i]);
		}
	}
}

void	ft_return_error(t_list_map *map, int define)
{
	if (define == ERROR_MALLOC)
		ft_putstr("Error malloc.\n");
	else if (define == ERROR_FILE_MANIP)
		ft_putstr("Error during opening or closing file.\n");
	else if (define == WRONG_FILECUB)
		ft_putstr("Error, invalid file .cub .\n");
	else if (define == WRONG_NUMBER_ARGUMENTS)
		ft_putstr("Error, invalid number of arguments.\n");
	ft_free(map);
	if (define == EXIT_SUCCESS)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
