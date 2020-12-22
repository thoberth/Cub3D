/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:07:53 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/18 12:49:59 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libcub.h"

int main (int argc, char **argv)
{
	t_list_map	map;
	
	ft_init_map(&map, argv[1]);
	if (argc != 2)
	{
		if (argc == 3 && ft_strcmp(argv[2], "--save") == 0)
			map.verif.save = 1;
		else
			ft_return_error(&map, WRONG_NUMBER_ARGUMENTS);
	}
	ft_start_all(&map);
	return (EXIT_SUCCESS);
}
