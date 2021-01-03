/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:07:32 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/31 16:12:28 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_init_map2(t_list_map *map)
{
	map->verif.verif_reso = 0;
	map->verif.verif_f = 0;
	map->verif.verif_c = 0;
	map->verif.last_verif = 0;
	map->map.t_map_y = 0;
	map->map.t_map_x = 0;
	map->map.no = NULL;
	map->map.so = NULL;
	map->map.ea = NULL;
	map->map.we = NULL;
	map->map.sprite = NULL;
	map->data.is_2d = 0;
	map->data.win_ptr = 0;
	map->data.img_ptr = 0;
	map->data.img_ptr_minimap = 0;
	map->data.data_addr = NULL;
	map->data.data_addr_minimap = NULL;
	map->map.map = malloc(sizeof(char **));
	map->ray.dist = NULL;
	map->ray.is_sprite = NULL;
	map->ray.sort = NULL;
	map->tex.wall_tex = NULL;
}

void	ft_test_f_c(t_list_map *map)
{
	if (map->map.f[0] < 0 || map->map.f[0] > 255)
		ft_return_error(map, WRONG_FILECUB);
	if (map->map.f[1] < 0 || map->map.f[1] > 255)
		ft_return_error(map, WRONG_FILECUB);
	if (map->map.f[2] < 0 || map->map.f[2] > 255)
		ft_return_error(map, WRONG_FILECUB);
	if (map->map.c[0] < 0 || map->map.c[0] > 255)
		ft_return_error(map, WRONG_FILECUB);
	if (map->map.c[1] < 0 || map->map.c[1] > 255)
		ft_return_error(map, WRONG_FILECUB);
	if (map->map.c[2] < 0 || map->map.c[2] > 255)
		ft_return_error(map, WRONG_FILECUB);
}

void	ft_init_map_suite(t_list_map *map, char *line, int fd)
{
	if (map->verif.last_verif == 8)
		map->map.map = ft_line_to_array_of_str(map->map.map,
			line, map->map.t_map_y++);
	free(line);
	map->map.map = ft_resize_map(map, map->map.t_map_y);
	ft_close(map, fd);
	if (map->verif.last_verif != 8 || ft_test_info_map(map) == -1
		|| ft_test_map(map) < 0)
	{
		ft_return_error(map, WRONG_FILECUB);
	}
}

void	ft_init_map(t_list_map *map, char *cub)
{
	int		fd;
	char	*line;
	int		taille_lu;

	ft_init_map2(map);
	fd = open(cub, O_RDONLY);
	if (fd == -1)
		ft_return_error(map, ERROR_FILE_MANIP);
	while ((taille_lu = get_next_line(fd, &line)) > 0)
	{
		if (map->verif.last_verif < 8)
			ft_detect_map(map, line);
		else if (map->verif.last_verif == 8 && (line[0] != '\0' ||
			map->map.t_map_y > 0))
			map->map.map = ft_line_to_array_of_str(map->map.map,
				line, map->map.t_map_y++);
		free(line);
	}
	ft_test_f_c(map);
	ft_init_map_suite(map, line, fd);
}
