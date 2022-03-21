/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:28:36 by mde-maul          #+#    #+#             */
/*   Updated: 2022/03/21 19:28:38 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_float(t_options *options, va_list *list, size_t *char_count)
{
	double	nb;
	int		main;
	int		decimal;
	int		precision;
	int		i;
	char	*nb_str;
	char	*tmp;
	size_t	len;

	nb = va_arg(*list, double);
	main = (int)nb;
	precision = options->precision;
	if (precision == -1)
		precision = 6;
	i = 0;
	nb_str = ft_itoa(main);
	if (precision != 0)
	{
		len = ft_strlen(nb_str);
		tmp = ft_strnew(len + precision + 1);
		ft_strcpy(tmp, nb_str);
		nb_str = tmp;
		nb_str[len] = '.';
		while (i < precision)
		{
			nb = (nb - (int)nb) * 10;
			decimal = (int)(nb);
			nb_str[len + i + 1] = ft_itoa(decimal)[0];
			i++;
		}
	}
	padded_print(nb_str, options, char_count);
	free(nb_str);
	//padded_print(ft_itoa(main), options, char_count);
}

void	handle_ld_float(t_options *options, va_list *list, size_t *char_count)
{
	long double	nb;

	nb = va_arg(*list, long double);
	padded_print("hey", options, char_count);
}

void    handle_f(t_options *options, va_list *list, size_t *char_count)
{
    (void)list;

	if (options->len_mod && *options->len_mod == 'L')
	{
		//printf("long double\n");
		handle_ld_float(options, list, char_count);
	}
	else
	{
		//printf("simple float\n");
		handle_float(options, list, char_count);
	}
}
