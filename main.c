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
	short int	short_nb;
	unsigned int u_nb;
	unsigned long int ul_nb;
	unsigned long long int ull_nb;
	char	my_char;

	ll_nb = -9223372036854775807;
	l_nb = -922;
	nb = 42;
	ull_nb = 25;
	ul_nb = 56;
	u_nb = -52;
	short_nb = -563;
	my_char = 'g';
	//char r = 'R';
	//short int my_int = 42;

	/*
	printf("hey '% 10.5d'\n", nb);
	ft_printf("hey '% 10.5d'\n", nb);
	printf("\n\n");
	printf("hey '% d'\n", nb);
	ft_printf("hey '% d'\n", nb);
	printf("\n\n");
	printf("hey '% 10d'\n", nb);
	ft_printf("hey '% 10d'\n", nb);
		printf("\n\n");
	printf("hey '% .5d'\n", nb);
	ft_printf("hey '% .5d'\n", nb);
	printf("\n\n");
	printf("\n\n");
	printf("hey '%10.5d'\n", -6);
	ft_printf("hey '%10.5d'\n", -6);
		printf("\n\n");
	printf("hey '%+10.5d'\n", 6);
	ft_printf("hey '%+10.5d'\n", 6);
	

	printf("\n\n");
	printf("hey '%#x'\n", 6);
	ft_printf("hey '%#x'\n", 6);

	printf("\n\n");
	printf("hey '%#x'\n", 0);
	ft_printf("hey '%#x'\n", 0);

	printf("\n\n");
	printf("hey '%#x'\n", 9);
	ft_printf("hey '%#x'\n", 9);


	printf("\n\n");
	printf("hey '%#.5x'\n", 9);
	ft_printf("hey '%#.5x'\n", 9);

	printf("\n\n");
	printf("hey '%#.5x'\n", 0);
	ft_printf("hey '%#.5x'\n", 0);

	printf("\n\n");
	printf("hey '%#10X'\n", 10);
	ft_printf("hey '%#10X'\n", 10);

	printf("\n\n");
	printf("hey '%#10.5x'\n", 9);
	ft_printf("hey '%#10.5x'\n", 9);

	printf("\n\n");
	printf("hey '%#10.5o'\n", 9);
	ft_printf("hey '%#10.5o'\n", 9);

	printf("hey '%+010.8d'\n", 9);
	ft_printf("hey '%+010.8d'\n", 9);
	
	printf("\n\n");
	printf("hey '%.4o'\n", 9);
	ft_printf("hey '%.4o'\n", 9);

	printf("\n\n");
	printf("hey '%#o'\n", 9);
	ft_printf("hey '%#o'\n", 9);

	printf("\n\n");
	printf("hey '%#o'\n", 0);
	ft_printf("hey '%#o'\n", 0);

	printf("\n\n");
	printf("hey '%- d'\n", 45);
	ft_printf("hey '%- d'\n", 45);

	printf("\n\n");
	printf("hey '%- 10d'\n", 45);
	ft_printf("hey '%- 10d'\n", 45);

	printf("\n\n");
	printf("hey '% d'\n", -45);
	ft_printf("hey '% d'\n", -45);

	printf("\n\n");
	printf("hey '%- 10d'\n", -45);
	ft_printf("hey '%- 10d'\n", -45);

	printf("\n\n");
	printf("hey '% 10d'\n", -45);
	ft_printf("hey '%+ 10d'\n", -45);

	printf("\n\n");
	printf("hey '%+10d'\n", 58);
	ft_printf("hey '%+10d'\n", 58);

	printf("\n\n");
	printf("%u\n", (unsigned int)4294967295);
	ft_printf("% u\n", (unsigned int)4294967295);

	printf("\n\n");
	printf("@moulitest: %.d %.0d\n", 0, 0);
	ft_printf("@moulitest: %.d %.0d\n", 0, 0);

	printf("\n\n");
	printf("wtf '%.d %.0d'\n", 0, 0);
	ft_printf("wtf '%.d %.0d'\n", 0, 0);

	printf("\n\n");
	printf("wtf '%10.d'\n", 0);
	ft_printf("wtf '%10.d'\n", 0);

	printf("\n\n");
	printf("wtf '%.0d'\n", 0);
	ft_printf("wtf '%.0d'\n", 0);

	printf("\n\n");
	printf("wtf '%d'\n", 0);
	ft_printf("wtf '%d'\n", 0);

	printf("\n\n");
	printf("wtf '%#08x'\n", 42);
	ft_printf("wtf '%#08x'\n", 42);

	printf("\n\n");
	printf("wtf '%#08o'\n", 42);
	ft_printf("wtf '%#08o'\n", 42);

	printf("\n\n");
	printf("wtf '%#08.o'\n", 42);
	ft_printf("wtf '%#08.o'\n", 42);

	printf("\n\n");
	printf("wtf '%#08.4o'\n", 42);
	ft_printf("wtf '%#08.4o'\n", 42);

	printf("\n\n");
	printf("wtf '%#0o'\n", 42);
	ft_printf("wtf '%#0o'\n", 42);


	printf("\n\n");
	printf("wtf '%#8o'\n", 42);
	ft_printf("wtf '%#8o'\n", 42);

	printf("\n\n");
	printf("wtf '%#8x'\n", 42);
	ft_printf("wtf '%#8x'\n", 42);


	printf("\n\n");
	printf("wtf '%#08x'\n", 42);
	ft_printf("wtf '%#08x'\n", 42);

	printf("\n\n");
	printf("wtf '%#02x'\n", 42);
	ft_printf("wtf '%#02x'\n", 42);

	printf("\n\n");
	printf("wtf '%#08.15x'\n", 42);
	ft_printf("wtf '%#08.15x'\n", 42);


	printf("\n\n");
	printf("wtf '%#08.5x'\n", 42);
	ft_printf("wtf '%#08.5x'\n", 42);

	printf("\n\n");
	printf("wtf '%#8x'\n", 42);
	ft_printf("wtf '%#8x'\n", 42);

	printf("\n\n");
	printf("wtf '%#8.x'\n", 42);
	ft_printf("wtf '%#8.x'\n", 42);

	printf("\n\n");
	printf("wtf '%#8.15x'\n", 42);
	ft_printf("wtf '%#8.15x'\n", 42);

	printf("\n\n");
	printf("hey '%#.x' '%#.0x'\n", 0, 0);
	ft_printf("hey '%#.x' '%#.0x'\n", 0, 0);

	printf("\n\n");
	printf("hey '%#.x' '%#.0x'\n", 1, 1);
	ft_printf("hey '%#.x' '%#.0x'\n", 1, 1);

	printf("\n\n");
	printf("wtf '% .d'\n", 0);
	ft_printf("wtf '% .d'\n", 0);

	printf("\n\n");
	printf("hey '%#.o'\n", 0);
	ft_printf("hey '%#.o'\n", 0);

	printf("\n\n");
	printf("hey '%#.1o'\n", 0);
	ft_printf("hey '%#.1o'\n", 0);

	printf("\n\n");
	printf("hey '%#.o'\n", 5);
	ft_printf("hey '%#.o'\n", 5);

	printf("\n\n");
	printf("hey '%#.2o'\n", 5);
	ft_printf("hey '%#.2o'\n", 5);

	

	printf("\n\n");
	//printf("hey '%.2c'\n", (char)NULL);
	ft_printf("hey '%.2c'\n", (char)NULL);

	printf("\n\n");
	printf("hey '%c'\n", (char)0);
	ft_printf("hey '%c'\n", (char)0);

	printf("\n\n");
	printf("hey '%1c'\n", (char)0);
	ft_printf("hey '%1c'\n", (char)0);

	printf("\n\n");
	printf("hey '%-2c'\n", (char)0);
	ft_printf("hey '%-2c'\n", (char)0);

	printf("\n\n");
	printf("hey '%3c'\n", (char)0);
	ft_printf("hey '%3c'\n", (char)0);

	printf("\n\n");
	//printf("hey '%0c'\n", (char)0);
	ft_printf("hey '%0c'\n", (char)0);

	printf("\n\n");
	//printf("hey '% c'\n", (char)0);
	ft_printf("hey '% c'\n", (char)0);

	printf("\n\n");
	printf("hey '%3c'\n", 'f');
	ft_printf("hey '%3c'\n", 'f');

	*/

	char *str = "hello";
	char *str2 = "hello";
	printf("\n\n");
	printf("hey '%10p'\n", (void *)str2);
	ft_printf("hey '%10p'\n", (void *)str2);
	printf("test '%x'\n", (unsigned int)str2);

	printf("\n\n");
	//printf("hey '%.10p'\n", (void *)str);
	ft_printf("hey '%.10p'\n", (void *)str);
}

/*
ft_printf("%.2c", NULL); -> "^@"
ft_printf("@moulitest: %c", 0);               -> "@moulitest: ^@"
ft_printf("%2c", 0);                          -> " ^@"
ft_printf("null %c and text", 0);             -> "null ^@ and text"
ft_printf("% c", 0);                          -> "^@"
*/
