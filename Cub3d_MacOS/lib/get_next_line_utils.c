/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:29:52 by thoberth          #+#    #+#             */
/*   Updated: 2020/09/18 11:35:07 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_test_if_n(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-i);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int a)
{
	int		t;
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	t = ft_strlen(s1) + a;
	if (!(res = malloc(sizeof(char) * (t + 1))))
		return (NULL);
	res[t] = '\0';
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] && j < a)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	s1 = NULL;
	return (res);
}

char	*ft_strdup_gnl(char *s1, int a)
{
	int		i;
	int		t;
	char	*dup;

	i = 0;
	t = a;
	dup = NULL;
	if (!(dup = malloc(sizeof(char) * (t + 1))))
		return (NULL);
	dup[t] = '\0';
	while (i < t)
	{
		dup[i] = s1[i];
		i++;
	}
	return (dup);
}
