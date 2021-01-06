/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 02:32:37 by alebross          #+#    #+#             */
/*   Updated: 2020/02/21 15:37:09 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_x(t_pf *pf)
{
	unsigned int	n;
	char			*base;
	int				c;

	n = va_arg(pf->ap, unsigned int);
	base = (pf->type == 6 ? "0123456789abcdef" : "0123456789ABCDEF");
	c = (pf->lz && (!pf->bp || pf->rp) ? '0' : ' ');
	pf->sz = ft_hexalen(n);
	pf->l2 = (pf->pcs > pf->sz ? pf->pcs - pf->sz : 0);
	pf->l2 += (pf->l2 && n < 0 ? 1 : 0);
	pf->l1 = (pf->len > pf->sz + pf->l2 ? pf->len - (pf->sz + pf->l2) : 0);
	pf->l1 += (pf->l1 && pf->bp && !pf->pcs && !pf->rp && !n ? 1 : 0);
	if (pf->rl == 0)
		ft_put_x_char(pf->l1, c);
	if (n < 0)
		write(1, "-", 1);
	n *= (n < 0 ? -1 : 1);
	ft_put_x_char(pf->l2, '0');
	if (!(pf->bp && !pf->pcs && !pf->rp && !n))
		ft_put_hexa(n, base);
	else
		pf->sz -= 1;
	if (pf->rl == 1)
		ft_put_x_char(pf->l1, ' ');
	pf->ret += (pf->l1 + pf->l2 + pf->sz);
}
