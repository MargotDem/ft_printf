/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:30:18 by mde-maul          #+#    #+#             */
/*   Updated: 2022/03/23 11:30:20 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_null_char(t_options *options, va_list *list, size_t *char_count)
{
	int		padding;

	padding = options->field_width - 1;
	if (options->flags & F_MINUS)
		ft_putchar('\0');
	while (padding > 0)
	{
		ft_putchar(' ');
		(*char_count)++;
		padding--;
	}
	if (!(options->flags & F_MINUS))
		ft_putchar('\0');
	(*char_count)++;
}

void	handle_char(t_options *options, va_list *list, size_t *char_count)
{
	char	c;
	char	*str;

	c = va_arg(*list, int);
	if (c)
	{
		str = ft_strnew(1);
		if (!str)
			handle_error();
		str[0] = c;
		str[1] = '\0';
		padded_print(str, options, char_count);
		free(str);
	}
	else
		handle_null_char(options, list, char_count);
}
