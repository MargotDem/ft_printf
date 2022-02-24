#include "tests.h"

void test_ints(void)
{
	int ret1;
	int ret2;
		int ret3;
	int ret4;
	int ret5;
	int ret6;

	ret1 = printf("rl: '%d'\n", -358);
	ret2 = ft_printf("ft: '%d'\n", -358);
	printf("ret rl: %d, ret ft: %d\n", ret1, ret2);
	printf("\n");

	ret3 = printf("rl: '%.d'\n", -358);
	ret4 = ft_printf("ft: '%.d'\n", -358);
	printf("ret rl: %d, ret ft: %d\n", ret3, ret4);
	printf("\n");

	ret1 = printf("rl: '%.4d'\n", -358);
	ret2 = ft_printf("ft: '%.4d'\n", -358);
	printf("ret rl: %d, ret ft: %d\n", ret1, ret2);
	printf("\n");

	ret1 = printf("rl: '%-10.6d'\n", -358);
	ret2 = ft_printf("ft: '%-10.6d'\n", -358);
	printf("ret rl: %d, ret ft: %d\n", ret1, ret2);
	printf("\n");

	ret1 = printf("rl: '%010.6d'\n", -358);
	ret2 = ft_printf("ft: '%010.6d'\n", -358);
	printf("ret rl: %d, ret ft: %d\n", ret1, ret2);
	printf("\n");

	ret1 = printf("rl: '%010d'\n", -358);
	ret2 = ft_printf("ft: '%010d'\n", -358);
	printf("ret rl: %d, ret ft: %d\n", ret1, ret2);
	printf("\n");

	ret1 = printf("rl: '%10d'\n", -358);
	ret2 = ft_printf("ft: '%10d'\n", -358);
	printf("ret rl: %d, ret ft: %d\n", ret1, ret2);
	printf("\n");

	ret1 = printf("rl: '%.6d'\n", -358);
	ret2 = ft_printf("ft: '%.6d'\n", -358);
	printf("ret rl: %d, ret ft: %d\n", ret1, ret2);
	printf("\n");

	ret1 = printf("rl: '%0.6d'\n", -358);
	ret2 = ft_printf("ft: '%0.6d'\n", -358);
	printf("ret rl: %d, ret ft: %d\n", ret1, ret2);
	printf("\n");

	ret1 = printf("rl: '%09.2d'\n", -358);
	ret2 = ft_printf("ft: '%09.2d'\n", -358);
	printf("ret rl: %d, ret ft: %d\n", ret1, ret2);
	printf("\n");

	ret1 = printf("rl: '%09d'\n", -358);
	ret2 = ft_printf("ft: '%09d'\n", -358);
	printf("ret rl: %d, ret ft: %d\n", ret1, ret2);
	printf("\n");

	ret1 = printf("rl: '%9d'\n", -358);
	ret2 = ft_printf("ft: '%9d'\n", -358);
	printf("ret rl: %d, ret ft: %d\n", ret1, ret2);
	printf("\n");

	ret1 = printf("rl: '%s'\n", "test");
	ret2 = ft_printf("ft: '%s'\n", "test");
	printf("ret rl: %d, ret ft: %d\n", ret1, ret2);
	printf("\n");

	ret5 = printf("rl: '%-5%'\n");
	ret6 = ft_printf("ft: '%-5%'\n");
	printf("the ret is %d\n", ret5);
	printf("the ret is %d\n", ret6);
}