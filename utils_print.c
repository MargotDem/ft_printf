/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:18:00 by mde-maul          #+#    #+#             */
/*   Updated: 2022/03/26 16:18:02 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	padded_print(char *str, t_options *options, size_t *char_count)
{
	size_t	len;
	size_t	total_len;
	int		padding;

	len = ft_strlen(str);
	total_len = options->field_width;
	padding = total_len - len;
	if (options->flags & F_MINUS)
		ft_putstr(str);
	while (padding > 0)
	{
		ft_putchar(' ');
		(*char_count)++;
		padding--;
	}
	if (!(options->flags & F_MINUS))
		ft_putstr(str);
	(*char_count) += len;
	free(str);
}
