#include <libc.h>

int	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
	return (1);
}