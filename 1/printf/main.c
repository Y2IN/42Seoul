#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("%d", -1);
	//ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	/*printf("%c \n", 'a');
	printf("%s \n", "abc");
	printf("%p \n", (void *)42);
	printf("%d %i \n", 42, 42);
	printf("%u \n", 42);
	printf("%x %X \n", 42, 42);
	printf("%% \n\n");

	ft_printf("%c \n", 'a');
	ft_printf("%s \n", "abc");
	ft_printf("%p \n", (void *)42);
	ft_printf("%d %i \n", 42, 42);
	ft_printf("%u \n", 42);
	ft_printf("%x %X \n", 42, 42);
	ft_printf("%% \n");*/

	return 0;
}