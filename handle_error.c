/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:45:08 by mde-maul          #+#    #+#             */
/*   Updated: 2022/01/25 15:45:10 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_error(void)
{
	write(2, "error\n", 6);
	exit(1);
}

char	*handle_str_malloc(char *str)
{
	return ((char *)ft_handle_malloc((void *)str, &handle_error));
}
