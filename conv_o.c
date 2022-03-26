/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:55:38 by mde-maul          #+#    #+#             */
/*   Updated: 2022/03/26 15:55:40 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_oct(t_options *options, va_list *list, size_t *char_count)
{
	char					*nb_str;
	unsigned long long int	nb;
	size_t					len;

	set_nb_unsigned(options, list, &nb);
	nb_str = ft_ull_itoa_base(nb, 8);
	len = ft_strlen(nb_str);
	if (options->flags & F_HASHTAG && \
		options->precision <= (int)len && nb != 0 && \
		!(options->flags & F_ZERO && options->field_width > len && \
			options->precision == -1))
		options->precision = (int)len + 1;
	print_out_nb_str(options, char_count, len, nb_str);
}
