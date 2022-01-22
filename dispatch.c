#include "ft_printf.h"

void    zero_pad_print(int  nb, size_t precision)
{
    size_t   len;
    size_t  zeroes;
    size_t  neg;
    char    *nb_str;

    neg = 0;
    if (nb < 0)
    {
        nb = -nb;
        neg = 1;
    }
    nb_str = ft_itoa(nb);
    len = ft_strlen(nb_str);
    zeroes = precision - len;
    if (neg)
        ft_putchar('-');
    while (zeroes > 0)
    {
        ft_putchar('0');
        zeroes--;
    }
    ft_putstr(nb_str);
}

void    handle_int(t_options *options, va_list *list)
{
    char *nb_str;
    int nb;

    nb = va_arg(*list, int);
    nb_str = ft_itoa(nb);
    if (options->precision == 0)
        return;
    if (options->precision < 0 || options->precision <= ft_strlen(nb_str))
        ft_putstr(nb_str);
    else
        zero_pad_print(nb, options->precision);
}

void    handle_str(t_options *options, va_list *list)
{
    char    *str;
//handle field width
    str = va_arg(*list, char *);
    if (options->len_mod && !ft_strncmp(options->len_mod, "l", 1))
        ft_putchar('?');
    else
    {
        if (options->precision < 0 || options->precision > ft_strlen(str))
            ft_putstr(str);
        else
            ft_putstr(ft_strsub(str, 0, options->precision));
    }
}

void    handle_char(t_options *options, va_list *list)
{
    if (options->len_mod && !ft_strncmp(options->len_mod, "l", 1))
        ft_putchar('?');
    else
	    ft_putchar(va_arg(*list, int));
}

void    handle_percentage(t_options *options, va_list *list)
{
    (void)options;

	ft_putchar('%');
}

void    dispatch(t_options *options, va_list *list)
{
    handle_arg_type2    *array[11];

    array[0] = &handle_int;
    array[1] = &handle_int;
    array[7] = &handle_char;
    array[8] = &handle_str;
    array[10] = &handle_percentage;

    (array[options->conv_spec])(options, list);
}


	/*int	arg_nb;
	char *arg_nb_str;
	size_t  arg_nb_len;

	arg_nb = ft_atoi(ptr);
	arg_nb_str = ft_itoa(arg_nb);
    arg_nb_len = ft_strlen(arg_nb_str);
    if (*(ptr + arg_nb_len) != '$')
        return ;
    //what is is negative?
    if (ft_atoi(ptr) < 0)
        exit(1);
    if (arg_nb == 0)
    {
        options->arg_nb = 0;
        options->chars_to_skip = 0;
        return ;
    }
	options->arg_nb = arg_nb;
	options->chars_to_skip = arg_nb_len + 1;*/