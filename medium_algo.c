#include "pushswap.h"

static void	update_range(t_range *rng, int chunk)
{
	rng->min = rng->max;
	rng->max = rng->min + chunk;
}

void	pusha(t_stk **a, t_stk **b, t_cnt *c, t_cfg *cfg)
{
	int		chunk;
	int		i;
	t_range	rng;

	chunk = size_chunk(*a);
	rng.min = 0;
	rng.max = chunk;
	while (*a)
	{
		i = 0;
		while (i < chunk && *a)
		{
			if (find_closest(a, &rng, c, cfg) < 0)
				break ;
			if ((*a)->index >= rng.min && (*a)->index < rng.max)
			{
				pb(a, b, c, cfg);
				i++;
			}
		}
		update_range(&rng, chunk);
	}
}

int	pos_of_max(t_stk *b, int max)
{
	int		i;
	t_stk	*tmp;

	i = 0;
	tmp = b;
	while (tmp)
	{
		if (tmp->index == max)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

void	push_backb(t_stk **a, t_stk **b, t_cnt *c, t_cfg *cfg)
{
	int	max;
	int	len;

	while (*b)
	{
		len = ft_lstlen(*b);
		max = len - 1;
		if ((*b)->index == max)
			pa(a, b, c, cfg);
		else if (pos_of_max(*b, max) <= max / 2)
			rb(b, c, cfg);
		else
			rrb(b, c, cfg);
	}
}

void	chunk_sort(t_stk **a, t_stk **b, t_cnt *c, t_cfg *cfg)
{
	if (!(*a) || !(*a)->next)
		return ;
	build_array(*a);
	pusha(a, b, c, cfg);
	push_backb(a, b, c, cfg);
}
