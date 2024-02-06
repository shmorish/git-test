#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <inttypes.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	sort_format(va_list *data, const char format);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);

#endif
