/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:11:43 by mde-maul          #+#    #+#             */
/*   Updated: 2022/03/26 16:11:46 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_d(t_options *options, va_list *list, size_t *char_count)
{
	char			*nb_str;
	char			*tmp;
	size_t			len;
	long long int	nb;

	set_nb(options, list, &nb);
	nb_str = handle_str_malloc(ft_ll_itoa(nb));
	len = ft_strlen(nb_str);
	if (nb < 0)
		len--;
	else
	{
		if (options->flags & F_PLUS)
			nb_str = handle_str_malloc(ft_strjoin_replace("+", nb_str, 0));
	}
	print_out_nb_str(options, char_count, len, nb_str);
}
