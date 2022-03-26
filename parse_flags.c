/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:36:29 by mde-maul          #+#    #+#             */
/*   Updated: 2022/03/26 17:36:32 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_uchar	get_flag(char *ptr)
{
	if (*ptr == '#')
		return (F_HASHTAG);
	else if (*ptr == '0')
		return (F_ZERO);
	else if (*ptr == '+')
		return (F_PLUS);
	else if (*ptr == '-')
		return (F_MINUS);
	else
		return (F_SPACE);
}

void	ignore_flags(t_options *options)
{
	if (options->flags & F_ZERO && options->flags & F_MINUS)
		options->flags = options->flags ^ F_ZERO;
	if (options->flags & F_SPACE && options->flags & F_PLUS)
		options->flags = options->flags ^ F_SPACE;
	if (options->flags & F_SPACE && \
		(options->conv_spec != CS_D && options->conv_spec != CS_I && \
		options->conv_spec != CS_F))
		options->flags = options->flags ^ F_SPACE;
}

void	handle_flags(char *ptr, t_options *options)
{
	options->flags = 0x00;
	while (*ptr == '#' || *ptr == '0' || *ptr == '+' || *ptr == '-' \
		|| *ptr == ' ')
	{
		options->flags = options->flags | get_flag(ptr);
		options->chars_to_skip += 1;
		ptr++;
	}
}
