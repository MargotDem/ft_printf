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

//deletee
#include <stdio.h>
#include "ft_printf.h"

void	ft_printf(char *str)
{
	char	*ptr;

	ptr = ft_strchr(str, (int)'%');
	while (ptr)
	{
		write(1, str, (int)(ptr - str));
		write(1, ptr + 1, 1);
		str = ptr + 1;
		ptr = ft_strchr(str, (int)'%');
	}
	printf("\n\n");
}
/*
ok so
array of strings
if ptr
put the first string bit into array
then analyse after %
switch on that
the functions: add to the string array the appropriate string
we dont know in advance how big the array is tho?? fuck. linked list then? yeah ok
the functions add the appropriate el to the list
after a function returned, skip to after the flag bit and redo
...???
*/