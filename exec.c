#include "pushswap.h"

void	simple(t_stk **stackA, t_stk **stackB, t_cnt *count, t_cfg *config)
{
	int	len;

	len = ft_lstlen(*stackA);
	if (len == 3)
		sort3(stackA, count, config);
	else if (len == 5)
		sort5(stackA, stackB, count, config);
	else
		insertion_sort(stackA, stackB, count, config);
}

void	adaptative(t_stk **stackA, t_stk **stackB, t_cnt *count, t_cfg *config)
{
	int	len;

	len = ft_lstlen(*stackA);
	if (len == 3)
		sort3(stackA, count, config);
	else if (len == 5)
		sort5(stackA, stackB, count, config);
	else if (len < 25)
		insertion_sort(stackA, stackB, count, config);
	else if (len < 100)
		chunk_sort(stackA, stackB, count, config);
	else
		radix(stackA, stackB, count, config);
}

char	*format_strategy(int strategy)
{
	char	*dst;

	if (strategy == 0)
		dst = "Adaptive / O(n√n)";
	if (strategy == 1)
		dst = "Simple / O(n2)";
	if (strategy == 2)
		dst = "Medium / O(n√n)";
	if (strategy == 3)
		dst = "Complex / O(n log n)";
	return (dst);
}

void	execute_sort(t_stk **a, t_stk **b, t_cfg *config, t_cnt *count)
{
	if (config->adaptative)
		adaptative(a, b, count, config);
	else if (config->strat == 1)
		simple(a, b, count, config);
	else if (config->strat == 2)
		chunk_sort(a, b, count, config);
	else if (config->strat == 3)
		radix(a, b, count, config);
}

void	print_benchmark(t_cnt count, t_cfg config, double disorder)
{
	ft_printf("[bench] disorder: %f%%\n", disorder);
	ft_printf("[bench] strategy: %s\n", format_strategy(config.strat));
	ft_printf("[bench] total_ops: %d\n", total_op(&count));
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		count.sa, count.sb, count.ss, count.pa, count.pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		count.ra, count.rb, count.rr, count.rra, count.rrb, count.rrr);
}
