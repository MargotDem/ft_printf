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

char	*round_float(char	*nb_str, size_t last_digit, size_t len)
{
	size_t	second_to_last;
	size_t	place;
	int		main;
	char	*tmp;

	if (!ft_strcmp(nb_str, "0"))
	{
		printf("heyyyyyyyyyy\n");
		return (nb_str);
	}
	if (last_digit > 4)
	{
		main = ft_atoi(nb_str);
		if (ft_strlen(ft_itoa(main)) == len || ft_strlen(ft_itoa(main)) == len - 1)
		{
			//printf("just an int or int and dot. str is '%s' \n", nb_str);
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
		}
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
			{
				// feels like deja vu lmao
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
			}
		}
	}
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
	size_t	last_digit; 

	nb = va_arg(*list, double);
	main = (int)nb;
	precision = options->precision;
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
			nb_str[len + i + 1] = ft_itoa(decimal)[0];
			i++;
		}
		total_len = len + precision + 1;
	}
	else if (options->flags & F_HASHTAG)
	{
		tmp = ft_strjoin(nb_str, ".");
		free(nb_str);
		nb_str = tmp;
		total_len++;
	}
	nb = (nb - (int)nb) * 10;
	last_digit = (int)nb;
	nb_str = round_float(nb_str, last_digit, total_len);
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
