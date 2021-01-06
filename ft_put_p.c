/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:46:59 by alebross          #+#    #+#             */
/*   Updated: 2020/02/19 17:56:25 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_p(t_pf *pf)
{
	unsigned long long	addr;

	addr = va_arg(pf->ap, long long);
	pf->sz = ft_uhexalen(addr);
	pf->l2 = (pf->pcs > pf->sz ? pf->pcs - (pf->sz) : 0);
	pf->l1 = 0;
	if (pf->len > pf->l2 + pf->sz + 2)
		pf->l1 = pf->len - (pf->l2 + pf->sz + 2);
	pf->l1 += (pf->l1 && (pf->bp || pf->pcs) && !addr ? 1 : 0);
	if (!pf->rl)
		ft_put_x_char(pf->l1, ' ');
	write(1, "0x", 2);
	ft_put_x_char(pf->l2, '0');
	if (addr)
		ft_put_uhexa((unsigned long long)addr, "0123456789abcdef");
	if (addr)
		pf->ret += pf->sz;
	else if (!pf->bp || pf->pcs)
	{
		write(1, "0", 1);
		pf->ret += 1;
	}
	if (pf->rl)
		ft_put_x_char(pf->l1, ' ');
	pf->ret += pf->l1 + pf->l2 + 2;
}
