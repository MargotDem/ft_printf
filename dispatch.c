#include "ft_printf.h"

void    handle_int(t_options *options, va_list *list)
{
    (void)options;

    ft_putnbr(va_arg(*list, int));
}

void    handle_str(t_options *options, va_list *list)
{
    (void)options;

	ft_putstr(va_arg(*list, char *));
}

void    handle_char(t_options *options, va_list *list)
{
    (void)options;

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
