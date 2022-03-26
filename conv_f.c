/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:28:36 by mde-maul          #+#    #+#             */
/*   Updated: 2022/03/21 19:28:38 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_flags(t_options *options, char *nb_str, long double nb_original, int is_negzero)
{
	if (options->flags & F_PLUS && nb_original >= (double)0 && !is_negzero)
		nb_str = ft_strjoin_replace("+", nb_str, 0);
	if (*nb_str != '+' && *nb_str != '-')
		options->no_sign = 1;
	if (options->flags & F_ZERO)
		nb_str = adjust_int(nb_str, options->field_width, 1, options);
	if (options->no_sign && options->flags & F_SPACE)
		nb_str = ft_strjoin_replace(" ", nb_str, 0);
	return (nb_str);
}

void	handle_float(t_options *options, long double nb, size_t *char_count)
{
	long double		nb_original;
	long long int	main;
	int				decimal;
	int				precision;
	int				i;
	char			*nb_str;
	char			*tmp;
	size_t			len;
	size_t			total_len;
	long double		last_digit;
	int				is_negzero;

	nb_original = nb;
	precision = options->precision;
	main = (long long int)nb;
	is_negzero = 0;
	if (nb == 0 && 1 / nb < 0)
		is_negzero = 1;
	if (handle_isinf(nb, options, char_count))
		return ;
	if (handle_isnan(nb, options, char_count))
		return ;
	if (precision == -1)
		precision = 6;
	i = 0;
	nb_str = ft_ll_itoa(main);
	if ((nb < 0 && nb > -1) || (is_negzero))
		nb_str = ft_strjoin_replace("-", nb_str, 0);
	len = ft_strlen(nb_str);
	total_len = len;
	if (precision != 0)
	{
		tmp = ft_strnew(len + precision + 1);
		ft_strcpy(tmp, nb_str);
		free(nb_str);
		nb_str = tmp;
		nb_str[len] = '.';
		while (i < precision)
		{
			nb = (nb - (long double)(long long int)nb) * (long double)10.00000000000000000000000;
			decimal = (long long int)(nb);
			nb_str[len + i + 1] = ft_ll_itoa(ft_abs_ll(decimal))[0];
			i++;
		}
		total_len = len + precision + 1;
	}
	else if (options->flags & F_HASHTAG)
	{
		nb_str = ft_strjoin_replace(nb_str, ".", 1);
		total_len++;
	}
	last_digit = ft_abs_float((nb - (long long int)nb) * 10);
	nb_str = round_float(nb_str, last_digit, total_len, nb);
	nb_str = handle_flags(options, nb_str, nb_original, is_negzero);
	padded_print(nb_str, options, char_count);
}

void	handle_f(t_options *options, va_list *list, size_t *char_count)
{
	long double		nb;

	if (options->len_mod && *options->len_mod == 'L')
		nb = va_arg(*list, long double);
	else
		nb = va_arg(*list, double);
	handle_float(options, nb, char_count);
}
