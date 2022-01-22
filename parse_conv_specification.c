#include "ft_printf.h"

void handle_arg_nb(char *ptr, t_options *options)
{
	int	arg_nb;
	char *arg;

	arg_nb = ft_atoi(ptr);
	arg = ft_itoa(arg_nb);

	printf("%s\n", arg);
	if (*(ptr + ft_strlen(arg)) != '$')
	{
		printf("wrong input\n");
		exit(1);
	}
	options->arg_nb = arg;
	options->chars_to_skip = ft_strlen(arg) + 1;
}

t_uchar get_flag(char *ptr)
{
    if (*ptr == '#')
        return (F_HASHTAG);
    else if (*ptr == '0')
        return (F_HASHTAG);
    else if (*ptr == '+')
        return (F_PLUS);
    else if (*ptr == '-')
        return (F_MINUS);
    else
        return (F_SPACE);
}

void    handle_flags(char *ptr, t_options *options)
{
    options->flags = 0x00;
    while (*ptr == '#' || *ptr == '0' || *ptr == '+' || *ptr == '-' || *ptr == ' ')
    {
        options->flags = options->flags | get_flag(ptr);
        options->chars_to_skip += 1;
        ptr++;
    }
}

size_t	parse_conv_specification(char *ptr, va_list *list)
{

	t_options	*options;

	options = (t_options *)malloc(sizeof(t_options));
	if (!options)
		exit(1);
    handle_arg_nb(ptr, options);
    handle_flags(ptr + options->chars_to_skip, options);
    //printf("flags : %x\n", options->flags);
	return (options->chars_to_skip);
}
