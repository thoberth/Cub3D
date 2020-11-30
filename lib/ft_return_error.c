/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoberth <thoberth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 13:21:32 by berthetthom       #+#    #+#             */
/*   Updated: 2020/11/28 14:49:37 by thoberth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

/*
// A completer
*/
int     ft_return_error(void)
{
    ft_putstr("Error, invalid file .cub\n");
    return (-1);
}