/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:45:22 by mde-maul          #+#    #+#             */
/*   Updated: 2022/01/25 15:45:25 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    int   precision;
    char    *len_mod;
    t_uchar conv_spec;
}               t_options;

typedef void handle_arg_type(t_options *options, va_list *list, size_t *char_count);

int     ft_printf(const char *str, ...);
size_t	parse_conv_specification(char *ptr, va_list *list, size_t *char_count, handle_arg_type **dispatcher);
void	handle_error(void);
void    handle_percentage(t_options *options, va_list *list, size_t *char_count);
void    handle_char(t_options *options, va_list *list, size_t *char_count);
void    handle_str(t_options *options, va_list *list, size_t *char_count);
void    handle_d(t_options *options, va_list *list, size_t *char_count);
void	handle_hex(t_options *options, va_list *list, size_t *char_count, size_t is_X);
void	handle_hex_x(t_options *options, va_list *list, size_t *char_count);
void	handle_hex_X(t_options *options, va_list *list, size_t *char_count);
void	handle_oct(t_options *options, va_list *list, size_t *char_count);
void	handle_decimal(t_options *options, va_list *list, size_t *char_count);

# define F_HASHTAG 0x80
# define F_ZERO 0x40
# define F_PLUS 0x20
# define F_MINUS 0x10
# define F_SPACE 0x08

# define CS_D 0x00
# define CS_I 0x01
# define CS_O 0x02
# define CS_U 0x03
# define CS_X 0x04
# define CS_XX 0x05
# define CS_F 0x06
# define CS_C 0x07
# define CS_S 0x08
# define CS_P 0x09
# define CS_PERCENTAGE 0x0a

#endif
