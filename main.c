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

void test_fct_0(char *str)
{
	printf("test fct 0: %s\n", str);
}

void test_fct_1(char *str)
{
	printf("test fct 1: %s\n", str);
}

void test_fct_2(char *str)
{
	printf("test fct 2: %s\n", str);
}

void test2(void)
{
	handle_arg_type3	*array[6];
	t_uint16	nb = 0x0005;

	array[0] = &test_fct_0;
	array[1] = &test_fct_1;
	array[5] = &test_fct_2;

	(array[nb])("hey");
}

int	main(void)
{
	//oldTest();
	//ft_printf("hola %.0s, hehe\n", "coucou");
	//printf("hola%s\n", "coucou");
	printf("rl: '%5.3s'\n", "coucou");
	ft_printf("rl: '%5.3s'\n", "coucou");
	//printf("invalid input: %3wesh\n", 2);
	//test2();
}

/*
error handling: what if nb of arguments passed dont correspond to nb of %, or the types dont match?
display error i guess?




*/


