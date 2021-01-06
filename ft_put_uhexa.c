/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:36:05 by alebross          #+#    #+#             */
/*   Updated: 2020/02/19 17:36:59 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_uhexa(unsigned long long n, char *base)
{
	unsigned long long	x;
	char				c;
	int					ret;

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
