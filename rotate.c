#include "pushswap.h"

/*================== ra && rb && rr ==================*/

static void	rotate(t_stk **s)
{
	t_stk	*first;
	t_stk	*last;

	first = *s;
	last = *s;
	if (!s || !*s || !(*s)->next)
		return ;
	while (last->next)
		last = last->next;
	*s = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stk **a, t_cnt *count, t_cfg *config)
{
	if (!a || !*a || !(*a)->next)
		return ;
	rotate(a);
	if (config->count_only == 0)
		write(1, "ra\n", 3);
	count->ra++;
}

void	rb(t_stk **b, t_cnt *count, t_cfg *config)
{
	if (!b || !*b || !(*b)->next)
		return ;
	rotate(b);
	if (config->count_only == 0)
		write(1, "rb\n", 3);
	count->rb++;
}

void	rr(t_stk **a, t_stk **b, t_cnt *count, t_cfg *config)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	rotate(a);
	rotate(b);
	if (config->count_only == 0)
		write(1, "rr\n", 3);
	count->rr++;
}
