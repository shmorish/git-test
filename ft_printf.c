#include <libc.h>

int	ft_printf(const char *str, ...)
{
	i = 0;
	result_length = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			result_length += ft_format(&args, str[i + 1]);
			i++;
		}
		else
			result_length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (result_length);
}

static int	ft_putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

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

int	sort_format(const char format, va_list *data)
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

