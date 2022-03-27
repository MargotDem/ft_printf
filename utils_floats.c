/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_floats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:03:06 by mde-maul          #+#    #+#             */
/*   Updated: 2022/03/25 19:03:09 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_isnan(long double nb, t_options *options, size_t *char_count)
{
	char	*nb_str;

	if (ft_isnan(nb))
	{
		nb_str = ft_strdup("nan");
		padded_print(nb_str, options, char_count);
		return (1);
	}
	return (0);
}

int	handle_isinf(long double nb, t_options *options, size_t *char_count)
{
	char	*nb_str;

	if (nb == 1.0 / 0 || nb == -1.0 / 0)
	{
		if (nb == 1.0 / 0)
		{
			if (options->flags & F_PLUS)
				nb_str = ft_strdup("+inf");
			else if (options->flags & F_SPACE)
				nb_str = ft_strdup(" inf");
			else
				nb_str = ft_strdup("inf");
		}
		else
			nb_str = ft_strdup("-inf");
		padded_print(nb_str, options, char_count);
		return (1);
	}
	return (0);
}

char	*round_main(char *nb_str, long long int main, size_t len, \
	int is_positive)
{
	char			*tmp;
	long long int	original_main;
	char			*main_str;
	char			*original_main_str;

	original_main = main;
	main++;
	if (!is_positive)
		main -= 2;
	main_str = handle_str_malloc(ft_ll_itoa(main));
	original_main_str = handle_str_malloc(ft_ll_itoa(original_main));
	if (ft_strlen(main_str) <= ft_strlen(original_main_str) \
		|| (original_main == 0 && !is_positive))
		ft_memmove(nb_str, main_str, ft_strlen(main_str));
	else
	{
		tmp = ft_strnew(len + 1);
		ft_strcpy(tmp + 1, nb_str);
		free(nb_str);
		nb_str = tmp;
		ft_memmove(nb_str, main_str, ft_strlen(main_str));
	}
	free(main_str);
	free(original_main_str);
	return (nb_str);
}

void	round_decimals(char *nb_str, size_t len, size_t *second_to_last)
{
	size_t	place;

	place = len - 1;
	while (nb_str[place] != '.')
	{
		*second_to_last = ((nb_str[place]) - 48 + 1) % 10;
		nb_str[place] = *second_to_last + 48;
		if (*second_to_last != 0)
			break ;
		place --;
	}
}

char	*round_float(char *nb_str, long double last_digit, size_t len, \
	long double test_stl)
{
	size_t			second_to_last;
	long long int	main;
	char			*main_str;
	int				is_positive;

	main = ft_ll_atoi(nb_str);
	is_positive = 0;
	if (test_stl > 0)
		is_positive = 1;
	if (last_digit > 5 || (last_digit == 5 && ft_abs((int)test_stl % 2) == 1))
	{
		main_str = handle_str_malloc(ft_ll_itoa(main));
		if (ft_strlen(main_str) == len || ft_strlen(main_str) == len - 1)
		{
			nb_str = round_main(nb_str, main, len, is_positive);
			free(main_str);
		}
		else
		{
			round_decimals(nb_str, len, &second_to_last);
			if (second_to_last == 0)
				nb_str = round_main(nb_str, main, len, is_positive);
		}
	}
	return (nb_str);
}
