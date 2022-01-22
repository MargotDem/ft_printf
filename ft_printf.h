#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
//delete
#include <stdio.h>

typedef unsigned char t_uchar;

int     ft_printf(const char *str, ...);
size_t	parse_conv_specification(char *ptr, va_list *list);

typedef int handle_arg_type(va_list *list);

typedef struct s_options {
    char    *arg_nb;
    t_uchar flags;
    size_t  chars_to_skip;
}               t_options;

# define F_HASHTAG 0x80
# define F_ZERO 0x40
# define F_PLUS 0x20
# define F_MINUS 0x10
# define F_SPACE 0x08

typedef struct s_handle_arg {
    char    *arg;
    handle_arg_type *func;
}               t_handle_arg;

#endif
