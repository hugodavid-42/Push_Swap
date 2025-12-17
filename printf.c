#include "pushswap.h"

int	my_putfloat(double nb, int *count)
{
	long long	nb_int;
	long long	virg;

	nb_int = (long long)nb;
	virg = (long long)((nb - nb_int) * 100 + 0.5);
	my_put_nbr((int)nb_int, count);
	ft_putchar('.', count);
	if (virg < 10)
		ft_putchar('0', count);
	my_put_nbr((int)virg, count);
	return (0);
}

void	convert_hex_low(unsigned int n, int *count)
{
	char	*scale;

	scale = "0123456789abcdef";
	if (n >= 16)
		convert_hex_low(n / 16, count);
	ft_putchar(scale[n % 16], count);
}

void	convert_hex_cap(unsigned int n, int *count)
{
	char	*scale;

	scale = "0123456789ABCDEF";
	if (n >= 16)
		convert_hex_cap(n / 16, count);
	ft_putchar(scale[n % 16], count);
}

void	find_args(const char *str, int i, va_list ap, int *count)
{
	if (str[i] == 'c')
		ft_putchar((char)va_arg(ap, int), count);
	else if (str[i] == 's')
		print_str(va_arg(ap, char *), count);
	else if (str[i] == 'd' || str[i] == 'i')
		ft_putnbr(va_arg(ap, int), count);
	else if (str[i] == 'u')
		ft_putnbr_unsigned(va_arg(ap, unsigned int), count);
	else if (str[i] == 'x')
		convert_hex_low(va_arg(ap, unsigned int), count);
	else if (str[i] == 'X')
		convert_hex_cap(va_arg(ap, unsigned int), count);
	else if (str[i] == 'p')
	{
		print_str("0x", count);
		convert_hex_low((unsigned int)va_arg(ap, unsigned int), count);
	}
	else if (str[i] == 'f')
		my_putfloat(va_arg(ap, double), count);
	else if (str[i] == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ft_putchar(str[i], &count);
		else
		{
			i++;
			find_args(str, i, ap, &count);
		}
		i++;
	}
	va_end(ap);
	return (count);
}
