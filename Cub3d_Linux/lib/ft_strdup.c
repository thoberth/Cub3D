/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:08:52 by thoberth          #+#    #+#             */
/*   Updated: 2020/12/17 16:14:20 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

char	*ft_strdup(char *s1)
{
	int		i;
	int		t;
	char	*dup;

	i = 0;
	t = ft_strlen(s1);
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
