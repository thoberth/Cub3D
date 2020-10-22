/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_info_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 10:39:41 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/22 17:47:33 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

int		ft_test_info_map(t_list_map *map)
{
	if (map->verif.verif_reso != 1 || map->verif.verif_f != 1 ||map->verif.verif_c != 1 ||
		map->map.no == NULL || map->map.so == NULL || map->map.ea == NULL || map->map.we == NULL ||
		map->map.sprite == NULL)
		return (-1);
	return (0);
}