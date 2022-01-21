#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>
//delete
#include <stdio.h>

void	ft_putstr(char const *s);

int	ft_printf(const char *str, ...);

typedef int handle_arg_type(va_list *list);

typedef struct s_handle_arg {
    char    *arg;
    handle_arg_type *func;
}               t_handle_arg;

#endif
