/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:45:27 by alebross          #+#    #+#             */
/*   Updated: 2020/02/14 19:14:03 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_put_x_char(int x, int c)
{
	int		tmp;

	if (x < 1)
		return (0);
	tmp = x;
	while (tmp)
	{
		write(1, &c, 1);
		tmp--;
	}
	return (x);
}
