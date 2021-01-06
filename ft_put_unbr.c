/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:50:10 by alebross          #+#    #+#             */
/*   Updated: 2020/02/10 07:45:10 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_unbr(unsigned int nb)
{
	int		x;
	int		ret;

	ret = ft_unbrlen(nb);
	x = 1;
	while (nb / x > 9)
		x *= 10;
	while (x)
	{
		ft_put_x_char(1, nb / x + 48);
		nb %= x;
		x /= 10;
	}
	return (ret);
}
