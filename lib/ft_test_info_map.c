/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_info_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berthetthomas <berthetthomas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 10:39:41 by thoberth          #+#    #+#             */
/*   Updated: 2020/09/23 13:24:02 by berthetthom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

int		ft_test_info_map(t_list_map *map)
{
	if (map->verif_reso != 1 || map->verif_f != 1 ||map->verif_c != 1 ||
		map->no == NULL || map->so == NULL || map->ea == NULL || map->we == NULL ||
		map->sprite == NULL)
		return (-1);
	return (0);
}