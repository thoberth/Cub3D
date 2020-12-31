/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_to_array_of_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 10:09:21 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/17 16:25:46 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

char	**ft_line_to_array_of_str(char **map, char *line, int c)
{
	int		i;
	char	**res;
	int		j;

	i = c;
	j = 0;
	if (!(res = malloc(sizeof(char *) * (i + 2))))
		return (NULL);
	res[i + 1] = NULL;
	while (j < i)
	{
		res[j] = ft_strdup(map[j]);
		j++;
	}
	res[i] = ft_strdup(line);
	return (res);
}
