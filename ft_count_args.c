/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:41:44 by alebross          #+#    #+#             */
/*   Updated: 2020/02/10 06:56:30 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_args(const char *fmt)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (fmt[i])
	{
		ret += ft_is_arg(fmt + i, "cspdiuxX%");
		i++;
	}
	return (ret);
}
