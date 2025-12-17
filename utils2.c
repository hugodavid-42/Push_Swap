#include "pushswap.h"

char	*my_revstr(char *str)
{
	int		start;
	int		end;
	char	c;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		c = str[start];
		str[start] = str[end];
		str[end] = c;
		start++;
		end--;
	}
	return (str);
}

void	my_put_unnbr(unsigned int nb, int *count)
{
	char	result[11];
	int		end;
	int		i;

	i = 0;
	while (nb >= 10)
	{
		end = nb % 10;
		result[i] = end + '0';
		nb = nb / 10;
		i++;
	}
	end = nb + '0';
	result[i] = end;
	i++;
	result[i] = '\0';
	my_revstr(result);
	print_str(result, count);
}

void	my_put_nbr(int nb, int *count)
{
	char	result[11];
	int		end;
	int		i;

	if (nb < 0)
	{
		ft_putchar('-', count);
		my_put_unnbr(nb * -1, count);
	}
	else
	{
		i = 0;
		while (nb >= 10)
		{
			end = nb % 10;
			result[i] = end + '0';
			nb = nb / 10;
			i++;
		}
		end = nb + '0';
		result[i] = end;
		i++;
		my_revstr(result);
		print_str(result, count);
	}
}

int	my_compute_power_rec(int nb, int p)
{
	if (p == 0)
		return (1);
	else if (p < 0)
		return (0);
	else
		return (nb * my_compute_power_rec(nb, p - 1));
}

int	my_nbrlen(int n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
