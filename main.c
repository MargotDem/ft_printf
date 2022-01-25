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
		printf("rl: '%d'\n", -358);
	ft_printf("ft: '%d'\n", -358);
	printf("\n");

	printf("rl: '%.d'\n", -358);
	ft_printf("ft: '%.d'\n", -358);
	printf("\n");

	printf("rl: '%.4d'\n", -358);
	ft_printf("ft: '%.4d'\n", -358);
	printf("\n");

	printf("rl: '%-10.6d'\n", -358);
	ft_printf("ft: '%-10.6d'\n", -358);
	printf("\n");

	printf("rl: '%010.6d'\n", -358);
	ft_printf("ft: '%010.6d'\n", -358);
	printf("\n");

	printf("rl: '%010d'\n", -358);
	ft_printf("ft: '%010d'\n", -358);
	printf("\n");

	printf("rl: '%10d'\n", -358);
	ft_printf("ft: '%10d'\n", -358);
	printf("\n");

	printf("rl: '%.6d'\n", -358);
	ft_printf("ft: '%.6d'\n", -358);
	printf("\n");

	printf("rl: '%0.6d'\n", -358);
	ft_printf("ft: '%0.6d'\n", -358);
	printf("\n");

	printf("rl: '%09.2d'\n", -358);
	ft_printf("ft: '%09.2d'\n", -358);
	printf("\n");

	printf("rl: '%09d'\n", -358);
	ft_printf("ft: '%09d'\n", -358);
	printf("\n");

	printf("rl: '%9d'\n", -358);
	ft_printf("ft: '%9d'\n", -358);
	printf("\n");
	
//endless zeros ft_printf("ft: '%-6d'\n", 589);
}

/*
error handling: what if nb of arguments passed dont correspond to nb of %, or the types dont match?
display error i guess?

why doesnt the real printf pad with zeros in this case: 


so
str:
padded prtin, with or without precision adjustment
0 undefined

int
if precision: make the 0 padded digit if needed, if field width padded print: with space only

if not precision but field width:
if 0 and -, 0 ignored ie padded print with spaces and left
if 0, padded print with 0, right
if -, left and spaces
if no flag, space and right



segfault
ft_printf("ft: '%0d'\n", -58);

*/


