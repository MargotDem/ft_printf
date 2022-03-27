/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_field_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:50:56 by mde-maul          #+#    #+#             */
/*   Updated: 2022/03/26 17:50:59 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_field_width(char *ptr, t_options *options, va_list *list)
{
	int		field_width;
	char	*field_width_str;

	if (*ptr == '*')
	{
		field_width = va_arg(*list, int);
		if (field_width < 0)
		{
			field_width = -field_width;
			options->flags = options->flags | F_MINUS;
		}
		options->field_width = field_width;
		options->chars_to_skip ++;
	}
	else
	{
		field_width = (size_t)ft_atoi(ptr);
		if (field_width == 0)
			return ;
		field_width_str = handle_str_malloc(ft_itoa(field_width));
		options->field_width = field_width;
		options->chars_to_skip += ft_strlen(field_width_str);
		free(field_width_str);
	}
}
