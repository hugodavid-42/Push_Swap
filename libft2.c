#include "pushswap.h"

/*================== Libft1 Utils ==================*/

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

void	ft_putchar(char c, int *count)
{
	write(2, &c, 1);
	(*count)++;
}

void	ft_putnbr(int n, int *count)
{
	long long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putnbr (nbr / 10, count);
	ft_putchar (nbr % 10 + '0', count);
}

void	ft_putnbr_unsigned(unsigned int nbr, int *count)
{
	if (nbr > 9)
		ft_putnbr_unsigned (nbr / 10, count);
	ft_putchar (nbr % 10 + '0', count);
}

void	print_str(const char	*arg, int *count)
{
	int	i;

	i = 0;
	if (arg == NULL)
		return ;
	while (arg[i] != '\0')
	{
		ft_putchar(arg[i], count);
		i ++;
	}
}
