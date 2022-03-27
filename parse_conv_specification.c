/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conv_specification.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:45:48 by mde-maul          #+#    #+#             */
/*   Updated: 2022/01/25 15:45:50 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_arg_nb(char *ptr, t_options *options)
{
	int		arg_nb;
	char	*arg_nb_str;

	arg_nb = ft_atoi(ptr);
	arg_nb_str = handle_str_malloc(ft_itoa(arg_nb));
	if (*(ptr + ft_strlen(arg_nb_str)) != '$')
	{
		options->chars_to_skip = 0;
		return ;
	}
	if (arg_nb < 0)
		handle_error();
	if (arg_nb == 0)
	{
		options->arg_nb = 0;
		options->chars_to_skip = 0;
		return ;
	}
	options->arg_nb = arg_nb;
	options->chars_to_skip = ft_strlen(arg_nb_str) + 1;
}

void	handle_len_mod(char *ptr, t_options *options)
{
	char	*len_mod;

	len_mod = NULL;
	if (!ft_strncmp(ptr, "ll", 2) || !ft_strncmp(ptr, "hh", 2))
	{
		len_mod = handle_str_malloc(ft_strsub(ptr, 0, 2));
		options->chars_to_skip += 2;
	}
	else if (*ptr == 'l' || *ptr == 'h' || *ptr == 'L')
	{
		len_mod = handle_str_malloc(ft_strsub(ptr, 0, 1));
		options->chars_to_skip += 1;
	}
	options->len_mod = len_mod;
}

void	handle_conv_specifier(char *ptr, t_options *options)
{
	options->chars_to_skip += 1;
	if (*ptr == 'd')
		options->conv_spec = CS_D;
	else if (*ptr == 'i')
		options->conv_spec = CS_I;
	else if (*ptr == 'o')
		options->conv_spec = CS_O;
	else if (*ptr == 'u')
		options->conv_spec = CS_U;
	else if (*ptr == 'x')
		options->conv_spec = CS_X;
	else if (*ptr == 'X')
		options->conv_spec = CS_XX;
	else if (*ptr == 'f')
		options->conv_spec = CS_F;
	else if (*ptr == 'c')
		options->conv_spec = CS_C;
	else if (*ptr == 's')
		options->conv_spec = CS_S;
	else if (*ptr == 'p')
		options->conv_spec = CS_P;
	else if (*ptr == '%')
		options->conv_spec = CS_PERCENTAGE;
	else
		handle_error();
}

size_t	parse_conv_specification(char *ptr, va_list *list, \
	size_t *char_count, t_handle_arg_type **dispatcher)
{
	t_options	*options;
	size_t		chars_to_skip;

	options = (t_options *)ft_handle_malloc((void *)malloc(sizeof(t_options)), &handle_error);
	options->precision = -1;
	options->field_width = 0;
	options->no_sign = 0;
	handle_arg_nb(ptr, options);
	handle_flags(ptr + options->chars_to_skip, options);
	handle_field_width(ptr + options->chars_to_skip, options, list);
	handle_precision(ptr + options->chars_to_skip, options, list);
	handle_len_mod(ptr + options->chars_to_skip, options);
	handle_conv_specifier(ptr + options->chars_to_skip, options);
	ignore_flags(options);
	(dispatcher[options->conv_spec])(options, list, char_count);
	chars_to_skip = options->chars_to_skip;
	if (options->len_mod)
		free(options->len_mod);
	free(options);
	return (chars_to_skip);
}
