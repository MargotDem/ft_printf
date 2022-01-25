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

void	padded_print(char *str, t_options *options, size_t *char_count)
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
		(*char_count)++;
		padding--;
	}
	if (!(options->flags & F_MINUS))
		ft_putstr(str);
	(*char_count) += len;
}

void    handle_int(t_options *options, va_list *list, size_t *char_count)
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
		padded_print(nb_str, options, char_count);
	}
    else if (options->precision <= len)
	{
		//printf("2\n");
		padded_print(nb_str, options, char_count);
	}
    else
	{
		//printf("5\n");
		nb_str = adjust_int(nb_str, options->precision, 0);
		padded_print(nb_str, options, char_count);
	}
	free(nb_str);
}

void    handle_str(t_options *options, va_list *list, size_t *char_count)
{
    char    *str;
    char    *substr;

    str = va_arg(*list, char *);
    if (options->len_mod && !ft_strncmp(options->len_mod, "l", 1))
        ft_putchar('?');
    else
    {
        if (options->precision < 0 || options->precision > ft_strlen(str))
			padded_print(str, options, char_count);
        else
		{
			substr = ft_strsub(str, 0, options->precision);
			padded_print(substr, options, char_count);
			free(substr);
		}
    }
}

void    handle_char(t_options *options, va_list *list, size_t *char_count)
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
	    padded_print(str, options, char_count);
	free(str);
}

void    handle_percentage(t_options *options, va_list *list, size_t *char_count)
{
    (void)list;

	padded_print("%", options, char_count);
}
