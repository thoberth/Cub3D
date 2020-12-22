/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:07:32 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/18 15:18:01 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_init_map2(t_list_map *map)
{
	map->verif.verif_reso = 0;
	map->verif.verif_f = 0;
	map->verif.verif_c = 0;
	map->verif.last_verif = 0;
	map->verif.save = 0;
	map->map.t_map_y = 0;
	map->map.t_map_x = 0;
	map->map.no = NULL;
	map->map.so = NULL;
	map->map.ea = NULL;
	map->map.we = NULL;
	map->map.sprite = NULL;
	map->data.is_2d = 0;
	map->data.mlx_ptr = 0;
	map->data.win_ptr = 0;
	map->data.img_ptr = 0;
	map->data.img_ptr_minimap = 0;
	map->data.data_addr = NULL;
	map->data.data_addr_minimap = NULL;
	map->map.map = malloc(sizeof(char **));
	map->map.map = NULL;
	map->ray.dist = NULL;
	map->ray.is_sprite = NULL;
	map->tex.wall_tex = NULL;
}

int		ft_detect_map(t_list_map *map, char *line)
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
	else if (line[i] == 'S' && line[i + 1] == 'O')
	{
		map->verif.last_verif++;
		while (line[i] != ' ')
			i++;
		map->map.so = ft_strdup(&line[++i]);
	}
	else if (line[i] == 'N' && line[i + 1] == 'O')
	{
		map->verif.last_verif++;
		while (line[i] != ' ')
			i++;
		map->map.no = ft_strdup(&line[++i]);
	}
	else if (line[i] == 'W' && line[i + 1] == 'E')
	{
		map->verif.last_verif++;
		while (line[i] != ' ')
			i++;
		map->map.we = ft_strdup(&line[++i]);
	}
	else if (line[i] == 'E' && line[i + 1] == 'A')
	{
		map->verif.last_verif++;
		while (line[i] != ' ')
			i++;
		map->map.ea = ft_strdup(&line[++i]);
	}
	else if (line[i] == 'S')
	{
		map->verif.last_verif++;
		while (line[i] != ' ')
			i++;
		map->map.sprite = ft_strdup(&line[++i]);
	}
	else if (line[i] == 'F')
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
	else if (line[i] == 'C')
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
	return (0);
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
	if (map->verif.last_verif == 8)
		map->map.map = ft_line_to_array_of_str(map->map.map,
			line, map->map.t_map_y++);
	free(line);
	map->map.map = ft_resize_map(map, map->map.t_map_y);
	ft_close(map, fd);
	if (map->verif.last_verif != 8 || ft_test_info_map(map) == -1
		|| ft_test_map(map) < 0)
		ft_return_error(map, WRONG_FILECUB);
}
