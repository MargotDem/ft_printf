/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:08:17 by mde-maul          #+#    #+#             */
/*   Updated: 2022/03/26 16:08:21 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_str(t_options *options, va_list *list, size_t *char_count)
{
	char	*str;
	char	*substr;

	str = va_arg(*list, char *);
	if (!str)
	{
		ft_putstr("(null)");
		*char_count += 6;
	}
	else
	{
		if (options->precision < 0 || options->precision > ft_strlen(str))
		{
			substr = ft_strdup(str);
			padded_print(substr, options, char_count);
		}
		else
		{
			substr = ft_strsub(str, 0, options->precision);
			padded_print(substr, options, char_count);
		}
	}
}
