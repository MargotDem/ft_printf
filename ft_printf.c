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

void	initialize_dispatcher(handle_arg_type **dispatcher)
{
	dispatcher[CS_D] = &handle_int;
	dispatcher[CS_I] = &handle_int;
	dispatcher[CS_C] = &handle_char;
	dispatcher[CS_S] = &handle_str;
	dispatcher[CS_X] = &handle_hex;
	dispatcher[CS_PERCENTAGE] = &handle_percentage;
}

int	ft_printf(const char *str, ...)
{
	char		*ptr;
	size_t		ret;
	va_list		list;
	size_t		char_count;
	handle_arg_type    *dispatcher[11];

	va_start(list, str);
	initialize_dispatcher(dispatcher);
	char_count = 0;
	ptr = ft_strchr(str, (int)'%');
	while (ptr)
	{
		write(1, str, (int)(ptr - str));
		char_count += (size_t)(ptr - str);
		//ret = handle_arg(ptr, &list);
		ret = parse_conv_specification(ptr + 1, &list, &char_count, dispatcher);
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