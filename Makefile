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

SRCS = ft_printf.c

SRCS_LIBFT = ./libft/ft_putstr.c \
		./libft/ft_strlen.c \
		./libft/ft_strchr.c

OBJS = $(SRCS:.c=.o)

OBJS_LIBFT = ft_putstr.o \
				ft_strlen.o \
				ft_strchr.o

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRCS) $(SRCS_LIBFT)
	ar rc $(NAME) $(OBJS) $(OBJS_LIBFT)

clean:
	rm -f $(OBJS) $(OBJS_LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

dev: re
	gcc $(FLAGS) main.c -L./ -lftprintf
	rm -f $(OBJS)
