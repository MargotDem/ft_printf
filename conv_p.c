/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:12:04 by mde-maul          #+#    #+#             */
/*   Updated: 2022/03/23 12:12:05 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_p(t_options *options, va_list *list, size_t *char_count)
{
	char					*nb_str;
	unsigned long long int	nb;

	(void)list;
	nb = va_arg(*list, unsigned long long int);
	nb_str = ft_ull_itoa_base(nb, 16);
	nb_str = ft_strjoin("0x", nb_str);
	padded_print(nb_str, options, char_count);
	free(nb_str);
}