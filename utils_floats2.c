/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_floats2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:56:02 by mde-maul          #+#    #+#             */
/*   Updated: 2022/03/27 15:56:04 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_flags_f(t_options *options, char *nb_str, \
	long double original_nb, int is_negzero)
{
	if (options->flags & F_PLUS && original_nb >= (double)0 && !is_negzero)
		nb_str = handle_str_malloc(ft_strjoin_replace("+", nb_str, 0));
	if (*nb_str != '+' && *nb_str != '-')
		options->no_sign = 1;
	if (options->flags & F_ZERO)
		nb_str = adjust_str(nb_str, options->field_width, 1, options);
	if (options->no_sign && options->flags & F_SPACE)
		nb_str = handle_str_malloc(ft_strjoin_replace(" ", nb_str, 0));
	return (nb_str);
}
