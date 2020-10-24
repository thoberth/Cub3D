/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dist_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:59:58 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/24 18:03:20 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

float	ft_dist_wallh(t_list_map *map)
{
	if ()
}

float	ft_dist_wall(t_list_map *map)
{
	float	a;
	float	b;

	a = ft_dist_wallv(map);
	b = ft_dist_wallh(map);
	if (a < b)
		return (a);
	return (b);
}