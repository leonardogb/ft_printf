#include <stdio.h>
#include <locale.h>

int	ft_printf(char *format, ...);

int	main(void)
{
	setlocale(LC_ALL, "");
	printf("%C\n", 0x7ff);
	ft_printf("%C\n", 0xD7ff);
}
