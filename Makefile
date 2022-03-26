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

SRCS = ft_printf.c parse_conv_specification.c utils.c handle_error.c \
	conv_f.c conv_c.c conv_percentage.c conv_p.c utils_floats.c \
	conv_x.c conv_o.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C ./libft
	cp ./libft/libft.a $(NAME)
	gcc $(CFLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean:
	make -C ./libft clean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

dev:
	cp ./libft/libft.a $(NAME)
	gcc $(CFLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJS)
	gcc $(FLAGS) main.c tests/*.c -L./ -lftprintf
	rm -f $(OBJS)
