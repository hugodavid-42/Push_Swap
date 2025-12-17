#include "pushswap.h"

/*============= Radix ==============*/

int	power2(int bit)
{
	int	result;

	result = 1;
	while (bit > 0)
	{
		result *= 2;
		bit--;
	}
	return (result);
}

int	get_bit(int value, int bit)
{
	int	divisor;

	divisor = power2(bit);
	return ((value / divisor) % 2);
}

int	count_bits(int max)
{
	int	bits;

	bits = 0;
	while (max > 0)
	{
		max /= 2;
		bits++;
	}
	return (bits);
}

void	radix(t_stk **stackA, t_stk **stackB, t_cnt *count, t_cfg *conf)
{
	int	bit;
	int	i;
	int	initial_size;
	int	value;

	build_array(*stackA);
	bit = 0;
	while (bit < count_bits(ft_lstlen(*stackA)))
	{
		i = 0;
		initial_size = ft_lstlen(*stackA);
		while (i < initial_size)
		{
			value = (*stackA)->index;
			if (get_bit(value, bit) == 0)
				pb(stackA, stackB, count, conf);
			else
				ra(stackA, count, conf);
			i++;
		}
		while (*stackB)
			pa(stackA, stackB, count, conf);
		bit++;
	}
}
