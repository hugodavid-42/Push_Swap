#include "pushswap.h"

int	size_chunk(t_stk *a)
{
	int	len;
	int	chunks;

	len = ft_lstlen(a);
	if (len <= 10)
		return (len);
	chunks = len / 10;
	if (len % 10 != 0)
		chunks++;
	return (len / chunks);
}

int	is_in_range(t_stk *stack, t_range *rng)
{
	return (stack->index >= rng->min && stack->index < rng->max);
}

int	steps_to_reach(t_stk *a, t_range *rng)
{
	int		i;
	t_stk	*tmp;

	i = 0;
	tmp = a;
	while (tmp && !is_in_range(tmp, rng))
	{
		i++;
		tmp = tmp->next;
	}
	if (!tmp)
		return (-1);
	return (i);
}

int	rotate_to_target(t_stk **a, int pos, t_cnt *c, t_cfg *cfg)
{
	int	len;
	int	move;
	int	steps;

	move = 0;
	len = ft_lstlen(*a);
	if (pos <= len / 2)
	{
		while (pos-- > 0)
		{
			ra(a, c, cfg);
			move++;
		}
	}
	else
	{
		steps = len - pos;
		while (steps-- > 0)
		{
			rra(a, c, cfg);
			move++;
		}
	}
	return (move);
}

int	find_closest(t_stk **a, t_range *rng, t_cnt *c, t_cfg *cfg)
{
	int	pos;

	if (!a || !*a)
		return (-1);
	pos = steps_to_reach(*a, rng);
	if (pos < 0)
		return (-1);
	return (rotate_to_target(a, pos, c, cfg));
}
