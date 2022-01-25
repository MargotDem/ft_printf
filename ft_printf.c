/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:47:41 by mde-maul          #+#    #+#             */
/*   Updated: 2022/01/18 14:47:43 by mde-maul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_int(va_list *list)
{
	ft_putnbr(va_arg(*list, int));
	return (1);
}

static int	handle_str(va_list *list)
{
	ft_putstr(va_arg(*list, char *));
	return (1);
}

static int	handle_garbage(va_list *list)
{
	(void)list;
	write(1, "its nonsensical garbage!", 25);
	return (3);
}

static int	handle_nothing(va_list *list)
{
	(void)list;
	write(1, "%", 1);
	return (0);
}

int handle_arg2(char *ptr, va_list *list)
{
	int	ret;
	int	i;
	t_handle_arg	*array[3];
	t_handle_arg handle_arg_int;
	t_handle_arg handle_arg_str;
	t_handle_arg handle_arg_garbage;
	t_handle_arg handle_arg_nothing;

	handle_arg_int.arg = "d";
	handle_arg_int.func = &handle_int;

	handle_arg_int.arg = "s";
	handle_arg_int.func = &handle_int;

	handle_arg_int.arg = "xvi";
	handle_arg_int.func = &handle_int;

	array[0] = &handle_arg_int;
	array[1] = &handle_arg_str;
	array[2] = &handle_arg_garbage;

	ret = 0;
	while (i < 3)
	{
		if (ft_strequ(array[i]->arg, ptr + 1)) // !!!
		{
			ret = (array[i]->func)(list);
		}
		i++;
	}
	if (ret == 0)
		ret = handle_nothing(list);
	return (ret);
}

int	handle_arg(char *ptr, va_list *list)
{
	int	ret;
	int	func;
	handle_arg_type	*array[4];

	array[0] = &handle_int;
	array[1] = &handle_str;
	array[2] = &handle_garbage;
	array[3] = &handle_nothing;
	if (*(ptr + 1) == 'd')
	{
		func = 0;
	}
	else if (*(ptr + 1) == 's')
	{
		func = 1;
	}
	else if (*(ptr + 1) == 'x' && *(ptr + 2) == 'v' && *(ptr + 3) == 'i')
	{
		func = 2;
	}
	else
	{
		func = 3;
	}
	ret = (array[func])(list);

	return ret;	
}

int	ft_printf(const char *str, ...)
{
	char		*ptr;
	size_t		ret;
	va_list		list;
	size_t		char_count;

	va_start(list, str);
	char_count = 0;
	ptr = ft_strchr(str, (int)'%');
	while (ptr)
	{
		write(1, str, (int)(ptr - str));
		char_count += (size_t)(ptr - str);
		//ret = handle_arg(ptr, &list);
		ret = parse_conv_specification(ptr + 1, &list, &char_count);
		//printf("ret %zu\n", ret);
		str = ptr + 1 + ret;
		ptr = ft_strchr(str, (int)'%');
	}
	write(1, str, ft_strlen(str));
	char_count += ft_strlen(str);
	return (char_count);
}

/*
int myfunc2(char *str, ...)
{
   va_list list;
   int j = 0;
   int i = 0;
   int count = 0;


	while (str[i])
	{
		if (str[i] == 'd' || str[i] == 's')
			count++;
		i++;
	}
   va_start(list, str);
   printf("%d\n", va_arg(list, int));
   printf("%s\n", va_arg(list, char *));
   //for(j=0; j<count; j++)
   //{
     //printf("%d\n", va_arg(list, int));
   //}

   va_end(list);

   return count;
}

*/

/*
ok so
array of strings
if ptr
put the first string bit into array
then analyse after %
switch  that
the functions: add to the string array the appropriate string
we dont know in advance how big the array is tho?? fuck. linked list then? yeah ok
the functions add the appropriate el to the list
after a function returned, skip to after the flag bit and redo
...???
*/