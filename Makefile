# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 14:46:04 by mde-maul          #+#    #+#              #
#    Updated: 2022/01/18 14:46:07 by mde-maul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a

SRCS = ft_printf.c parse_conv_specification.c utils_set_nb.c handle_error.c \
	conv_f.c conv_c.c conv_percentage.c conv_p.c utils_floats.c \
	conv_x.c conv_o.c conv_s.c conv_d.c conv_u.c utils_format_str.c \
	utils_print_str.c parse_flags.c parse_field_width.c parse_precision.c \
	utils_floats2.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C ./libft
	cp ./libft/libft.a $(NAME)
	gcc $(FLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean:
	make -C ./libft clean
	rm -f $(OBJS)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all

dev:
	cp ./libft/libft.a $(NAME)
	gcc $(FLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJS)
	gcc $(FLAGS) main.c -L./ -lftprintf
	rm -f $(OBJS)
