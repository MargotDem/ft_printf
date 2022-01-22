#include <stdio.h>
#include "ft_printf.h"

int myfunc(char *str, ...);

void oldTest(void)
{
	ft_printf("\n");
	//myfunc("Hey  %d hehe hehe%shello % hellooooo", 5, "heyyy");
	ft_printf("heyy first arg: '%d', and second: '%s',\nand third: '%xvi', and fourth is just a '%',\nand the last bit has no percentage sign\n", 45, "it's a string!");
	ft_printf("\nhey\n");
	ft_printf("\n");
}

void test(void)
{
	t_uchar	nb;
	t_uchar	mask;
	int i = 0;

	nb = 0x00;
	mask = 0x80;
	while (i < 8)
	{
		printf("mask: %x\n", mask);
		mask = mask >> 1;
		i++;
	}

}

int	main(void)
{
	//oldTest();
	ft_printf("hey %356$# - +d hehe\n");
}

/*
error handling: what if nb of arguments passed dont correspond to nb of %, or the types dont match?
display error i guess?

*/