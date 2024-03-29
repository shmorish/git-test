#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		result_length;
	va_list	args;

	i = 0;
	result_length = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			result_length += sort_format(&args, str[i + 1]);
			i++;
		}
		else
			result_length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (result_length);
}



int	sort_format(va_list *data, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(*data, int));
	if (format == 's')
		len += ft_putstr(va_arg(*data, char *));
	if (format == 'd')
		len += ft_putnbr(va_arg(*data, int));
	if (format == 'i')
		len += ft_putnbr(va_arg(*data, int));
	if (format == 'x')
		len += ft_puthex(va_arg(*data, unsigned int));
	if (format == '%')
		len += write(STDOUT_FILENO, "%", 1);
	return (len);
}
