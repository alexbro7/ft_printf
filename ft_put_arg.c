/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:47:00 by alebross          #+#    #+#             */
/*   Updated: 2020/02/11 22:55:49 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_arg(t_pf *pf)
{
	void	(*ptr[9])(t_pf *);

	ptr[0] = &ft_put_c;
	ptr[1] = &ft_put_s;
	ptr[2] = &ft_put_p;
	ptr[3] = &ft_put_d;
	ptr[4] = &ft_put_d;
	ptr[5] = &ft_put_u;
	ptr[6] = &ft_put_x;
	ptr[7] = &ft_put_x;
	ptr[8] = &ft_put_mod;
	ptr[pf->type](pf);
}
