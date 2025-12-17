#include "pushswap.h"

/*============= rra & rrb && rrr ===============*/

static void	rev_rotate(t_stk **s)
{
	t_stk	*prev;
	t_stk	*last;

	prev = NULL;
	last = *s;
	if (!s || !*s || !(*s)->next)
		return ;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *s;
	*s = last;
}

void	rra(t_stk **a, t_cnt *count, t_cfg *config)
{
	if (!a || !*a || !(*a)->next)
		return ;
	rev_rotate(a);
	if (config->count_only == 0)
		write(1, "rra\n", 4);
	count->rra++;
}

void	rrb(t_stk **b, t_cnt *count, t_cfg *config)
{
	if (!b || !*b || !(*b)->next)
		return ;
	rev_rotate(b);
	if (config->count_only == 0)
		write(1, "rrb\n", 4);
	count->rrb++;
}

void	rrr(t_stk **a, t_stk **b, t_cnt *count, t_cfg *config)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	rev_rotate(a);
	rev_rotate(b);
	if (config->count_only == 0)
		write(1, "rrr\n", 4);
	count->rrr++;
}
