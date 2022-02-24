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

void handle_arg_nb(char *ptr, t_options *options)
{
	int	arg_nb;
	char *arg_nb_str;

	arg_nb = ft_atoi(ptr);
	arg_nb_str = ft_itoa(arg_nb);
	if (*(ptr + ft_strlen(arg_nb_str)) != '$')
    {
        options->chars_to_skip = 0;
        return ;
    }
    //what is is negative?
    if (arg_nb < 0)
    {
        //printf("nope\n");
        exit(1);
    }
    if (arg_nb == 0)
    {
        options->arg_nb = 0;
        options->chars_to_skip = 0;
        return ;
    }
	//printf("%s\n", arg_nb_str);
	options->arg_nb = arg_nb;
	options->chars_to_skip = ft_strlen(arg_nb_str) + 1;
}

t_uchar get_flag(char *ptr)
{
    if (*ptr == '#')
        return (F_HASHTAG);
    else if (*ptr == '0')
        return (F_ZERO);
    else if (*ptr == '+')
        return (F_PLUS);
    else if (*ptr == '-')
        return (F_MINUS);
    else
        return (F_SPACE);
}

void    handle_flags(char *ptr, t_options *options)
{
    options->flags = 0x00;
    while (*ptr == '#' || *ptr == '0' || *ptr == '+' || *ptr == '-' || *ptr == ' ')
    {
        options->flags = options->flags | get_flag(ptr);
        options->chars_to_skip += 1;
        ptr++;
    }
}

void    handle_field_width(char *ptr, t_options *options)
{
	int	field_width;
	char *field_width_str;

    if (ft_atoi(ptr) < 0) //?? useless bc if starts with -, the - will be interpreted as a flag ??
        exit(1);
	field_width = (size_t)ft_atoi(ptr);
    if (field_width == 0)
    {
        options->field_width = 0;
		// why did i do this? if an actual 0 is specified, doesnt it get interpreted as a flag? wtf
        if (*ptr == '0') // actual printf refuses this cos undefined behavior
            options->chars_to_skip += 1;
        return ;
    }
	field_width_str = ft_itoa(field_width);
    options->field_width = field_width;
    options->chars_to_skip += ft_strlen(field_width_str);

}

void    handle_precision(char *ptr, t_options *options)
{
    int	precision;
	char *precision_str;

    if (*ptr != '.')
        return ;
	if (*ptr == '.' && ft_atoi(ptr + 1) < 0) // original: invalid conv specifier
		exit(1);
    precision = (size_t)ft_atoi(ptr + 1);
    if (precision == 0)
    {
        options->precision = 0;
        options->chars_to_skip += 1;
        if (*(ptr + 1) == '0')
            options->chars_to_skip += 1;
        return ;
    }
    precision_str = ft_itoa(precision);
    options->precision = precision;
    options->chars_to_skip += ft_strlen(precision_str) + 1;
}

void    handle_len_mod(char *ptr, t_options *options)
{
    if (!ft_strncmp(ptr, "ll", 2) || !ft_strncmp(ptr, "hh", 2))
    {
        options->len_mod = ft_strsub(ptr, 0, 2);
        options->chars_to_skip += 2;
        return ;
    }
    else if (*ptr == 'l' || *ptr == 'h' || *ptr == 'L')
    {
        options->len_mod = ft_strsub(ptr, 0, 1);
        options->chars_to_skip += 1;
    }
}

void    handle_conv_specifier(char *ptr, t_options *options)
{
    // d i o u x X f c s p and %
    char    c;

    c = *ptr;
	options->chars_to_skip += 1;
	if (c == 'd')
		options->conv_spec = CS_D;
	else if (c == 'i')
		options->conv_spec = CS_I;
	else if (c == 'o')
		options->conv_spec = CS_O;
	else if (c == 'u')
		options->conv_spec = CS_U;
	else if (c == 'x')
		options->conv_spec = CS_X;
	else if (c == 'X')
		options->conv_spec = CS_XX;
	else if (c == 'f')
		options->conv_spec = CS_F;
	else if (c == 'c')
		options->conv_spec = CS_C;
	else if (c == 's')
		options->conv_spec = CS_S;
	else if (c == 'p')
		options->conv_spec = CS_P;
	else if (c == '%')
		options->conv_spec = CS_PERCENTAGE;
    else
        exit(1);
    // if no conv spec: invalid input??
}

size_t	parse_conv_specification(char *ptr, va_list *list, size_t *char_count, handle_arg_type **dispatcher)
{
	t_options	*options;
	size_t		chars_to_skip;

	options = (t_options *)malloc(sizeof(t_options));
	if (!options)
		handle_error();
    options->len_mod = NULL;
    options->precision = -1;
    handle_arg_nb(ptr, options);
    handle_flags(ptr + options->chars_to_skip, options);
    handle_field_width(ptr + options->chars_to_skip, options);
    handle_precision(ptr + options->chars_to_skip, options);
    handle_len_mod(ptr + options->chars_to_skip, options);
    handle_conv_specifier(ptr + options->chars_to_skip, options);
    //printf("flags : %x\n", options->flags);
    //printf("field width %zu\n", options->field_width);
    //printf("precision %zu\n", options->precision);
    //printf("len mod %s\n", options->len_mod);
    //printf("conv spec %x\n", options->conv_spec);
	//printf("hey\n");
	(dispatcher[options->conv_spec])(options, list, char_count);
    if (options->len_mod)
        free(options->len_mod);
	/*// by what black magic was this working? if you free it how can you access it???
    free(options);
	return (options->chars_to_skip);
	*/
	chars_to_skip = options->chars_to_skip;
	free(options);
	return (chars_to_skip);
}
