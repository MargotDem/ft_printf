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




	

 

/*printf("\n\n");
printf("testons donc '%.15f'\n", 0.500000000000001 - 0.500000000000000);
printf("testons donc '%.15f'\n", 0.5000 - 0.500000000000000);
printf("testons donc '%.15f'\n", 0.5001 - 0.500000000000000);
printf("testons donc '%.15f'\n", 0.5
000000000000001 - 0.500000000000000);

*/

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

/*
int int1;
int int2;
 	printf("\n\n");
	int1 = printf("test null char '%10c'\n", (int)NULL);
 int2 = ft_printf("test null char '%10c'\n", (int)NULL);
	printf("ret printf %d\n", int1);
	printf("ret ft_printf %d\n", int2);

	printf("\n\n");
	int1 = printf("print percentage: '%-10.10%' and '%05%'\n");
	int2 = ft_printf("print percentage: '%-10.10%' and '%05%'\n");
	printf("ret printf %d\n", int1);
	printf("ret ft_printf %d\n", int2);

		printf("\n\n");
	int1 = printf("print percentage: '%015.40%'\n");
	int2 = ft_printf("print percentage: '%015.40%'\n");
	printf("ret printf %d\n", int1);
	printf("ret ft_printf %d\n", int2);



*/

printf("HLELLLOOOOOOOO\n\n"); 

	printf("\n\n");
	printf("hello hello '%.4f'\n", 10.50009);
 ft_printf("hello hello '%.4f'\n", 10.50009);

	printf("\n\n");
	printf("hello hello '%.f'\n", 10.50009);
 ft_printf("hello hello '%.f'\n", 10.50009);
	
	printf("\n\nWHAT IN THE NAME OF JESUS\n");
	printf("hello hello '%.f'\n", 10.5000000000000008881);
 ft_printf("hello hello '%.f'\n", 10.5000000000000008881);

	printf("\n\n");
	printf("hello hello '%.f'\n", 10.5000000000000008882);
 ft_printf("hello hello '%.f'\n", 10.5000000000000008882);

 	printf("\n\n");
	printf("hello hello '%.f'\n", 10.5000004000000008881);
 ft_printf("hello hello '%.f'\n", 10.5000004000000008881);


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
	printf("oihkugjtest '%.1f'\n", 5.9);
 ft_printf("oihkugjtest '%.1f'\n", 5.9);

 	printf("\n\n");
	printf("oihkugjtest '%.f'\n", 5.9);
 ft_printf("oihkugjtest '%.f'\n", 5.9);

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
	printf("oihkugjtest '%#.f'\n", 5.9);
 ft_printf("oihkugjtest '%#.f'\n", 5.9);

	printf("\n\n");
	printf("oihkugjtest '%.1f'\n", 5.96);
 ft_printf("oihkugjtest '%.1f'\n", 5.96);

 	printf("\n\n");
	printf("oihkugjtest '%.1f'\n", 9.99);
 ft_printf("oihkugjtest '%.1f'\n", 9.99);

  	printf("\n\n");
	printf("oihkugjtest '%.f'\n", 9.99);
 ft_printf("oihkugjtest '%.f'\n", 9.99);

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
	printf("oihkugjtest '%.2f'\n", (double)0.005);
 ft_printf("oihkugjtest '%.2f'\n", (double)0.005);

   	printf("\n\n");
	printf("oihkugjtest '%.f'\n", (double)0.555);
 ft_printf("oihkugjtest '%.f'\n", (double)0.555);

  	printf("\n\n");
	printf("oihkugjtest '%.f'\n", (double)0);
 ft_printf("oihkugjtest '%.f'\n", (double)0);


	printf("\n\nBANKERS ROUNDING\n\n");
	printf("bankers rounding '%.f'\n", 4.5);
 ft_printf("bankers rounding '%.f'\n", 4.5);

		printf("\n\n");
	printf("bankers rounding '%.f'\n", 5.5);
 ft_printf("bankers rounding '%.f'\n", 5.5);

 		printf("\n\n");
	printf("bankers rounding '%.f'\n", 4.500000000000001);
 ft_printf("bankers rounding '%.f'\n", 4.500000000000001);

  		printf("\n\n");
	printf("bankers rounding '%.f'\n", 4.5000000000000001);
 ft_printf("bankers rounding '%.f'\n", 4.5000000000000001);

  		printf("\n\n");
	printf("bankers rounding '%.f'\n", 0.5);
 ft_printf("bankers rounding '%.f'\n", 0.5);

  		printf("\n\n");
	printf("bankers rounding '%.f'\n", 1.5);
 ft_printf("bankers rounding '%.f'\n", 1.5);


  		printf("\n\n");
  		printf("\n\n");
	printf("test # '%#f'\n", 4.5);
 ft_printf("test # '%#f'\n", 4.5);

   		printf("\n\n");
	printf("test # '%#.5f'\n", 4.5);
 ft_printf("test # '%#.5f'\n", 4.5);

   		printf("\n\n");
	printf("test # '%#*f'\n", 12, 4.5);
 ft_printf("test # '%#*f'\n", 12, 4.5);

    		printf("\n\n");
	printf("test # '%#.*f'\n", 12, 4.5);
 ft_printf("test # '%#.*f'\n", 12, 4.5);

     		printf("\n\n");
	printf("test # '%#.*f'\n", 0, 4.5);
 ft_printf("test # '%#.*f'\n", 0, 4.5);

      		printf("\n\n");
	printf("test # '%#.f'\n", 4.5);
 ft_printf("test # '%#.f'\n", 4.5);


      		printf("\n\n");
	printf("test # '%#.f'\n", (double)4);
 ft_printf("test # '%#.f'\n", (double)4);


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

	printf("\n\n");
	printf("heyyy '%f'\n", 10.9988);
 ft_printf("heyyy '%f'\n", 10.9988);

		printf("\n\n");
	printf("heyyy '%.f'\n", 10.9988);
 ft_printf("heyyy '%.f'\n", 10.9988);

		printf("\n\n");
	printf("heyyy '%.f'\n", 10.1);
 ft_printf("heyyy '%.f'\n", 10.1);

		printf("\n\n");
	printf("heyyy '%.f'\n", 10.5);
 ft_printf("heyyy '%.f'\n", 10.5);

 		printf("\n\n");
	printf("heyyy '%.3f'\n", 10.9988);
 ft_printf("heyyy '%.3f'\n", 10.9988);

