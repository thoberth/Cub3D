/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:43:28 by thoberth          #+#    #+#             */
/*   Updated: 2020/11/06 18:48:12 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

void    ft_display_cub(t_list_map *map)
{
    int     i;
    int     t;
    int     a;
    int     tmp;
    int     dist;
    int     dist_fc;

    i = 0;
    a = 0;
    while(a < map->map.reso[0])
    {
        t = 0;
        tmp = i + 4;
        dist = 64 / map->ray.dist[a] * map->ray.dist_to_pp;
        dist_fc = (map->map.reso[1] - dist) / 2;
        while (t < dist_fc)
        {
            map->data.data_addr[i++] = map->map.f[0];
            map->data.data_addr[i++] = map->map.f[1];
            map->data.data_addr[i++] = map->map.f[2];
            i += map->map.size_line - 3;
            t++;
        }
        t = 0;
        if (dist > 0)
        {
            while (t < dist)
            {
                map->data.data_addr[i++] = 125;
                map->data.data_addr[i++] = 125;
                map->data.data_addr[i++] = 125;
                i += map->map.size_line - 3;
                t++;
            }
            t = 0;
        }
        while (t < dist_fc)
        {
            map->data.data_addr[i++] = map->map.c[0];
            map->data.data_addr[i++] = map->map.c[1];
            map->data.data_addr[i++] = map->map.c[2];
            i += map->map.size_line - 3;
            t++;
        }
        i = tmp;
        a++;
    }
}