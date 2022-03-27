/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percentage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:06:15 by mde-maul          #+#    #+#             */
/*   Updated: 2022/03/23 12:06:17 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_percentage(t_options *options, va_list *list, size_t *char_count)
{
	char	*nb_str;

	(void)list;
	nb_str = handle_str_malloc(ft_strnew(1));
	nb_str[0] = '%';
	if (options->flags & F_ZERO)
		nb_str = adjust_str(nb_str, options->field_width, 1, options);
	padded_print(nb_str, options, char_count);
}
