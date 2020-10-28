/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berthetthomas <berthetthomas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:11:42 by thoberth          #+#    #+#             */
/*   Updated: 2020/10/28 19:04:52 by berthetthom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub.h"

long int	count(long int nb)
{
	int		i;

	i = 1;
	while (nb > 9)
	{
		nb /= 10;
		i *= 10;
	}
	return (i);
}

void		ft_putnbr(int nb)
{
	int			i;
	int			nbr;
	long int	number;

	number = nb;
	if (number < 0)
	{
		number *= -1;
		ft_putchar('-');
	}
	i = count(number);
	while (number > 9)
	{
		nbr = number / i;
		ft_putchar(nbr + 48);
		number -= nbr * i;
		i /= 10;
	}
	while (i > 1)
	{
		ft_putchar('0');
		i /= 10;
	}
	ft_putchar(number + 48);
	ft_putchar('\n');
}
