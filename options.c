#include "pushswap.h"

int	is_option(char *argv)
{
	if (!ft_strncmp(argv, "--adaptative", 13))
		return (0);
	else if (!ft_strncmp(argv, "--simple", 9))
		return (1);
	else if (!ft_strncmp(argv, "--medium", 9))
		return (2);
	else if (!ft_strncmp(argv, "--complex", 10))
		return (3);
	else if (!ft_strncmp(argv, "--bench", 12))
		return (5);
	else if (!ft_strncmp(argv, "--count_only", 13))
		return (6);
	else
		return (-1);
}

int	select_option(char *argv, t_cfg *config)
{
	int	tmp;

	tmp = is_option(argv);
	if (tmp < 0)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	else if (tmp == 5)
		config->bench = 1;
	else if (tmp == 0)
		config->adaptative = 1;
	else if (tmp == 6)
		config->count_only = 1;
	else
	{
		config->strat = tmp;
		config->adaptative = 0;
	}
	return (1);
}
