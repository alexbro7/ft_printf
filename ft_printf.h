/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:36:15 by alebross          #+#    #+#             */
/*   Updated: 2020/02/20 06:40:40 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct	s_pf
{
	va_list		ap;
	char		*indics;
	int			i;
	int			argcnt;
	int			ret;
	int			len;
	int			rl;
	int			lz;
	int			rp;
	int			bp;
	int			pcs;
	int			type;
	int			l1;
	int			l2;
	int			sz;
}				t_pf;

int				ft_printf(const char *format, ...);
int				ft_count_args(const char *fmt);
int				ft_is_arg(const char *fmt, const char *indcs);
t_pf			ft_get_flags(const char *fmt, t_pf pf);
void			ft_put_arg(t_pf *pf);
void			ft_put_c(t_pf *pf);
void			ft_put_s(t_pf *pf);
void			ft_put_p(t_pf *pf);
void			ft_put_d(t_pf *pf);
void			ft_put_u(t_pf *pf);
void			ft_put_x(t_pf *pf);
void			ft_put_mod(t_pf *pf);
int				ft_write_untl_indc(const char *fmt, int *i);
int				ft_put_x_char(unsigned int x, int c);
int				ft_put_hexa(unsigned int n, char *base);
int				ft_put_uhexa(unsigned long long n, char *base);
int				ft_put_nbr(int nb);
int				ft_put_unbr(unsigned int nb);
int				ft_atoi(const char *str);
int				ft_strlen(char *str);
int				ft_nbrlen(int nb);
int				ft_unbrlen(unsigned int nb);
int				ft_hexalen(unsigned int nb);
int				ft_uhexalen(unsigned long long nb);
int				ft_is_num(char const *str);

#endif
