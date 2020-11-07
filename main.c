/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:07:53 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/30 21:18:27 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libcub.h"

int main (int argc, char **argv)
{
	t_list_map	map;

	if (argc != 2)
	{
		ft_putstr("Invalid number of argument.");
		return (-1);
	}
	if (ft_init_map(&map, argv[1]) == -1)
		return (-1);
	map.data.mlx_ptr = mlx_init();
	map.data.win_ptr = mlx_new_window(map.data.mlx_ptr, map.map.reso[0],
		map.map.reso[1], "Cub3D");
	ft_start_all(&map);
	return (0);
}
