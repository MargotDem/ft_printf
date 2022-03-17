#include <stdio.h>
#include "ft_printf.h"
#include "tests/tests.h"

int myfunc(char *str, ...);

void oldTest(void)
{
	ft_printf("\n");
	//myfunc("Hey  %d hehe hehe%shello % hellooooo", 5, "heyyy");
	ft_printf("heyy first arg: '%d', and second: '%s',\nand third: '%xvi', and fourth is just a '%',\nand the last bit has no percentage sign\n", 45, "it's a string!");
	ft_printf("\nhey\n");
	ft_printf("\n");
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

int	main(void)
{
	long long int	ll_nb;
	long int	l_nb;
	int	nb;
	unsigned int u_nb;
	unsigned long int ul_nb;
	unsigned long long int ull_nb;

	ll_nb = -9223372036854775807;
	l_nb = -922;
	nb = -563;
	ull_nb = 25;
	ul_nb = 56;
	u_nb = -52;
	//char r = 'R';
	//short int my_int = 42;
	printf("hey '%llx'\n", ull_nb);
	ft_printf("hey '%llx'\n", ull_nb);
	// ft_printf("hey '%.3d', and '%d'\n", 42, 58);
}
