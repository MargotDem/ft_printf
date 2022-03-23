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

char	*round_main(char *nb_str, int main, size_t len)
{
	char	*tmp;

	main++;
	if (ft_strlen(ft_itoa(main)) > ft_strlen(ft_itoa(main - 1)))
	{
		tmp = ft_strnew(len + 1);
		ft_strcpy(tmp + 1, nb_str);
		free(nb_str);
		nb_str = tmp;
		ft_memmove(nb_str, ft_itoa(main), ft_strlen(ft_itoa(main)));
	}
	else
		ft_memmove(nb_str, ft_itoa(main), ft_strlen(ft_itoa(main)));
	return (nb_str);
}

char	*round_float(char *nb_str, long double last_digit, size_t len)
{
	size_t	second_to_last;
	size_t	place;
	int		main;

	//printf("here, last digit   is %.10Lf\n", last_digit);
	if (last_digit > 5.000000000000000)
	{
		main = ft_atoi(nb_str);
		// just a round float or a round float plus dot
		if (ft_strlen(ft_itoa(main)) == len || ft_strlen(ft_itoa(main)) == len - 1)
			nb_str = round_main(nb_str, main, len);
		else
		{
			place = len - 1;
			while (nb_str[place] != '.')
			{
				second_to_last = ((nb_str[place]) - 48 + 1) % 10;
				nb_str[place] = second_to_last + 48;
				if (second_to_last != 0)
					break;
				place --;
			}
			if (second_to_last == 0)
				nb_str = round_main(nb_str, main, len);
		}
	}
	return (nb_str);
}

char	*add_dot(char *nb_str)
{
	char	*tmp;

	tmp = ft_strjoin(nb_str, ".");
	free(nb_str);
	nb_str = tmp;
	return (nb_str);
}

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
	size_t	total_len;
	double	last_digit; 

	nb = va_arg(*list, double);

	precision = options->precision;
	main = (int)nb;
	// bankers rounding
	if (precision == 0 && nb - main - 0.500000000000000 == 0.000000000000000)
	{
		if (main % 2 == 0)
			nb_str = ft_itoa(main);
		else
			nb_str = ft_itoa(main + 1);
		if (options->flags & F_HASHTAG)
			nb_str = add_dot(nb_str);
	}
	else
	{
		if (precision == -1)
			precision = 6;
		i = 0;
		nb_str = ft_itoa(main);
		len = ft_strlen(nb_str);
		total_len = len;
		if (precision != 0)
		{
			tmp = ft_strnew(len + precision + 1);
			ft_strcpy(tmp, nb_str);
			free(nb_str);
			nb_str = tmp;
			nb_str[len] = '.';
			while (i < precision)
			{
				nb = (nb - (int)nb) * 10;
				decimal = (int)(nb);
				nb_str[len + i + 1] = ft_itoa(ft_abs(decimal))[0];
				i++;
			}
			total_len = len + precision + 1;
		}
		else if (options->flags & F_HASHTAG)
		{
			nb_str = add_dot(nb_str);
			total_len++;
		}
		nb = (nb - (int)nb) * 10;
		//printf("here, float nb  is %.20f\n", nb);
		//printf("here, int nb  is %d\n", (int)nb);

		last_digit = ft_abs_float(nb);
		//printf("first here, last digit is %zu\n", last_digit);
		nb_str = round_float(nb_str, last_digit, total_len);
	}
	//deja vu in handlersm, extract
	if (options->flags & F_PLUS && nb > 0)
	{
		tmp = ft_strjoin("+", nb_str);
		free(nb_str);
		nb_str = tmp;
	}
	if (*nb_str != '+' && *nb_str != '-')
		options->no_sign = 1;
	if (options->flags & F_ZERO) // how bout the precision tho
		nb_str = adjust_int(nb_str, options->field_width, 1, options);
	if (options->no_sign && options->flags & F_SPACE)
	{
		tmp = ft_strjoin(" ", nb_str);
		free(nb_str);
		nb_str = tmp;
	}
	padded_print(nb_str, options, char_count);
	free(nb_str);
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
