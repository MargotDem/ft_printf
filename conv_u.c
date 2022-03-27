/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:14:42 by mde-maul          #+#    #+#             */
/*   Updated: 2022/03/26 16:14:44 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_decimal(t_options *options, va_list *list, size_t *char_count)
{
	char					*nb_str;
	unsigned long long int	nb;
	size_t					len;

	set_nb_unsigned(options, list, &nb);
	nb_str = handle_str_malloc(ft_ull_itoa_base(nb, 10));
	len = ft_strlen(nb_str);
	print_out_nb_str(options, char_count, len, nb_str);
}
