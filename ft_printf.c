#include <libc.h>

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = sort_format(format, ap);
	va_end(ap);
	return (ret);
}