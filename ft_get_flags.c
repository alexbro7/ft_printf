/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:26:41 by alebross          #+#    #+#             */
/*   Updated: 2020/02/16 17:34:10 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf	ft_get_flags2(const char *fmt, t_pf pf)
{
	if (fmt[pf.i] == '.')
	{
		pf.bp = 1;
		pf.i++;
		if (ft_is_num(fmt + pf.i))
		{
			pf.pcs = ft_atoi(fmt + pf.i);
			pf.i += (fmt[pf.i] == '-' ? 1 : 0);
			while (fmt[pf.i] >= '0' && fmt[pf.i] <= '9')
				pf.i++;
		}
		else if (fmt[pf.i] == '*')
		{
			pf.pcs = va_arg(pf.ap, int);
			pf.i++;
			pf.rp = (pf.pcs < 0 ? 1 : 0);
		}
		pf.pcs = (pf.pcs < 0 ? 0 : pf.pcs);
	}
	while (fmt[pf.i] != pf.indics[pf.type])
		pf.type++;
	pf.i++;
	return (pf);
}

t_pf	ft_get_flags(const char *fmt, t_pf pf)
{
	pf.len = 0;
	pf.pcs = 0;
	pf.type = 0;
	pf.bp = 0;
	pf.rp = 0;
	pf.i++;
	pf.i += (pf.lz = (fmt[pf.i] == '0' ? 1 : 0));
	pf.i += (pf.rl = (fmt[pf.i] == '-' ? 1 : 0));
	if ((fmt[pf.i] >= '0' && fmt[pf.i] <= '9') || fmt[pf.i] == '-')
	{
		pf.len = ft_atoi(fmt + pf.i);
		while ((fmt[pf.i] >= '0' && fmt[pf.i] <= '9') || fmt[pf.i] == '-')
			pf.i++;
	}
	else if (fmt[pf.i] == '*')
	{
		pf.len = va_arg(pf.ap, int);
		pf.i++;
	}
	pf.rl = (pf.len < 0 || pf.rl ? 1 : 0);
	pf.len *= (pf.len < 0 ? -1 : 1);
	return (ft_get_flags2(fmt, pf));
}
