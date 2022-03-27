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

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
//delete
# include <stdio.h>

typedef unsigned char	t_uchar;
typedef unsigned short	t_uint16;

typedef struct s_options {
	size_t	arg_nb;
	t_uchar	flags;
	size_t	chars_to_skip;
	size_t	field_width;
	int		precision;
	char	*len_mod;
	t_uchar	conv_spec;
	int		no_sign;
}	t_options;

typedef void			t_handle_arg_type(t_options *options, \
	va_list *list, size_t *char_count);

int		ft_printf(const char *str, ...);
size_t	parse_conv_specification(char *ptr, va_list *list, \
	size_t *char_count, t_handle_arg_type **dispatcher);
void	handle_error(void);
void	handle_percentage(t_options *options, va_list *list, \
	size_t *char_count);
void	handle_char(t_options *options, va_list *list, size_t *char_count);
void	handle_str(t_options *options, va_list *list, size_t *char_count);
void	handle_d(t_options *options, va_list *list, size_t *char_count);
void	handle_hex(t_options *options, va_list *list, \
	size_t *char_count, size_t is_X);
void	handle_hex_x(t_options *options, va_list *list, size_t *char_count);
void	handle_hex_xx(t_options *options, va_list *list, size_t *char_count);
void	handle_oct(t_options *options, va_list *list, size_t *char_count);
void	handle_decimal(t_options *options, va_list *list, size_t *char_count);
void	handle_f(t_options *options, va_list *list, size_t *char_count);
void	handle_p(t_options *options, va_list *list, size_t *char_count);
void	padded_print(char *str, t_options *options, size_t *char_count);
char	*adjust_str(char *nb_str, size_t precision, \
	int field_width, t_options *options);
int		handle_isnan(long double nb, t_options *options, size_t *char_count);
int		handle_isinf(long double nb, t_options *options, size_t *char_count);
char	*round_main(char *nb_str, long long int main, size_t len, \
	int is_positive);
char	*round_float(char *nb_str, long double last_digit, \
	size_t len, long double test_stl);
void	set_nb_unsigned(t_options *options, va_list *list, \
	unsigned long long int *nb);
void	print_out_nb_str(t_options *options, size_t *char_count, \
	size_t len, char *nb_str);
void	set_nb(t_options *options, va_list *list, long long int *nb);
void	set_nb_unsigned(t_options *options, va_list *list, \
	unsigned long long int *nb);
void	handle_flags(char *ptr, t_options *options);
void	ignore_flags(t_options *options);
void	handle_field_width(char *ptr, t_options *options, va_list *list);
void	handle_precision(char *ptr, t_options *options, va_list *list);
char	*handle_flags_f(t_options *options, char *nb_str, \
	long double original_nb, int is_negzero);

# define F_HASHTAG 0x80
# define F_ZERO 0x40
# define F_PLUS 0x20
# define F_MINUS 0x10
# define F_SPACE 0x08

# define CS_D 0
# define CS_I 1
# define CS_O 2
# define CS_U 3
# define CS_X 4
# define CS_XX 5
# define CS_F 6
# define CS_C 7
# define CS_S 8
# define CS_P 9
# define CS_PERCENTAGE 10

#endif
