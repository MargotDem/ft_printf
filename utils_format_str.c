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

char	*make_new_str(char *nb_str, char *tmp, char sign, int zeroes)
{
	char	*tmp_ptr;
	char	*nb_str_ptr;

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
	return (tmp);
}

char	*adjust_str(char *nb_str, size_t total_len, int is_field_width, \
	t_options *options)
{
	char	*tmp;
	size_t	len;
	int		zeroes;
	char	sign;

	len = ft_strlen(nb_str);
	zeroes = total_len - len;
	if (zeroes < 0)
		return (nb_str);
	if (*nb_str == '-' || *nb_str == '+')
		sign = *nb_str;
	else
		sign = 0;
	if (sign && !(is_field_width))
		zeroes++;
	if (zeroes > 0 && options->no_sign && options->flags & F_SPACE \
		&& options->precision == -1)
		zeroes--;
	tmp = handle_str_malloc(ft_strnew(zeroes + len));
	nb_str = make_new_str(nb_str, tmp, sign, zeroes);
	return (nb_str);
}

char	*handle_hashtag_x(t_options *options, char *nb_str, \
	char *original_str, size_t len)
{
	char	*tmp;

	if (options->flags & F_HASHTAG \
		&& (options->conv_spec == CS_X || options->conv_spec == CS_XX) \
		&& *original_str != '\0' && *original_str != '0')
	{
		if (options->flags & F_ZERO && options->precision == -1 \
			&& options->field_width > len)
		{
			tmp = ft_strdup(nb_str);
			ft_memmove(tmp, "0X", 2);
		}
		else
			tmp = ft_strjoin("0X", nb_str);
		if (options->conv_spec == CS_X)
				tmp[1] = 'x';
		free(nb_str);
		nb_str = tmp;
	}
	return (nb_str);
}

void	print_out_nb_str(t_options *options, size_t *char_count, \
	size_t len, char *nb_str)
{
	char	*tmp;
	char	*original_str;

	if (options->precision == 0 && !(ft_strcmp(nb_str, "0")) \
		&& !(options->conv_spec == CS_O && options->flags & F_HASHTAG))
	{
		tmp = ft_strnew(0);
		free(nb_str);
		nb_str = tmp;
	}
	original_str = ft_strdup(nb_str);
	if (*nb_str != '+' && *nb_str != '-')
		options->no_sign = 1;
	if (options->precision == -1 && options->flags & F_ZERO)
		nb_str = adjust_str(nb_str, options->field_width, 1, options);
	else if (options->precision > -1)
		nb_str = adjust_str(nb_str, options->precision, 0, options);
	if (options->no_sign && options->flags & F_SPACE)
		nb_str = ft_strjoin_replace(" ", nb_str, 0);
	nb_str = handle_hashtag_x(options, nb_str, original_str, len);
	padded_print(nb_str, options, char_count);
	free(original_str);
}
