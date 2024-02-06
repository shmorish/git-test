#include "ft_printf.h"

static size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_putstr(char *str)
{
	return (write(STDOUT_FILENO, str, ft_strlen(str)));
}
