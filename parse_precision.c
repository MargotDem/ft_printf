/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:53:27 by mde-maul          #+#    #+#             */
/*   Updated: 2022/03/26 17:53:29 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_precision(t_options *options, char *ptr)
{
	int		precision;
	char	*precision_str;

	if (ft_atoi(ptr + 1) < 0)
		handle_error();
	precision = (size_t)ft_atoi(ptr + 1);
	if (precision == 0)
	{
		options->precision = 0;
		options->chars_to_skip += 1;
		if (*(ptr + 1) == '0')
			options->chars_to_skip += 1;
		return ;
	}
	precision_str = handle_str_malloc(ft_itoa(precision));
	options->precision = precision;
	options->chars_to_skip += ft_strlen(precision_str) + 1;
}

void	handle_precision(char *ptr, t_options *options, va_list *list)
{
	int		precision;

	if (*ptr != '.')
		return ;
	if (*(ptr + 1) == '*')
	{
		precision = va_arg(*list, int);
		options->chars_to_skip += 2;
		if (precision >= 0)
			options->precision = precision;
	}
	else
		set_precision(options, ptr);
}
