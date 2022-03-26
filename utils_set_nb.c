/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:45:38 by mde-maul          #+#    #+#             */
/*   Updated: 2022/01/25 15:45:40 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_nb(t_options *options, va_list *list, long long int *nb)
{
	if (options->len_mod && !ft_strncmp(options->len_mod, "ll", 2))
		*nb = va_arg(*list, long long int);
	else if (options->len_mod && !ft_strncmp(options->len_mod, "l", 1))
		*nb = va_arg(*list, long int);
	else if (options->len_mod && !ft_strncmp(options->len_mod, "hh", 2))
		*nb = (char)va_arg(*list, int);
	else if (options->len_mod && !ft_strncmp(options->len_mod, "h", 1))
		*nb = (short int)va_arg(*list, int);
	else
		*nb = va_arg(*list, int);
}

void	set_nb_unsigned(t_options *options, va_list *list, \
	unsigned long long int *nb)
{
	if (options->len_mod && !ft_strncmp(options->len_mod, "ll", 2))
		*nb = va_arg(*list, unsigned long long int);
	else if (options->len_mod && !ft_strncmp(options->len_mod, "l", 1))
		*nb = va_arg(*list, unsigned long int);
	else if (options->len_mod && !ft_strncmp(options->len_mod, "hh", 2))
		*nb = (unsigned char)va_arg(*list, unsigned int);
	else if (options->len_mod && !ft_strncmp(options->len_mod, "h", 1))
		*nb = (unsigned short int)va_arg(*list, unsigned int);
	else
		*nb = va_arg(*list, unsigned int);
}
