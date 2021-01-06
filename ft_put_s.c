/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:06:40 by alebross          #+#    #+#             */
/*   Updated: 2020/02/16 17:47:06 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_s(t_pf *pf)
{
	char	*s;
	int		boul;
	int		c;

	s = va_arg(pf->ap, char *);
	boul = 0;
	c = (pf->lz ? '0' : ' ');
	if (!s)
	{
		boul = 1;
		pf->sz = 6;
		s = "(null).";
	}
	else
		pf->sz = ft_strlen(s);
	pf->l2 = (pf->pcs < pf->sz && pf->pcs > 0 ? pf->pcs : pf->sz);
	pf->l2 = (pf->bp && !pf->pcs ? 0 : pf->l2);
	pf->l2 = (!pf->l2 && pf->rp ? pf->sz : pf->l2);
	pf->l1 = (pf->len > pf->l2 ? pf->len - pf->l2 : 0);
	if (pf->rl == 0)
		ft_put_x_char(pf->l1, c);
	write(1, s, pf->l2);
	if (pf->rl == 1)
		ft_put_x_char(pf->l1, ' ');
	pf->ret += (pf->l1 + pf->l2);
}
