#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}