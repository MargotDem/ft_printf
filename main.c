#include <stdio.h>
#include "ft_printf.h"

int myfunc(char *str, ...);

int	main(void)
{
	ft_printf("\n");
	//myfunc("Hey  %d hehe hehe%shello % hellooooo", 5, "heyyy");
	ft_printf("heyy first arg: '%d', and second: '%s',\nand third: '%xvi', and fourth is just a '%',\nand the last bit has no percentage sign\n", 45, "it's a string!");
	ft_printf("\nhey\n");
	ft_printf("\n");
}

/*
error handling: what if nb of arguments passed dont correspond to nb of %, or the types dont match?
display error i guess?

*/