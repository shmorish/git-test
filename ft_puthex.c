#include "ft_printf.h"

int	ft_puthex(unsigned int hex)
{
	int	len;

	len = 0;
	if (hex >= 16)
	{
		len += ft_puthex(hex / 16);
		len += ft_puthex(hex % 16);
	}
	else
		len += ft_putchar("0123456789abcdef"[hex]);
	return (len);
}