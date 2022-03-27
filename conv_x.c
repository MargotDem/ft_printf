/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:48:06 by mde-maul          #+#    #+#             */
/*   Updated: 2022/03/26 15:48:08 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_hex(t_options *options, va_list *list, size_t *char_count, \
	size_t is_X)
{
	char					*nb_str;
	unsigned long long int	nb;
	size_t					i;
	size_t					len;

	set_nb_unsigned(options, list, &nb);
	nb_str = handle_str_malloc(ft_ull_itoa_base(nb, 16));
	len = ft_strlen(nb_str);
	i = 0;
	if (is_X)
	{
		while (nb_str[i])
		{
			nb_str[i] = ft_toupper(nb_str[i]);
			i++;
		}
	}
	print_out_nb_str(options, char_count, len, nb_str);
}

void	handle_hex_x(t_options *options, va_list *list, size_t *char_count)
{
	handle_hex(options, list, char_count, 0);
}

void	handle_hex_xx(t_options *options, va_list *list, size_t *char_count)
{
	handle_hex(options, list, char_count, 1);
}
