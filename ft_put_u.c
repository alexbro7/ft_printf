/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 01:05:35 by alebross          #+#    #+#             */
/*   Updated: 2020/02/16 17:39:51 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_u(t_pf *pf)
{
	unsigned int	n;
	int				c;

	n = va_arg(pf->ap, unsigned int);
	c = (pf->lz && !pf->bp ? '0' : ' ');
	pf->sz = ft_unbrlen(n);
	pf->l2 = (pf->pcs > pf->sz ? pf->pcs - pf->sz : 0);
	pf->l1 = (pf->len > pf->sz + pf->l2 ? pf->len - (pf->sz + pf->l2) : 0);
	pf->l1 += (pf->l1 && !n && pf->bp && !pf->pcs ? 1 : 0);
	if (pf->rl == 0)
		ft_put_x_char(pf->l1, c);
	ft_put_x_char(pf->l2, '0');
	if (!(pf->bp && !pf->pcs && !n))
		ft_put_unbr(n);
	if (pf->rl == 1)
		ft_put_x_char(pf->l1, ' ');
	pf->ret += (pf->l1 + pf->l2 + pf->sz);
	pf->ret -= (!n && pf->bp && !pf->pcs ? 1 : 0);
}
