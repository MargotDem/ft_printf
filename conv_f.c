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

size_t	handle_decimals(long double *nb, char **nb_str, int precision, \
	size_t len)
{
	int				i;
	int				decimal;
	size_t			total_len;
	char			*tmp;

	tmp = handle_str_malloc(ft_strnew(len + precision + 1));
	if (!tmp)
		handle_error();
	ft_strcpy(tmp, (*nb_str));
	free((*nb_str));
	(*nb_str) = tmp;
	(*nb_str)[len] = '.';
	i = 0;
	while (i < precision)
	{
		(*nb) = ((*nb) - (long double)(long long int)(*nb)) * (long double)10;
		decimal = (long long int)((*nb));
		(*nb_str)[len + i + 1] = ft_abs_ll(decimal) + '0';
		i++;
	}
	total_len = len + precision + 1;
	return (total_len);
}

int	set_nb_str(long double nb, char **nb_str, t_options *options, \
	size_t *char_count)
{
	long long int	main;

	if (handle_isinf(nb, options, char_count))
		return (1);
	if (handle_isnan(nb, options, char_count))
		return (1);
	main = (long long int)nb;
	*nb_str = handle_str_malloc(ft_ll_itoa(main));
	return (0);
}

int	handle_negzero(long double nb, char **nb_str)
{
	int	is_negzero;

	is_negzero = 0;
	if (nb == 0 && 1 / nb < 0)
		is_negzero = 1;
	if ((nb < 0 && nb > -1) || (is_negzero))
		*nb_str = handle_str_malloc(ft_strjoin_replace("-", *nb_str, 0));
	return (is_negzero);
}

void	handle_float(t_options *options, long double nb, \
	long double original_nb, size_t *char_count)
{
	int		precision;
	char	*nb_str;
	size_t	total_len;
	int		is_negzero;

	precision = options->precision;
	if (precision == -1)
		precision = 6;
	if (set_nb_str(nb, &nb_str, options, char_count))
		return ;
	is_negzero = handle_negzero(nb, &nb_str);
	total_len = ft_strlen(nb_str);
	if (precision != 0)
		total_len = handle_decimals(&nb, &nb_str, precision, total_len);
	else if (options->flags & F_HASHTAG)
	{
		nb_str = handle_str_malloc(ft_strjoin_replace(nb_str, ".", 1));
		total_len++;
	}
	nb_str = round_float(nb_str, \
		ft_abs_float((nb - (long long int)nb) * 10), total_len, nb);
	nb_str = handle_flags_f(options, nb_str, original_nb, is_negzero);
	padded_print(nb_str, options, char_count);
}

void	handle_f(t_options *options, va_list *list, size_t *char_count)
{
	long double		nb;

	if (options->len_mod && *options->len_mod == 'L')
		nb = va_arg(*list, long double);
	else
		nb = va_arg(*list, double);
	handle_float(options, nb, nb, char_count);
}