printf("\n\n");
	printf("hey '%#########################################################################--###------10o'\n", 7);
 ft_printf("hey '%########################################################--####################------10o'\n", 7);

 		printf("\n\n");
	printf("hey '%-15f'\n", 10.256);
 ft_printf("hey '%-15f'\n", 10.256);

	printf("\n\n");
	printf("test '%#.0f'\n", 10.49);
 ft_printf("test '%#.0f'\n", 10.49);

	printf("\n\n");
	printf("test '%#-20.1f'\n", 10.49);
 ft_printf("test '%#-20.1f'\n", 10.49);

 	printf("\n\n");
	printf("test '%#-20.25f'\n", 10.49);
 ft_printf("test '%#-20.25f'\n", 10.49);


  	printf("\n\n");
	printf("null '%0 10d' and text\n", 3);
 ft_printf("null '%0 10d' and text\n", 3);

   	printf("\n\n");
	printf("null '%0 10.4d' and text\n", 3);
 ft_printf("null '%0 10.4d' and text\n", 3);

   	printf("\n\n");
	printf("null '%0 .4d' and text\n", 3);
 ft_printf("null '%0 .4d' and text\n", 3);


   	printf("\n\n");
	printf("null '%0 8d' and text\n", 3);
 ft_printf("null '%0 8d' and text\n", 3);


   	printf("\n\n");
	printf("null '% 8d' and text\n", 3);
 ft_printf("null '% 8d' and text\n", 3);
 	
	printf("\n\n");
	printf("null '%010f' and text\n", 3.14159265);
 ft_printf("null '%010f' and text\n", 3.14159265);

 

 	printf("\n\n");
	printf("null '%0 f' and text\n", 3.14159265);
 ft_printf("null '%0 f' and text\n", 3.14159265);

 	printf("\n\n");
	printf("null '%0 10f' and text\n", 3.14159265);
 ft_printf("null '%0 10f' and text\n", 3.14159265);

 	printf("\n\n");
	printf("null '%0+25f' and text\n", 3.14159265);
 ft_printf("null '%0+25f' and text\n", 3.14159265);

 	printf("\n\n");
	printf("null '%0 10f' and text\n", -3.14159265);
 ft_printf("null '%0 10f' and text\n", -3.14159265);

 

  	printf("\n\n");
	printf("null '%0#10.1f' and text\n", -3.14159265);
 ft_printf("null '%0#10.1f' and text\n", -3.14159265);

   	printf("\n\n");
	printf("null '%0#10.1f' and text\n", 3.14159265);
 ft_printf("null '%0#10.1f' and text\n", 3.14159265);

 
    	printf("\n\n");
	printf("null '%.2f' and text\n", -12.126);
 ft_printf("null '%.2f' and text\n", -12.126);

     	printf("\n\n");
	printf("null '%.2f' and text\n", 12.126);
 ft_printf("null '%.2f' and text\n", 12.126);

     	printf("\n\n");
	printf("null '%.2f' and text\n", -958.125);
 ft_printf("null '%.2f' and text\n", -958.125);


      	printf("\n\n");
	printf("null '%.2f' and text\n", 12.135);
 ft_printf("null '%.2f' and text\n", 12.135);

       	printf("\n\n");
	printf("null '%.2f' and text\n", 12.125);
 ft_printf("null '%.2f' and text\n", 12.125);

 	printf("\n\nBANKERS ROUNDING\n\n");
	printf("bankers rounding '%.f'\n", 4.5);
 ft_printf("bankers rounding '%.f'\n", 4.5);

		printf("\n\n");
	printf("bankers rounding '%.f'\n", 5.5);
 ft_printf("bankers rounding '%.f'\n", 5.5);

 		printf("\n\n");
	printf("bankers rounding '%.f'\n", 4.500000000000001);
 ft_printf("bankers rounding '%.f'\n", 4.500000000000001);

  		printf("\n\n");
	printf("bankers rounding '%.f'\n", 4.5000000000000001);
 ft_printf("bankers rounding '%.f'\n", 4.5000000000000001);

  		printf("\n\n");
	printf("bankers rounding '%.f'\n", 0.5);
 ft_printf("bankers rounding '%.f'\n", 0.5);

  		printf("\n\n");
	printf("bankers rounding '%.f'\n", 1.5);
 ft_printf("bankers rounding '%.f'\n", 1.5);


      	printf("\n\nHELLOOOO\n\n");


	printf("null '%.2f' and text\n", 12.135); //12.13
 ft_printf("null '%.2f' and text\n", 12.135);

       	printf("\n\n");
	printf("null '%.2f' and text\n", 12.125); //12.12 makes ZERO SENSE GOD WHY
 ft_printf("null '%.2f' and text\n", 12.125);

       	printf("\n\n");
	printf("null '%.2f' and text\n", 12.136); //12.14 makes sense
 ft_printf("null '%.2f' and text\n", 12.136);

       	printf("\n\n");
	printf("null '%.2f' and text\n", 12.126); //12.13 makes sense
 ft_printf("null '%.2f' and text\n", 12.126);

       	printf("\n\n");
	printf("null '%.2f' and text\n", 12.1352); //12.14
 ft_printf("null '%.2f' and text\n", 12.1352);

        	printf("\n\n");
	printf("null '%.2f' and text\n", -12.1352); //12.14
 ft_printf("null '%.2f' and text\n", -12.1352);




        	printf("\n\n");
	printf("null '%+0f' and text\n", -958.125);
 ft_printf("null '%+0f' and text\n", -958.125);

        	printf("\n\n");
	printf("null '% d' and text\n", 958);
 ft_printf("null '% d' and text\n", 958);

         	printf("\n\n");
	printf("null '%#.f' and text\n", (double)5);
 ft_printf("null '%#.f' and text\n", (double)5);

          	printf("\n\n");
	printf("null '%+f' and text\n", 1.0);
 ft_printf("null '%+f' and text\n", 1.0);

           	printf("\n\n");
	printf("null '%+f' and text\n", -0.0);
 ft_printf("null '%+f' and text\n", -0.0);

 if (-0.0 == 0.0)
	printf("what ever the FUCK is this BULLSHIT\n");




