/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:18:34 by alebross          #+#    #+#             */
/*   Updated: 2020/02/14 19:12:02 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_nbr(int nb)
{
	int		x;
	int		ret;

	ret = ft_nbrlen(nb);
	x = 1;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		ft_put_x_char(1, '-');
		nb = nb * -1;
	}
	while (nb / x > 9)
		x *= 10;
	while (x)
	{
		ft_put_x_char(1, (nb / x) + 48);
		nb %= x;
		x /= 10;
	}
	return (ret);
}
