/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:47:41 by mde-maul          #+#    #+#             */
/*   Updated: 2022/01/18 14:47:43 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_dispatcher(handle_arg_type **dispatcher)
{
	dispatcher[CS_D] = &handle_int;
	dispatcher[CS_I] = &handle_int;
	dispatcher[CS_C] = &handle_char;
	dispatcher[CS_S] = &handle_str;
	dispatcher[CS_X] = &handle_hex;
	dispatcher[CS_PERCENTAGE] = &handle_percentage;
}

int	ft_printf(const char *str, ...)
{
	char		*ptr;
	size_t		ret;
	va_list		list;
	size_t		char_count;
	handle_arg_type    *dispatcher[11];

	va_start(list, str);
	initialize_dispatcher(dispatcher);
	char_count = 0;
	ptr = ft_strchr(str, (int)'%');
	while (ptr)
	{
		write(1, str, (int)(ptr - str));
		char_count += (size_t)(ptr - str);
		ret = parse_conv_specification(ptr + 1, &list, &char_count, dispatcher);
		str = ptr + 1 + ret;
		ptr = ft_strchr(str, (int)'%');
	}
	write(1, str, ft_strlen(str));
	char_count += ft_strlen(str);
	return (char_count);
}
