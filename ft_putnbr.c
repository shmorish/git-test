#include <unistd.h>

static int	ft_putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

int	ft_putnbr(int nb)
{
	long	lnb;
	int		len;

	len = 0;
	lnb = nb;
	if (lnb < 0)
	{
		lnb *= -1;
		len += ft_putchar('-');
	}
	if (lnb >= 10)
	{
		len += ft_putnbr(lnb / 10);
		len += ft_putnbr(lnb % 10);
	}
	else
		len += ft_putchar(lnb + '0');
	return (len);
}

/* check if ft_putnbr(); works correctly */
// int main(void)
// {
// 	__builtin_printf("[%d]", ft_putnbr(100));
// }
