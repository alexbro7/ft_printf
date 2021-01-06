/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:32:32 by alebross          #+#    #+#             */
/*   Updated: 2020/02/21 15:35:17 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_d2(t_pf *pf, int n)
{
	if (!(pf->bp && !pf->pcs && !pf->rp && !n))
		ft_put_nbr(n);
	if (pf->rl == 1)
		ft_put_x_char(pf->l1, ' ');
	pf->ret += (pf->l1 + pf->l2 + pf->sz);
	pf->ret -= (pf->l1 && pf->bp && !pf->pcs
			&& !pf->rp && !pf->lz && !n ? 1 : 0);
	pf->ret -= (pf->lz && pf->bp && !pf->pcs && !n ? 1 : 0);
	pf->ret += (!pf->l1 && pf->rp && !n ? 1 : 0);
}

void	ft_put_d(t_pf *pf)
{
	int		n;
	int		c;

	n = va_arg(pf->ap, int);
	c = (pf->lz && (!pf->bp || pf->rp) ? '0' : ' ');
	pf->sz = (!n && !pf->pcs && !pf->len && pf->bp ? 0 : ft_nbrlen(n));
	pf->l2 = (pf->pcs > pf->sz ? pf->pcs - pf->sz : 0);
	pf->l2 += (pf->l2 && n < 0 ? 1 : 0);
	pf->l2 += (n < 0 && pf->pcs == pf->sz ? 1 : 0);
	pf->l1 = (pf->len > pf->sz + pf->l2 ? pf->len - (pf->sz + pf->l2) : 0);
	pf->l1 += (pf->l1 && pf->bp && !pf->pcs && !pf->rp
			&& !pf->lz && !n ? 1 : 0);
	pf->l1 += (pf->lz && pf->bp && !pf->pcs && !n ? 1 : 0);
	if (c == '0' && pf->l1 && n < 0)
		write(1, "-", 1);
	if (!pf->rl)
		ft_put_x_char(pf->l1, c);
	if (!(c == '0' && pf->l1) && n < 0)
		write(1, "-", 1);
	ft_put_x_char(pf->l2, '0');
	if (n == -2147483648)
		write(1, "2", 1);
	n = (n == -2147483648 ? 147483648 : n);
	n *= (n < 0 ? -1 : 1);
	ft_put_d2(pf, n);
}
