/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:41:12 by alebross          #+#    #+#             */
/*   Updated: 2020/02/16 17:34:26 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_arg2(const char *fmt, int i, int j, char const *indics)
{
	i += (fmt[i] == '.' ? 1 : 0);
	if ((fmt[i] >= '0' && fmt[i] <= '9') || fmt[i] == '-')
		while ((fmt[i] >= '0' && fmt[i] <= '9') || fmt[i] == '-')
			i++;
	else if (fmt[i] == '*')
		i++;
	while (j < 9)
	{
		if (fmt[i] == indics[j])
			return (1);
		j++;
	}
	return (0);
}

int		ft_is_arg(const char *fmt, const char *indics)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (fmt[i] == '%')
	{
		i++;
		if ((fmt[i] >= '0' && fmt[i] <= '9') || fmt[i] == '-')
		{
			while ((fmt[i] >= '0' && fmt[i] <= '9') || fmt[i] == '-')
				i++;
		}
		if (fmt[i] == '*')
			i++;
		return (ft_is_arg2(fmt, i, j, indics));
	}
	return (0);
}
