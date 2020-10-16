/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:07:32 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/16 15:02:12 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void	ft_init_ptr(t_list_ptr *ptr)
{
	ptr->mlx_ptr = 0;
	ptr->win_ptr = 0;
	ptr->img_ptr = 0;
	ptr->data_addr = "";
	ptr->data_addr_minimap = "";
	ptr->img_ptr_minimap = 0;
}

void	ft_init_map2(t_list_map	*map)
{
	map->verif_reso = 0;
	map->verif_f = 0;
	map->verif_c = 0;
	map->last_verif = 0;
	map->t_map_y = 0;
	map->t_map_x = 0;
	map->no = NULL;
	map->so = NULL;
	map->ea = NULL;
	map->we = NULL;
	map->sprite = NULL;
	map->map = malloc(sizeof(char **));
}

int		ft_detect_map(t_list_map *map, char *line)
{
	int i;

	i = 0;
	if (line[i] == 'R')
	{
		map->last_verif++;
		map->verif_reso++;
		i++;
		map->reso[0] = ft_atoi(&line[++i]);
		while (line[i] >= '0' && line[i] <= '9')
			i++;
		map->reso[1] = ft_atoi(&line[i]);
	}
	else if (line[i] == 'S' && line[i + 1] == 'O')
	{
		map->last_verif++;
		while (line[i] != ' ')
			i++;
		map->so = ft_strdup(&line[i++]);
	}
	else if (line[i] == 'N' && line[i + 1] == 'O')
	{
		map->last_verif++;
		while (line[i] != ' ')
			i++;
		map->no = ft_strdup(&line[i++]);
	}
	else if (line[i] == 'W' && line[i + 1] == 'E')
	{
		map->last_verif++;
		while (line[i] != ' ')
			i++;
		map->we = ft_strdup(&line[i++]);
	}
	else if (line[i] == 'E' && line[i + 1] == 'A')
	{
		map->last_verif++;
		while (line[i] != ' ')
			i++;
		map->ea = ft_strdup(&line[i++]);
	}
	else if (line[i] == 'S')
	{
		map->last_verif++;
		while (line[i] != ' ')
			i++;
		map->sprite = ft_strdup(&line[i++]);
	}
	else if (line[i] == 'F')
	{
		map->last_verif++;
		map->verif_f++;
		i++;
		map->f[0] = ft_atoi(&line[++i]);
		while (line[i] != ',')
			i++;
		map->f[1] = ft_atoi(&line[++i]);
		while (line[i] != ',')
			i++;
		map->f[2] = ft_atoi(&line[++i]);
	}
	else if (line[i] == 'C')
	{
		map->last_verif++;
		map->verif_c++;
		i++;
		map->c[0] = ft_atoi(&line[++i]);
		while (line[i] != ',')
			i++;
		map->c[1] = ft_atoi(&line[++i]);
		while (line[i] != ',')
			i++;
		map->c[2] = ft_atoi(&line[++i]);
	}
	return (0);
}

int		ft_init_map(t_list_map *map, char *cub)
{
	int		fd;
	char	*line;
	int		taille_lu;

	ft_init_map2(map);
	fd = open(cub, O_RDONLY);
	if (fd == -1)
		return (ft_return_error());
	while ((taille_lu = get_next_line(fd, &line)) > 0)
	{
		if (map->last_verif < 8)
			ft_detect_map(map, line); //verif et recuperation des donnees de la map
		else if (map->last_verif == 8 && (line[0] != '\0' || map->t_map_y > 0))
			map->map = ft_line_to_array_of_str(map->map, line, map->t_map_y++);
		free(line);
	}
	if (map->last_verif == 8)
		map->map = ft_line_to_array_of_str(map->map, line, map->t_map_y++);
	free(line);
	map->map = ft_resize_map(map, map->t_map_y);
	if (map->last_verif != 8 || close(fd) == -1 || ft_test_info_map(map) == -1 ||
		ft_test_map(map) < 0)
		return(ft_return_error());
	return (0);
}

	/*for (int i = 0; map->map[i] != 0; i++)
	{
		ft_putstr(map->map[i]);
		ft_putchar('\n');
	}
	printf("no =%s\nso =%s\nwe =%s\nea =%s\nsprite =%s\n", map->no, map->so, map->we, map->ea, map->sprite);
	printf("reso = %i %i\ncouleur sol = %i,%i,%i\ncouleur plafond = %i,%i,%i\n", map->reso[0], map->reso[1], map->f[0], map->f[1], map->f[2], map->c[0], map->c[1], map->c[2]);*/