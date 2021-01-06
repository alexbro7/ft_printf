/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:19:03 by alebross          #+#    #+#             */
/*   Updated: 2020/02/14 19:10:38 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_c(t_pf *pf)
{
	int		c;

	c = va_arg(pf->ap, int);
	if (pf->rl == 0)
		ft_put_x_char(pf->len - 1, ' ');
	write(1, &c, 1);
	if (pf->rl == 1)
		ft_put_x_char(pf->len - 1, ' ');
	pf->ret += pf->len;
	pf->ret += (pf->len == 0 ? 1 : 0);
}