/*
printf("\n\nbest of de cette fonction de la mort\n\n");

// the four following make no sense to me
           	printf("\n\n"); // 0.1
	printf("null '%.1f' and text\n", 0.05);
 ft_printf("null '%.1f' and text\n", 0.05);

        	printf("\n\n"); // 12.12
	printf("null '%.2f' and text\n", 12.125);
 ft_printf("null '%.2f' and text\n", 12.125);

         	printf("\n\n"); // 13.123
	printf("null '%.3f' and text\n", 13.1225);
 ft_printf("null '%.3f' and text\n", 13.1225);

          	printf("\n\n"); // 0.122
	printf("null '%.3f' and text\n", 0.1225);
 ft_printf("null '%.3f' and text\n", 0.1225);

printf("\n\n"); // 10
 	printf("hello hello '%.f'\n", 10.5000000000000008881);
 ft_printf("hello hello '%.f'\n", 10.5000000000000008881);

	printf("\n\n"); // 11
	printf("hello hello '%.f'\n", 10.5000000000000008882);
 ft_printf("hello hello '%.f'\n", 10.5000000000000008882);

 	printf("\n\n"); // 5.0000001155566460298018682806286960840225
	printf("oihkugjtest '%.40f'\n", 5.0000001155566464684864646158489596566);
 ft_printf("oihkugjtest '%.40f'\n", 5.0000001155566464684864646158489596566);


 		printf("\n\n"); // 5
	printf("bankers rounding '%.f'\n", 4.500000000000001);
 ft_printf("bankers rounding '%.f'\n", 4.500000000000001);

  		printf("\n\n"); // 4
	printf("bankers rounding '%.f'\n", 4.5000000000000001);
 ft_printf("bankers rounding '%.f'\n", 4.5000000000000001);
 
 */

           	printf("\n\n"); // 0.1
	printf("null '%.1f' and text\n", 0.05);
 ft_printf("null '%.1f' and text\n", 0.05);

        	printf("\n\n"); // 12.12
	printf("null '%.2f' and text\n", 12.125);
 ft_printf("null '%.2f' and text\n", 12.125);

         	printf("\n\n"); // 13.123
	printf("null '%.3f' and text\n", 13.1225);
 ft_printf("null '%.3f' and text\n", 13.1225);

          	printf("\n\n"); // 0.122
	printf("null '%.3f' and text\n", 0.1225);
 ft_printf("null '%.3f' and text\n", 0.1225);


      	printf("\n\n");
	printf("null '%.2f' and text\n", -958.125);
 ft_printf("null '%.2f' and text\n", -958.125);



           	printf("\n\n");
	printf("hey '%f'\n", 18014398509481984.0);
 ft_printf("hey '%f'\n", 18014398509481984.0);


           	printf("\n\n"); // 0.1
	printf("null '%.1f' and text\n", 0.05);
 ft_printf("null '%.1f' and text\n", 0.05);

            	printf("\n\n"); // 0.1
	printf("null '%.1f' and text\n", 0.15);
 ft_printf("null '%.1f' and text\n", 0.15);

            	printf("\n\n"); // 0.2
	printf("null '%.1f' and text\n", 0.25);
 ft_printf("null '%.1f' and text\n", 0.25);

            	printf("\n\n"); // 0.3
	printf("null '%.1f' and text\n", 0.35);
 ft_printf("null '%.1f' and text\n", 0.35);

         	printf("\n\n"); // 0.5
	printf("null '%.1f' and text\n", 0.45);
 ft_printf("null '%.1f' and text\n", 0.45);

         	printf("\n\n"); // 0.6
	printf("null '%.1f' and text\n", 0.55);
 ft_printf("null '%.1f' and text\n", 0.55);

         	printf("\n\n"); // 0.7
	printf("null '%.1f' and text\n", 0.65);
 ft_printf("null '%.1f' and text\n", 0.65);

 
             	printf("\n\n");
	printf("null '%.0f' and text\n", 1.5);
 ft_printf("null '%.0f' and text\n", 1.5);

              	printf("\n\n");
	printf("null '%.0f' and text\n", 2.5);
 ft_printf("null '%.0f' and text\n", 2.5);
             	printf("\n\n");
	printf("null '%.0f' and text\n", -1.5);
 ft_printf("null '%.0f' and text\n", -1.5);

              	printf("\n\n");
	printf("null '%.0f' and text\n", -2.5);
 ft_printf("null '%.0f' and text\n", -2.5);


              	printf("\n\n");
	printf("null '%.1f' and text\n", -1.78);
 ft_printf("null '%.1f' and text\n", -1.78);

               	printf("\n\n");
	printf("null '%.f' and text\n", -1.78);
 ft_printf("null '%.f' and text\n", -1.78);

                	printf("\n\n");
	printf("null '%.f' and text\n", -0.78);
 ft_printf("null '%.f' and text\n", -0.78);

                 	printf("\n\n");
	printf("null '%.f' and text\n", -0.18);
 ft_printf("null '%.f' and text\n", -0.18);



 //tests im not passing from satus tests
 printf("\n\n\n\n\n\n\n\n\n\n\ntests still not passing \n\n\n");

          	printf("\n\n"); // -958.12
	printf("null '%.2f' and text\n",  -958.125);
 ft_printf("null '%.2f' and text\n",  -958.125);

            	printf("\n\n");
	printf("null '%f' and text\n", -0.0);
 ft_printf("null '%f' and text\n", -0.0);



           	printf("\n\n"); // 0.1 round
	printf("null '%.1f' and text\n", 0.05); //1 odd round. 0 % 2 0.
 ft_printf("null '%.1f' and text\n", 0.05);

            	printf("\n\n"); // 0.1 dont
	printf("null '%.1f' and text\n", 0.15); //02 even dont round
 ft_printf("null '%.1f' and text\n", 0.15);

            	printf("\n\n"); // 0.2 dont
	printf("null '%.1f' and text\n", 0.25); //3 odd round
 ft_printf("null '%.1f' and text\n", 0.25);

            	printf("\n\n"); // 0.3 dont
	printf("null '%.1f' and text\n", 0.35); //4 round
 ft_printf("null '%.1f' and text\n", 0.35);

         	printf("\n\n"); // 0.5 round
	printf("null '%.1f' and text\n", 0.45);
 ft_printf("null '%.1f' and text\n", 0.45);

         	printf("\n\n"); // 0.6 round
	printf("null '%.1f' and text\n", 0.55);
 ft_printf("null '%.1f' and text\n", 0.55);

         	printf("\n\n"); // 0.7 round
	printf("null '%.1f' and text\n", 0.65);
 ft_printf("null '%.1f' and text\n", 0.65);

         	printf("\n\n"); // 0.7 round
	printf("null '%.2f' and text\n", 123.125);
 ft_printf("null '%.2f' and text\n", 123.125);


          	printf("\n\n"); 
	printf("null '%.30f' and text\n",  0.65000000000000002220446049);
 ft_printf("null '%.30f' and text\n",  0.65000000000000002220446049);


         	printf("\n\n"); // 0.7 round
	printf("null '%f' and text\n", 0.876508942);
 ft_printf("null '%f' and text\n", 0.876508942);

          	printf("\n\n"); // 0.7 round
	printf("null '%.f' and text\n", 0.876508942);
 ft_printf("null '%.f' and text\n", 0.876508942);

           	printf("\n\n");
	printf("null '%.1f' and text\n", 0.75);
 ft_printf("null '%.1f' and text\n", 0.75);


           	printf("\n\n");
	printf("null '%#.0f' and text\n", -99.5);
 ft_printf("null '%#.0f' and text\n", -99.5);

            	printf("\n\n");
	printf("null '%.f' and text\n", -0.55);
 ft_printf("null '%.f' and text\n", -0.55);

            	printf("\n\n");
	printf("null '%.f' and text\n", -12.7);
 ft_printf("null '%.f' and text\n", -12.7);

            	printf("\n\n");
	printf("null '%.f' and text\n", -0.0);
 ft_printf("null '%.f' and text\n", -0.0);




            	printf("\n\n");
	printf("hey '%-10f'\n", -1.0 / 0);
 ft_printf("hey '%-10f'\n", -1.0 / 0);

            	printf("\n\n");
	printf("hey '%+f'\n", 1.0 / 0);
 ft_printf("hey '%+f'\n", 1.0 / 0);

             	printf("\n\n");
	printf("hey '%12f'\n", 0.0 / 0);
 ft_printf("hey '%12f'\n", 0.0 / 0);

              	printf("\n\n");
	printf("hey '%.f'\n", -0.0 / 0);
 ft_printf("hey '%.f'\n", -0.0 / 0);


            	printf("\n\nAAAAA\n\n");
	int int1 = printf("hey '% f'\n", 1.0 / 0);
 int int2 = ft_printf("hey '% f'\n", 1.0 / 0);
