/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:35:03 by alebross          #+#    #+#             */
/*   Updated: 2020/02/14 19:10:22 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_pf pf;

	pf.i = 0;
	pf.indics = "cspdiuxX%";
	pf.ret = 0;
	if (format)
	{
		if ((pf.argcnt = ft_count_args(format)))
			va_start(pf.ap, format);
		while (format[pf.i])
		{
			pf.ret += ft_write_untl_indc(format, &pf.i);
			if (ft_is_arg(format + pf.i, pf.indics))
			{
				pf = ft_get_flags(format, pf);
				ft_put_arg(&pf);
			}
		}
		if (pf.argcnt)
			va_end(pf.ap);
	}
	return (pf.ret);
}
