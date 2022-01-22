#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
//delete
#include <stdio.h>

typedef unsigned char t_uchar;
typedef unsigned short t_uint16;

typedef struct s_options {
    size_t  arg_nb;
    t_uchar flags;
    size_t  chars_to_skip;
    size_t  field_width;
    size_t  precision;
    char    *len_mod;
    t_uchar conv_spec;
}               t_options;

int     ft_printf(const char *str, ...);
size_t	parse_conv_specification(char *ptr, va_list *list);
void    dispatch(t_options *options, va_list *list);
//static int	handle_int(va_list *list);
//static int	handle_str(va_list *list);
//static int	handle_garbage(va_list *list);
//static int	handle_nothing(va_list *list);


typedef int handle_arg_type(va_list *list);
typedef void handle_arg_type2(t_options *options, va_list *list);
typedef void handle_arg_type3(char *str);


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
