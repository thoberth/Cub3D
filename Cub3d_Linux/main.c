/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:07:53 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/31 15:28:08 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/libcub.h"

int	main(int argc, char **argv)
{
	t_list_map	map;
	int			i;

	map.verif.save = 0;
	i = ft_strlen(argv[1]) - 4;
	if (ft_strcmp(&argv[1][i], ".cub"))
		ft_return_error(&map, WRONG_NUMBER_ARGUMENTS);
	if (argc != 2)
	{
		if (argc == 3 && ft_strcmp(argv[2], "--save") == 0)
			map.verif.save = 1;
		else
			ft_return_error(&map, WRONG_NUMBER_ARGUMENTS);
	}
	ft_start_all(&map, argv[1]);
	return (EXIT_SUCCESS);
}
