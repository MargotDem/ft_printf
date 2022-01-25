/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:45:38 by mde-maul          #+#    #+#             */
/*   Updated: 2022/01/25 15:45:40 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    zero_pad_print(int  nb, size_t precision)
{
    size_t   len;
    size_t  zeroes;
    size_t  neg;
    char    *nb_str;

    neg = 0;
    if (nb < 0)
    {
        nb = -nb;
        neg = 1;
    }
    nb_str = ft_itoa(nb);
    len = ft_strlen(nb_str);
    zeroes = precision - len;
    if (neg)
        ft_putchar('-');
    while (zeroes > 0)
    {
        ft_putchar('0');
        zeroes--;
    }
    ft_putstr(nb_str);
}

char	*adjust_int(char *nb_str, size_t precision, int field_width)
{
	char	*tmp;
	char	*tmp_ptr;
	char	*nb_str_ptr;
	size_t   len;
	int  zeroes;

	len = ft_strlen(nb_str);
	zeroes = precision - len;
	if (zeroes < 0)
		return (nb_str);
	if (*nb_str == '-' && !(field_width))
		zeroes++;
	tmp = (char *)malloc(zeroes + len + 1);
	tmp_ptr = tmp;
	nb_str_ptr = nb_str;
	if (*nb_str == '-')
	{
		ft_memset(tmp_ptr, '-', 1);
		tmp_ptr++;
		nb_str_ptr++;
	}
	ft_memset(tmp_ptr, '0', zeroes);
	ft_strcpy(tmp_ptr + zeroes, nb_str_ptr);
	free (nb_str);
	nb_str = tmp;
	return (nb_str);
}

void	padded_print(char *str, t_options *options)
{
	size_t	len;
	size_t	total_len;
	int		padding;

	len = ft_strlen(str);
	total_len = options->field_width;
	padding = total_len - len;
	if (options->flags & F_MINUS)
		ft_putstr(str);
	while (padding > 0)
	{
		ft_putchar(' ');
		padding--;
	}
	if (!(options->flags & F_MINUS))
		ft_putstr(str);
}

void    handle_int(t_options *options, va_list *list)
{
    char *nb_str;
    int nb;
	size_t	len;

    nb = va_arg(*list, int);
    nb_str = ft_itoa(nb);
	len = ft_strlen(nb_str);
	if (nb < 0)
		len--;
	if (options->precision == -1 && options->flags & F_ZERO)
	{
		//printf("1\n");
		nb_str = adjust_int(nb_str, options->field_width, 1);
		//printf("B\n");
		padded_print(nb_str, options);
	}
    else if (options->precision <= len)
	{
		//printf("2\n");
		padded_print(nb_str, options);
	}
    else
	{
		//printf("5\n");
		nb_str = adjust_int(nb_str, options->precision, 0);
		padded_print(nb_str, options);
	}
	free(nb_str);
}

void    handle_str(t_options *options, va_list *list)
{
    char    *str;
    char    *substr;

    str = va_arg(*list, char *);
    if (options->len_mod && !ft_strncmp(options->len_mod, "l", 1))
        ft_putchar('?');
    else
    {
        if (options->precision < 0 || options->precision > ft_strlen(str))
			padded_print(str, options);
        else
		{
			substr = ft_strsub(str, 0, options->precision);
			padded_print(substr, options);
			free(substr);
		}
    }
}

void    handle_char(t_options *options, va_list *list)
{
	char    c;
	char	*str;

	c = va_arg(*list, int);
	str = ft_strnew(1);
	if (!str)
		handle_error();
	str[0] = c;
	str[1] = '\0';
    if (options->len_mod && !ft_strncmp(options->len_mod, "l", 1))
        ft_putchar('?');
    else
	    padded_print(str, options);
	free(str);
}

void    handle_percentage(t_options *options, va_list *list)
{
    (void)options;

	ft_putchar('%');
}

void    dispatch(t_options *options, va_list *list)
{
    handle_arg_type2    *array[11];

    array[CS_D] = &handle_int;
    array[CS_I] = &handle_int;
    array[CS_C] = &handle_char;
    array[CS_S] = &handle_str;
    array[CS_PERCENTAGE] = &handle_percentage;

    (array[options->conv_spec])(options, list);
}


	/*int	arg_nb;
	char *arg_nb_str;
	size_t  arg_nb_len;

	arg_nb = ft_atoi(ptr);
	arg_nb_str = ft_itoa(arg_nb);
    arg_nb_len = ft_strlen(arg_nb_str);
    if (*(ptr + arg_nb_len) != '$')
        return ;
    //what is is negative?
    if (ft_atoi(ptr) < 0)
        exit(1);
    if (arg_nb == 0)
    {
        options->arg_nb = 0;
        options->chars_to_skip = 0;
        return ;
    }
	options->arg_nb = arg_nb;
	options->chars_to_skip = arg_nb_len + 1;*/
