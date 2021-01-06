/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_untl_indc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:45:58 by alebross          #+#    #+#             */
/*   Updated: 2020/02/16 17:47:57 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_write_untl_indc(const char *fmt, int *i)
{
	int		ret;

	ret = 0;
	while (fmt[*i])
	{
		if (fmt[*i] == '%')
		{
			if (ft_is_arg(fmt + *i, "cspdiuxX%"))
				return (ret);
			*i += 1;
		}
		write(1, fmt + *i, 1);
		*i += 1;
		ret++;
	}
	return (ret);
}
