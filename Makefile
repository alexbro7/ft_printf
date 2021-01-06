# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llefranc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/15 23:22:56 by llefranc          #+#    #+#              #
#    Updated: 2020/02/20 06:40:02 by alebross         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
FLAGS		=	-Wall -Wextra -Werror
SRCS		=	ft_printf.c \
		ft_count_args.c \
		ft_is_arg.c \
		ft_is_num.c \
		ft_get_flags.c \
		ft_put_arg.c \
		ft_put_c.c \
		ft_put_s.c \
		ft_put_p.c \
		ft_put_d.c \
		ft_put_u.c \
		ft_put_x.c \
		ft_put_mod.c \
		ft_write_untl_indc.c \
		ft_put_x_char.c \
		ft_put_hexa.c \
		ft_put_uhexa.c \
		ft_put_nbr.c \
		ft_put_unbr.c \
		ft_atoi.c \
		ft_strlen.c \
		ft_nbrlen.c \
		ft_unbrlen.c \
		ft_hexalen.c \
		ft_uhexalen.c \

OBJS		=	$(SRCS:.c=.o)

PATHINC		=	./

all		: $(NAME)

$(NAME)	:	$(OBJS)
			gcc -c $(FLAGS) $(SRCS) -I $(PATHINC)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
