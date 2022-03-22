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



	char *str = "hello";
	char *str2 = "hello";
	(void)str2;

	printf("\n\n");
	printf("hey '%10p'\n", (void *)str);
	ft_printf("hey '%10p'\n", (void *)str);


	printf("\n\n");
	printf("hey '%-10p'\n", (void *)str);
	ft_printf("hey '%-10p'\n", (void *)str);

	printf("\n\n");
	//printf("hey '%+10p'\n", (void *)str);
	ft_printf("hey '%+10p'\n", (void *)str);

	printf("\n\n");
	//printf("hey '%010p'\n", (void *)str);
	ft_printf("hey '%010p'\n", (void *)str);
	
	printf("\n\n");
	//printf("hey '%.10p'\n", (void *)str);
	ft_printf("hey '%.10p'\n", (void *)str);

	printf("\n\n");
	printf("heyyy '%-p'\n", (void *)NULL);
	ft_printf("heyyy '%-p'\n", (void *)NULL);

	printf("\n\n");
	printf("heyyy '%-10p'\n", (void *)NULL);
	ft_printf("heyyy '%-10p'\n", (void *)NULL);

	printf("\n\n");
	printf("heyyy '%20p'\n", (void *)NULL);
	ft_printf("heyyy '%20p'\n", (void *)NULL);

	printf("\n\n");
	printf("heyyy '%-4p'\n", (void *)NULL);
	ft_printf("heyyy '%-4p'\n", (void *)NULL);

	printf("\n\n");
	printf("heyyy '%20p'\n", (void *)str);
	ft_printf("heyyy '%20p'\n", (void *)str);

	*/



	printf("\n\n");
	printf("heyyy '%f'\n", (double)10);
	ft_printf("heyyy '%f'\n", (double)10);

	printf("\n\n");
	printf("heyyy '%.f'\n", (double)10);
	ft_printf("heyyy '%.f'\n", (double)10);

	printf("\n\n");
	printf("heyyy '%.0f'\n", (double)10);
	ft_printf("heyyy '%.0f'\n", (double)10);

	printf("\n\n");
	printf("heyyy '%.1f'\n", (double)10);
	ft_printf("heyyy '%.1f'\n", (double)10);

	printf("\n\n");
	printf("heyyy '%.4f'\n", (double)10);
	ft_printf("heyyy '%.4f'\n", (double)10);

	printf("\n\n");
	printf("heyyy '%.10f'\n", (double)10);
	ft_printf("heyyy '%.10f'\n", (double)10);

	printf("\n\n");
	printf("heyyy '%Lf'\n", (long double)10);
	ft_printf("heyyy '%Lf'\n", (long double)10);


	printf("test '%d'\n", (int)10.9988);
	printf("test '%f'\n", 10.9988);
	printf("test '%.f'\n", 10.9988);
	printf("test '%.f'\n", 10.1);
	printf("test '%.f'\n", 10.4);
	printf("test '%.f'\n", 10.5);
	printf("test '%.f'\n", 10.6);

	printf("test '%.f'\n", 10.49);
	printf("test '%.1f'\n", 10.9988);
	printf("test '%.3f'\n", 10.9988);
	printf("test '%.1f'\n", 10.88);

	printf("test '%d'\n", (int)10.9);
	printf("test '%f'\n", 0.56 * 10);

	printf("hey '%#########################################################################--###------10o'\n", 7);
	ft_printf("hey '%########################################################--####################------10o'\n", 7);

	printf("hey %f\n", (double)10.2);
	printf("hey %lf\n", (double)10.2);
	printf("hey %Lf\n", (long double)10.2);

		printf("\n\n");
	printf("hey '%-15f'\n", (double)10.256);
	ft_printf("hey '%-15f'\n", (double)10.256);

	printf("test '%#.0f'\n", 10.49);
	ft_printf("test '%#.0f'\n", 10.49);

	printf("oihkugjtest '%.f'\n", 10.56);
	printf("oihkugjtest '%.f'\n", 10.50);
	printf("oihkugjtest '%.f'\n", 10.55);
	printf("oihkugjtest '%.f'\n", 10.51);
	printf("oihkugjtest '%.f'\n", 10.499);
	printf("oihkugjtest '%.f'\n", 10.501);
	printf("oihkugjtest '%.f'\n", 10.5001);
	printf("oihkugjtest '%.f'\n", 10.50001);
	printf("oihkugjtest '%.f'\n", 10.500001);
	printf("oihkugjtest '%.f'\n", 10.5000001);
	printf("oihkugjtest '%.f'\n", 10.50000001);
	printf("oihkugjtest '%.f'\n", 10.500000001);
	printf("oihkugjtest '%.f'\n", 10.5000000001);
	printf("oihkugjtest '%.f'\n", 10.50000000001);
	printf("oihkugjtest '%.f'\n", 10.500000000001);
	printf("oihkugjtest '%.f'\n", 10.5000000000001);
	printf("oihkugjtest '%.f'\n", 10.50000000000001);
	printf("oihkugjtest '%.f'\n", 10.500000000000001);
	printf("here '%.f'\n", 10.5000000000000009);
	printf("oihkugjtest '%.f'\n", 10.5000000000000001);
	printf("oihkugjtest '%.f'\n", 10.5000000000000004);
	printf("oihkugjtest '%.f'\n", 10.5000000000000005);
	printf("oihkugjtest '%.f'\n", 10.5000000000000008);
	printf("there '%.f'\n", 10.5000000000000009);
	printf("oihkugjtest '%.f'\n", 10.50000000000000089);
	printf("oihkugjtest '%.f'\n", 10.50000000000000059);
	printf("oihkugjtest '%.f'\n", 10.50000000000000001); //17
	printf("oihkugjtest '%.f'\n", 10.500000000000000001); //17

	printf("AAAA\n");


	printf("oihkugjtest '%.f'\n", 10.5000000000000008881);
	printf("oihkugjtest '%.f'\n", 10.5000000000000008884);

	printf("oihkugjtest '%.f'\n", 10.5000000000000008885);
	printf("hehehoho '%.f'\n", 0.5000000000000008881);
	printf("hehehoho '%.f'\n", 0.5000000000000008884);
	printf("hehehoho '%.f'\n", 0.5000000000000008885);


	printf("bankers rounding '%.f'\n", 0.5);
	printf("bankers rounding '%.f'\n", 1.5);

	printf("test '%.10f'\n", 10.49);


	printf("oihkugjtest '%.f'\n", 10.5000000000000008881);
	printf("oihkugjtest '%.f'\n", 10.5000000000000008884);
	printf("\n\n");

	printf("oihkugjtest '%.f'\n", 9.5000000000000008881);
	printf("oihkugjtest '%.f'\n", 9.5000000000000008884);
	printf("\n\n");

	printf("oihkugjtest '%.f'\n", 8.5000000000000008881);
	printf("oihkugjtest '%.f'\n", 8.5000000000000008884);
	printf("\n\n");

	printf("oihkugjtest '%.f'\n", 7.5000000000000008881);
	printf("oihkugjtest '%.f'\n", 7.5000000000000008884);
	printf("\n\n");

	printf("oihkugjtest '%.f'\n", 6.5000000000000008881);
	printf("oihkugjtest '%.f'\n", 6.5000000000000008884);
	printf("\n\n");

	printf("oihkugjtest '%.f'\n", 5.5000000000000008881);
	printf("oihkugjtest '%.f'\n", 5.5000000000000008884);
	printf("\n\n");

	printf("oihkugjtest '%.f'\n", 4.5000000000000008881);
	printf("oihkugjtest '%.f'\n", 4.5000000000000008884);
	printf("\n\n");

	printf("oihkugjtest '%.f'\n", 10.5000000000000008881);
	printf("oihkugjtest '%.f'\n", 10.50000000000000088818);
	printf("oihkugjtest '%.17f'\n", 10.5000000000000008882);
	printf("oihkugjtest '%.20f'\n", 10.5000000000000008882);
	printf("oihkugjtest '%.19f'\n", 10.5000000000000008882);


	printf("HLELLLOOOOOOOO\n\n"); 

	printf("\n\n");
	printf("hello hello '%.4f'\n", 10.50009);
 ft_printf("hello hello '%.4f'\n", 10.50009);

	printf("\n\n");
	printf("hello hello '%.f'\n", 10.50009);
 ft_printf("hello hello '%.f'\n", 10.50009);
	
	printf("\n\n");
	printf("WHAT IN THE NAME OF JESUS '%.f'\n", 10.5000000000000008881);
 ft_printf("hello hello '%.f'\n", 10.5000000000000008881);

 	printf("\n\n");
	printf("hello hello '%.f'\n", 10.5000004000000008881);
 ft_printf("hello hello '%.f'\n", 10.5000004000000008881);

	printf("\n\n");
	printf("hello hello '%.f'\n", 10.5000000000000008882);
 ft_printf("hello hello '%.f'\n", 10.5000000000000008882);

	printf("\n\n");
	printf("hello hello '%.f'\n", 10.50000000000000088818);
 ft_printf("hello hello '%.f'\n", 10.50000000000000088818);

 	printf("\n\n");
	printf("hello hello '%.17f'\n", 10.5000000000000008882);
 ft_printf("hello hello '%.17f'\n", 10.5000000000000008882);

  	printf("\n\n");
	printf("hello hello '%.19f'\n", 10.5000000000000008882);
 ft_printf("hello hello '%.19f'\n", 10.5000000000000008882);

  	printf("\n\n");
	printf("hello hello '%.20f'\n", 10.5000000000000008882);
 ft_printf("hello hello '%.20f'\n", 10.5000000000000008882);


	printf("\n\n");
	printf("bankers rounding '%.f'\n", 4.5);
 ft_printf("bankers rounding '%.f'\n", 4.5);

		printf("\n\n");
	printf("bankers rounding '%.f'\n", 5.5);
 ft_printf("bankers rounding '%.f'\n", 5.5);



	printf("\n\n");
	printf("oihkugjtest '%.1f'\n", 5.9);
 ft_printf("oihkugjtest '%.1f'\n", 5.9);

	printf("\n\n");
	printf("oihkugjtest '%.1f'\n", 5.5);
 ft_printf("oihkugjtest '%.1f'\n", 5.5);

	printf("\n\n");
	printf("oihkugjtest '%.1f'\n", 5.95);
 ft_printf("oihkugjtest '%.1f'\n", 5.95);

	printf("\n\n");
	printf("oihkugjtest '%.1f'\n", 5.595);
 ft_printf("oihkugjtest '%.1f'\n", 5.595);

	printf("\n\n");
	printf("oihkugjtest '%f'\n", 5.595);
 ft_printf("oihkugjtest '%f'\n", 5.595);

	printf("\n\n");
	printf("oihkugjtest '%.1f'\n", 5.49);
 ft_printf("oihkugjtest '%.1f'\n", 5.49);

	printf("\n\n");
	printf("oihkugjtest '%.1f'\n", 5.59);
 ft_printf("oihkugjtest '%.1f'\n", 5.59);
	
	printf("\n\n");
	printf("oihkugjtest '%.1f'\n", 5.99);
 ft_printf("oihkugjtest '%.1f'\n", 5.99);

	printf("\n\n");
	printf("oihkugjtest '%.40f'\n", 5.0000001155566464684864646158489596566);
 ft_printf("oihkugjtest '%.40f'\n", 5.0000001155566464684864646158489596566);

	printf("\n\n");
	printf("oihkugjtest '%.30f'\n", 5.0000001155566464684864646158489596566);
 ft_printf("oihkugjtest '%.30f'\n", 5.0000001155566464684864646158489596566);


	printf("\n\n");
	printf("oihkugjtest '%.f'\n", 5.9);
 ft_printf("oihkugjtest '%.f'\n", 5.9);

 	printf("\n\n");
	printf("oihkugjtest '%#.f'\n", 5.9);
 ft_printf("oihkugjtest '%#.f'\n", 5.9);

	printf("\n\n");
	printf("oihkugjtest '%.1f'\n", 5.96);
 ft_printf("oihkugjtest '%.1f'\n", 5.96);

 	printf("\n\n");
	printf("oihkugjtest '%.1f'\n", 9.99);
 ft_printf("oihkugjtest '%.1f'\n", 9.99);

 	printf("\n\n");
	printf("oihkugjtest '%.f'\n", (double)456);
 ft_printf("oihkugjtest '%.f'\n", (double)456);

  	printf("\n\n");
	printf("oihkugjtest '%.f'\n", (double)0.0);
 ft_printf("oihkugjtest '%.f'\n", (double)0.0);

   	printf("\n\n");
	printf("oihkugjtest '%.f'\n", (double)0.004);
 ft_printf("oihkugjtest '%.f'\n", (double)0.004);

    	printf("\n\n");
	printf("oihkugjtest '%.3f'\n", (double)0.004);
 ft_printf("oihkugjtest '%.3f'\n", (double)0.004);

     	printf("\n\n");
	printf("oihkugjtest '%.3f'\n", (double)0.005);
 ft_printf("oihkugjtest '%.3f'\n", (double)0.005);

     	printf("\n\n");
	printf("oihkugjtest '%.2f'\n", (double)0.005);
 ft_printf("oihkugjtest '%.2f'\n", (double)0.005);

   	printf("\n\n");
	printf("oihkugjtest '%.f'\n", (double)0.555);
 ft_printf("oihkugjtest '%.f'\n", (double)0.555);

  	printf("\n\n");
	printf("oihkugjtest '%.f'\n", (double)0);
 ft_printf("oihkugjtest '%.f'\n", (double)0);



/*
//printf("%.2c\n", NULL);
ft_printf("'%.2c'\n", NULL);
printf("\n\n");

printf("@moulitest: '%c'\n", 0);
ft_printf("@moulitest: '%c'\n", 0);
printf("\n\n");

printf("'%2c'\n", 0);
ft_printf("'%2c'\n", 0);
printf("\n\n");

printf("null '%c' and text\n", 0);
ft_printf("null '%c' and text\n", 0);
printf("\n\n");

printf("null '%c' and text\n", 0);
ft_printf("null '%c' and text\n", 0);
printf("\n\n");

*/

	
}