printf("int1 is %d and int2 is %d\n", int1, int2);


            	printf("\n\nAAAAA\n\n");
	int int3 = printf("hey '%#0 f'\n", 0.0 / 0);
 int int4 = ft_printf("hey '%#0 f'\n", 0.0 / 0);
printf("int1 is %d and int2 is %d\n", int3, int4);

              	printf("\n\n");
	printf("hey '%.1f'\n", 0.25);
 ft_printf("hey '%.1f'\n", 0.25);


                	printf("\n\n");
	printf("hey '%.1Lf'\n", (long double)-0.05);
 ft_printf("hey '%.1Lf'\n", (long double)-0.05);

                 	printf("\n\n");
	printf("hey '%+.1f'\n", -0.12);
 ft_printf("hey '%+.1f'\n", -0.12);

  
                	printf("\n\n");
	printf("hey '% .1f'\n", 0.00);
 ft_printf("hey '% .1f'\n", 0.00);


              	printf("\n\n");
	printf("hey '%.1f'\n", 0.05);
 ft_printf("hey '%.1f'\n", 0.05);

              	printf("\n\n");
	printf("hey '%.1f'\n", 0.06);
 ft_printf("hey '%.1f'\n", 0.06);

                	printf("\n\n");
	printf("hey '%.1Lf'\n", (long double)0.05);
 ft_printf("hey '%.1Lf'\n", (long double)0.05);


               	printf("\n\n");
	printf("hey '%.1Lf'\n", 0.05l);
 ft_printf("hey '%.1Lf'\n", 0.05l);

printf("\n\n");
 long double testtest = 0.05;
 printf("hey test '%.30Lf'\n", testtest);
 printf("hey test '%.30Lf'\n", testtest * 10l);



long double testre = 0.05l;
	 printf("\n\n");
 printf("v '%.30Lf'\n", testre);
 printf("v '%.30Lf'\n", (long double)testre + 1.0);
 printf("v '%.30Lf'\n", (long double)testre * 1.0);
 printf("v '%.30Lf'\n", (long double)testre * (long double)10);
 printf("v '%.30Lf'\n", (testre / 1) * 10);
 printf("v '%.30Lf'\n", testre * 10);
 printf("v '%.30Lf'\n", (testre - 0.05) * 1000000);

 printf("\n\n");
 

}

/*

5.00000000000497379915 11
5.00000000000008881784 13
*/   