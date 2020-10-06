/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 12:15:12 by thoberth          #+#    #+#             */
/*   Updated: 2020/09/17 15:48:21 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"
#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		t;
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	t = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = malloc(sizeof(char) * (t + 1))))
		return (NULL);
	res[t] = '\0';
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	return (res);
}
