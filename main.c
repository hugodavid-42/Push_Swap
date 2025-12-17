#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stk	*a;
	t_stk	*b;
	t_cnt	count;
	t_cfg	config;
	double	disorder;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	init_config(&config);
	init_count(&count);
	if (!parse_input(argc, argv, &a, &config))
		return (1);
	disorder = compute_disorder(a) * 100;
	if (!disorder)
		return (free_stack(&a), 0);
	execute_sort(&a, &b, &config, &count);
	if (config.bench)
		print_benchmark(count, config, disorder);
	if (config.count_only == 1)
		ft_printf("%d\n", total_op(&count));
	return (free_stack(&a), free_stack(&b), 0);
}
