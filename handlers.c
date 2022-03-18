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

/*
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
*/

char	*adjust_int(char *nb_str, size_t precision, int field_width)
{
	char	*tmp;
	char	*tmp_ptr;
	char	*nb_str_ptr;
	size_t   len;
	int  zeroes;
	char	sign;

	len = ft_strlen(nb_str);
	zeroes = precision - len;
	if (zeroes < 0)
		return (nb_str);
	if (*nb_str == '-' || *nb_str == '+')
		sign = *nb_str;
	else
		sign = 0;
	if (sign && !(field_width))
		zeroes++;
	tmp = (char *)malloc(zeroes + len + 1);
	tmp_ptr = tmp;
	nb_str_ptr = nb_str;
	if (sign)
	{
		ft_memset(tmp_ptr, sign, 1);
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

void	print_out_nb_str(t_options *options, size_t *char_count, size_t len, char *nb_str)
{
	char	*tmp;
	char	*original_str;
	int		no_sign;

	original_str = ft_strdup(nb_str);
	// "if a signed conversion results in no characters" what does that even mean
	if (*nb_str != '+' && *nb_str != '-')
		no_sign = 1;
	if (options->precision == -1 && options->flags & F_ZERO)
		nb_str = adjust_int(nb_str, options->field_width, 1);
    else
		nb_str = adjust_int(nb_str, options->precision, 0);
	//so if if (options->precision <= len) we dont adjust int
	if (no_sign && options->flags & F_SPACE && !(options->flags & F_PLUS) && !(options->flags & F_MINUS))
	{
		tmp = ft_strjoin(" ", nb_str);
		free(nb_str);
		nb_str = tmp;
	}
	if (options->flags & F_HASHTAG)
	{
		if (options->conv_spec == CS_X || options->conv_spec == CS_XX)
		{
			if (*original_str != '0')
			{
				if (options->conv_spec == CS_X)
					tmp = ft_strjoin("0x", nb_str);
				else
					tmp = ft_strjoin("0X", nb_str);
				free(nb_str);
				nb_str = tmp;
			}
		}
		else if (options->conv_spec & CS_O)
		{
			//printf("hehe coucou\n");
		}
	}
	padded_print(nb_str, options, char_count);
	free(original_str);
}

void	set_nb(t_options *options, va_list *list, long long int *nb)
{
	if (options->len_mod && !ft_strncmp(options->len_mod, "ll", 2))
		*nb = va_arg(*list, long long int);
	else if (options->len_mod && !ft_strncmp(options->len_mod, "l", 1))
		*nb = va_arg(*list, long int);
	else if (options->len_mod && !ft_strncmp(options->len_mod, "hh", 2))
		*nb = (char)va_arg(*list, int);
	else if (options->len_mod && !ft_strncmp(options->len_mod, "h", 1))
		*nb = (short int)va_arg(*list, int);
	else
		*nb = va_arg(*list, int);
}

void	set_nb_unsigned(t_options *options, va_list *list, unsigned long long int *nb)
{
	if (options->len_mod && !ft_strncmp(options->len_mod, "ll", 2))
		*nb = va_arg(*list, unsigned long long int);
	else if (options->len_mod && !ft_strncmp(options->len_mod, "l", 1))
		*nb = va_arg(*list, unsigned long int);
	else if (options->len_mod && !ft_strncmp(options->len_mod, "hh", 2))
		*nb = (unsigned char)va_arg(*list, unsigned int);
	else if (options->len_mod && !ft_strncmp(options->len_mod, "h", 1))
		*nb = (unsigned short int)va_arg(*list, unsigned int);
	else
		*nb = va_arg(*list, unsigned int);
}

void	handle_hex(t_options *options, va_list *list, size_t *char_count, size_t is_X)
{
	char					*nb_str;
	unsigned long long int	nb;
	size_t					i;
	size_t					len;

	set_nb_unsigned(options, list, &nb);
	nb_str = ft_ull_itoa_base(nb, 16);
	len = ft_strlen(nb_str);
	i = 0;
	if (is_X)
	{
		while(nb_str[i])
		{
			nb_str[i] = ft_toupper(nb_str[i]);
			i++;
		}
	}
	print_out_nb_str(options, char_count, len, nb_str);
	//free(nb_str);
	//ft_memdel((void *)nb_str);
}

void	handle_hex_x(t_options *options, va_list *list, size_t *char_count)
{
	handle_hex(options, list, char_count, 0);
}

void	handle_hex_X(t_options *options, va_list *list, size_t *char_count)
{
	handle_hex(options, list, char_count, 1);
}

void	handle_oct(t_options *options, va_list *list, size_t *char_count)
{
	char					*nb_str;
	unsigned long long int	nb;
	size_t					len;

	set_nb_unsigned(options, list, &nb);
	nb_str = ft_ull_itoa_base(nb, 8);
	len = ft_strlen(nb_str);
	print_out_nb_str(options, char_count, len, nb_str);
	//free(nb_str);
	//ft_memdel((void *)nb_str);
}

void	handle_decimal(t_options *options, va_list *list, size_t *char_count)
{
	char					*nb_str;
	unsigned long long int	nb;
	size_t					len;

	set_nb_unsigned(options, list, &nb);
	nb_str = ft_ull_itoa_base(nb, 10);
	len = ft_strlen(nb_str);
	print_out_nb_str(options, char_count, len, nb_str);
	//free(nb_str);
	//ft_memdel((void *)nb_str);
}

void	handle_d(t_options *options, va_list *list, size_t *char_count)
{
	char			*nb_str;
	char			*tmp;
	size_t			len;
	long long int	nb;

	set_nb(options, list, &nb);
    nb_str = ft_ll_itoa(nb);
	len = ft_strlen(nb_str);
	if (nb < 0)
		len--;
	else
	{
		if (options->flags & F_PLUS)
		{
			tmp = ft_strjoin("+", nb_str);
			free(nb_str);
			nb_str = tmp;
		}
	}
	print_out_nb_str(options, char_count, len, nb_str);
	//free(nb_str);
	//ft_memdel((void *)nb_str);
}

void    handle_str(t_options *options, va_list *list, size_t *char_count)
{
    char    *str;
    char    *substr;

    str = va_arg(*list, char *);
	if (options->precision < 0 || options->precision > ft_strlen(str))
		padded_print(str, options, char_count);
	else
	{
		substr = ft_strsub(str, 0, options->precision);
		padded_print(substr, options, char_count);
		free(substr);
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
	padded_print(str, options, char_count);
	free(str);
}

void    handle_percentage(t_options *options, va_list *list, size_t *char_count)
{
    (void)list;

	padded_print("%", options, char_count);
}

/*
42filechecker

70 78 are undefined behavior


*/