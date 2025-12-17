#include "pushswap.h"

int	is_valid_int(char *s)
{
	long	n;

	n = ft_atol(s);
	if (n > 2147483647 || n < -2147483648)
		return (0);
	return (1);
}

int	add_numbers(t_stk **a, char **argv, int start_index, int argc)
{
	int		i;
	long	val;
	t_stk	*new;
	char	**nums;

	i = start_index;
	if (argc - start_index == 1)
	{
		nums = ft_split(argv[start_index], ' ');
		i = 0;
	}
	else
		nums = argv;
	while (nums[i])
	{
		if (!ft_isnumber(nums[i]) || !is_valid_int(nums[i]))
			return (0);
		val = ft_atol(nums[i]);
		new = ft_lstnew((int)val);
		if (!new)
			return (0);
		ft_lstadd_back(a, new);
		i++;
	}
	return (1);
}

int	has_duplicates(t_stk *a)
{
	t_stk	*cur;
	t_stk	*cmp;

	cur = a;
	while (cur)
	{
		cmp = cur->next;
		while (cmp)
		{
			if (cmp->data == cur->data)
				return (1);
			cmp = cmp->next;
		}
		cur = cur->next;
	}
	return (0);
}
