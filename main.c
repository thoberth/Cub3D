/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:07:53 by thoberth          #+#    #+#             */
/*   Updated: 2020/11/30 13:21:05 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libcub.h"

int main (int argc, char **argv)
{
	t_list_map	map;
	
	if (ft_init_map(&map, argv[1]) == -1)
		ft_return_error();
	if (argc != 2)
	{
		if (argc == 3 && ft_strcmp(argv[2], "--save") == 0)
			map.verif.save = 1;
		else
		{
			ft_putstr("Invalid number of argument.");
			map.verif.save = 0;
			ft_return_error();
		}
	}
	ft_start_all(&map);
	return (0);
}
