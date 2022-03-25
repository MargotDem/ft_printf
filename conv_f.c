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

char	*round_main(char *nb_str, long long int main, size_t len, int is_positive)
{
	char			*tmp;
	long long int	original_main;

	original_main = main;
	//printf("here, origina main   is %lld\n", original_main);
	if (is_positive)
		main++;
	else
		main--;
	//printf("here,  main   is %lld\n", main);
	
	if (ft_strlen(ft_ll_itoa(main)) <= ft_strlen(ft_ll_itoa(original_main)) || (original_main == 0 && !is_positive))
	{
				//printf("aaaa. str is %s\n", nb_str);
		ft_memmove(nb_str, ft_ll_itoa(main), ft_strlen(ft_ll_itoa(main)));
		//printf("aaaa. str is %s\n", nb_str);

	}
	else
	{
		//printf("here\n");
		tmp = ft_strnew(len + 1);
		ft_strcpy(tmp + 1, nb_str);
		free(nb_str);
		nb_str = tmp;
		ft_memmove(nb_str, ft_ll_itoa(main), ft_strlen(ft_ll_itoa(main)));

	}
	return (nb_str);
}

char	*round_float(char *nb_str, long double last_digit, size_t len, long double test_stl)
{
	size_t			second_to_last;
	size_t			place;
	long long int	main;
	int				is_positive;

	//printf("heree nbstr is %s\n", nb_str);
	//printf("here, last digit   is %.30Lf\n", last_digit);
	//printf("here, second to last digit   is %.30Lf\n", test_stl);
	//if (last_digit >= (long double)5.0000000000001)
	//printf("hey nb is %.3Lf\n", test_stl);
	//printf("hey nbstr is %s\n", nb_str);
	main = ft_ll_atoi(nb_str);
	is_positive = 0;
	if (test_stl > 0)
		is_positive = 1;
	if (last_digit > 5 || (last_digit == 5 && ft_abs((int)test_stl % 2) == 1))
	{
		//printf("main is %lld\n", main);
		// just a round float or a round float plus dot
		if (ft_strlen(ft_ll_itoa(main)) == len || ft_strlen(ft_ll_itoa(main)) == len - 1)
		{
			nb_str = round_main(nb_str, main, len, is_positive);
		}
		else
		{
			
			//printf("here\n");
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
				nb_str = round_main(nb_str, main, len, is_positive);
		}
	}
	return (nb_str);
}

int		handle_isnan(long double nb, t_options *options, size_t *char_count)
{
	char	*nb_str;

	if (ft_isnan(nb))
	{
		nb_str = "nan";
		padded_print(nb_str, options, char_count);
		return (1);
	}
	return (0);
}

int		handle_isinf(long double nb, t_options *options, size_t *char_count)
{
	char	*nb_str;

	if (nb == 1.0 / 0 || nb == -1.0 / 0)
	{
		if (nb == 1.0 / 0)
		{
			if (options->flags & F_PLUS)
				nb_str = "+inf";
			else if (options->flags & F_SPACE)
				nb_str = " inf";
			else
				nb_str = "inf";
		}
		else
			nb_str = "-inf";
		padded_print(nb_str, options, char_count);
		return (1);
	}
	return (0);
}

void	handle_float(t_options *options, long double nb, size_t *char_count)
{
	long double		nb_original;
	long long int	main;
	int				decimal;
	int				precision;
	int				i;
	char			*nb_str;
	char			*tmp;
	size_t			len;
	size_t			total_len;
	long double		last_digit;
	int				is_negzero;

	nb_original = nb;

	precision = options->precision;
	main = (long long int)nb;

	is_negzero = 0;
	if (nb == 0 && 1 / nb < 0)
		is_negzero = 1;

	//printf("hey nb is %.30Lf\n", nb);
	//printf("hey nb * 10 is %.30Lf\n", nb * (long double)10l);
	if (handle_isinf(nb, options, char_count))
		return ;
	if (handle_isnan(nb, options, char_count))
		return ;

	if (precision == -1)
		precision = 6;
	i = 0;
	nb_str = ft_ll_itoa(main);
	if ((nb < 0 && nb > -1) || (is_negzero))
	{
		//printf("here\n");
		nb_str = ft_strjoin_replace("-", nb_str, 0);
	}
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
			nb = (nb - (long double)(long long int)nb) * (long double)10.00000000000000000000000;
			//printf("HERE float nb is %.30Lf\n", nb);
			decimal = (long long int)(nb);
			nb_str[len + i + 1] = ft_ll_itoa(ft_abs_ll(decimal))[0];
			i++;
		}
		total_len = len + precision + 1;
	}
	else if (options->flags & F_HASHTAG)
	{
		nb_str = ft_strjoin_replace(nb_str, ".", 1);
	
		total_len++;
	}
	last_digit = ft_abs_float((nb - (long long int)nb) * 10);
	
	//printf("hey nb is %.30Lf\n", nb);
	nb_str = round_float(nb_str, last_digit, total_len, nb);

	if (options->flags & F_PLUS && nb_original >= (double)0 && !is_negzero)
		nb_str = ft_strjoin_replace("+", nb_str, 0);
	if (*nb_str != '+' && *nb_str != '-')
		options->no_sign = 1;
	if (options->flags & F_ZERO) // how bout the precision tho
		nb_str = adjust_int(nb_str, options->field_width, 1, options);
	if (options->no_sign && options->flags & F_SPACE)
		nb_str = ft_strjoin_replace(" ", nb_str, 0);
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
	long double		nb;

	if (options->len_mod && *options->len_mod == 'L')
	{
		nb = va_arg(*list, long double);
	}
	else
	{
		nb = va_arg(*list, double);
	}
	handle_float(options, nb, char_count);
	long double test = -0.0;
	long double test2 = -0.0;
}
