#include "pushswap.h"

void	init_count(t_cnt *count)
{
	count->sa = 0;
	count->sb = 0;
	count->ss = 0;
	count->pa = 0;
	count->pb = 0;
	count->ra = 0;
	count->rb = 0;
	count->rr = 0;
	count->rra = 0;
	count->rrb = 0;
	count->rrr = 0;
}

void	init_config(t_cfg *conf)
{
	conf->strat = 0;
	conf->bench = 0;
	conf->adaptative = 1;
	conf->count_only = 0;
}

int	parse_options(int argc, char **argv, t_cfg *config)
{
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (select_option(argv[i], config) < 0)
			return (-1);
		i++;
	}
	return (i);
}

int	parse_input(int argc, char **argv, t_stk **a, t_cfg *config)
{
	int	start_idx;

	if (argc < 2)
		return (0);
	start_idx = parse_options(argc, argv, config);
	if (start_idx == -1)
		return (0);
	if (start_idx >= argc)
		return (0);
	if (!add_numbers(a, argv, start_idx, argc))
	{
		write(2, "Error\n", 6);
		free_stack(a);
		return (0);
	}
	if (has_duplicates(*a))
	{
		write(2, "Error\n", 6);
		free_stack(a);
		return (0);
	}
	return (1);
}
