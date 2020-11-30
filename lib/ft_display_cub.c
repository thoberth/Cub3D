/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:43:28 by thoberth          #+#    #+#             */
/*   Updated: 2020/11/19 13:19:16 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

int    ft_display_fc(t_list_map *map, int v, int i)
{   
    int     t;

    t = 0;
    while (t < map->dis.t_fc)
    {
        map->data.data_addr[i++] = (v ? map->map.f[0] : map->map.c[0]);
        map->data.data_addr[i++] = (v ? map->map.f[1] : map->map.c[1]);
        map->data.data_addr[i++] = (v ? map->map.f[2] : map->map.c[2]);
        i += map->map.size_line - 3;
        t++;
    }
    return (i);
}

int     ft_display_wall(t_list_map *map, int i)
{
    int     t;

    t = 0;
    while (t < map->dis.t_wall)
    {
        map->data.data_addr[i++] = map->dis.color_wall;
        map->data.data_addr[i++] = map->dis.color_wall;
        map->data.data_addr[i++] = map->dis.color_wall;
        i += map->map.size_line - 3;
        t++;
    }
    return (i);
}

void    ft_display_cub(t_list_map *map)
{
    int     i;
    int     a;
    int     tmp;

    i = 0;
    a = 0;
    while(a < map->map.reso[0])
    {
        tmp = i + 4;
        if (map->tex.wall_tex[a][0] == 1 || map->tex.wall_tex[a][0] == 0)
            map->dis.color_wall = 125;
        else
            map->dis.color_wall = 150;
        map->dis.t_wall = 64 / map->ray.dist[a] * map->ray.dist_to_pp;
        map->dis.t_fc = (map->map.reso[1] - map->dis.t_wall) / 2;
        if (map->dis.t_wall + (map->dis.t_fc * 2) < map->map.reso[1])
            map->dis.t_wall++;
        if (map->dis.t_wall > map->map.reso[1])
        {
            map->dis.t_wall = map->map.reso[1];
            i = ft_display_wall(map, i);
        }
        else
        {
            i = ft_display_fc(map, 1, i);
            i = ft_display_wall(map, i);
            i = ft_display_fc(map, 0, i);
        }
        i = tmp;
        a++;
    }
}