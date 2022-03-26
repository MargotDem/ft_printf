/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_format_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:17:53 by mde-maul          #+#    #+#             */
/*   Updated: 2022/03/26 16:17:55 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*adjust_int(char *nb_str, size_t precision, int field_width, t_options *options)
{
	char	*tmp;
	char	*tmp_ptr;
	char	*nb_str_ptr;
	size_t   len;
	int  zeroes;
	char	sign;

	len = ft_strlen(nb_str);
	zeroes = precision - len;
	if (zeroes < 0)
		return (nb_str);
	if (*nb_str == '-' || *nb_str == '+')
		sign = *nb_str;
	else
		sign = 0;
	if (sign && !(field_width))
		zeroes++;
	if (zeroes > 0 && options->no_sign && options->flags & F_SPACE && options->precision == -1)
		zeroes--;
	tmp = ft_strnew(zeroes + len);
	if (!tmp)
		handle_error();
	tmp_ptr = tmp;
	nb_str_ptr = nb_str;
	if (sign)
	{
		*tmp_ptr = sign;
		tmp_ptr++;
		nb_str_ptr++;
	}
	ft_memset(tmp_ptr, '0', zeroes);
	ft_strcpy(tmp_ptr + zeroes, nb_str_ptr);
	free (nb_str);
	nb_str = tmp;
	return (nb_str);
}

void	print_out_nb_str(t_options *options, size_t *char_count, size_t len, char *nb_str)
{
	char	*tmp;
	char	*original_str;

	if (options->precision == 0 && !(ft_strcmp(nb_str, "0")) && !(options->conv_spec == CS_O &&options->flags & F_HASHTAG))
	{
		tmp = ft_strnew(0);
		free(nb_str);
		nb_str = tmp;
	}
	original_str = ft_strdup(nb_str);
	// no_sign. space. "if a signed conversion results in no characters" what does that even mean
	if (*nb_str != '+' && *nb_str != '-')
		options->no_sign = 1;
	if (options->precision == -1 && options->flags & F_ZERO)
		nb_str = adjust_int(nb_str, options->field_width, 1, options);
    //previously just else
	else if (options->precision > -1)
		nb_str = adjust_int(nb_str, options->precision, 0, options);
	//so if (options->precision <= len) we dont adjust int
	//isnt that repetitive?
	if (options->no_sign && options->flags & F_SPACE)
		nb_str = ft_strjoin_replace(" ", nb_str, 0);
	//does this need to be here? this is ridiculous may i add. it looks hysterical. surely there must a better way
	if (options->flags & F_HASHTAG && (options->conv_spec == CS_X || options->conv_spec == CS_XX) && *original_str != '\0')
	{
		if (*original_str != '0')
		{
			if (options->flags & F_ZERO && options->precision == -1 && options->field_width > len)
			{
				tmp = ft_strdup(nb_str);
				tmp[0] = '0';
				if (options->conv_spec == CS_X)
					tmp[1] = 'x';
				else
					tmp[1] = 'X';
			}
			else
			{
				if (options->conv_spec == CS_X)
					tmp = ft_strjoin("0x", nb_str);
				else
					tmp = ft_strjoin("0X", nb_str);
			}
			free(nb_str);
			nb_str = tmp;
		}
	}
	padded_print(nb_str, options, char_count);
	free(original_str);
}
