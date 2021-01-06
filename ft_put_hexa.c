/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:39:41 by alebross          #+#    #+#             */
/*   Updated: 2020/02/19 12:08:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_hexa(unsigned int n, char *base)
{
	unsigned int	x;
	char			c;
	int				ret;

	ret = ft_hexalen(n);
	if (!n)
	{
		write(1, "0", 1);
		return (ret);
	}
	x = (n > 15 ? 16 : 1);
	while (n / x > 15)
		x *= 16;
	while (x)
	{
		c = base[n / x];
		write(1, &c, 1);
		n %= x;
		x /= 16;
	}
	return (ret);
}
