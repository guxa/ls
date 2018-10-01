#include "libft.h"
#include <string.h>



int	main()
{
	// char *str1 = "%kabastada%%%P   %%%d %x%c %s%s  emin%\n";
	
	// int i;
	// int f;
	// i = b_printf(str1, -13, 100,'p', "test", "kontrola");
	// printf("\n i is %d\n", i);
	// b_printf(str1, -13, 100,'p', "test", "kontrola");
	// printf(str1, -13, 100,'p', "test", "kontrola");

	// i = b_printf("\n of X is %p", &str1);
	// printf("\n i is %d\n", i);
	
	// f = printf("\n of X is %p", &str1);
	// printf("\n F is %d\n", f);

	// char *str2 = NULL;
	// b_printf("what is this %s", str2);
	//ft_putstr(ft_itoa_base(32412122, 16));
	//ft_putstr("\n");
	char *str = "test";
	char *ptr = (char *)malloc(sizeof(char) * 10);
	
	ptr = strncpy(ptr, "dfadsdsa", 8);
	int num = 32412122;
	char ch;
	b_printf("test proba %s %o %x %s %p %d %i %u %o %s \n", "ABAS", 100, 100, str, &ch, num, num, num, num, ptr);
	//b_printf("test proba %s %o %x %s %p %d %i %u %x %s \n", "ABAS", 100, 100, str, &ch, num, num, num, num, ptr);
	printf("test proba %s %o %x %s %p %d %i %u %o %s \n", "ABAS", 100, 100, str, &ch, num, num, num, num, ptr);

	//b_printf("test proba %x %p %x", num, &ch, num);
	
	return 0;
}