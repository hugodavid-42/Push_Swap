#include "pushswap.h"

/*================== sa && sb ==================*/

static void	swap(t_stk **s)
{
	t_stk	*next;
	int		temp;

	if (!s || !*s || !(*s)->next)
		return ;
	next = (*s)->next;
	temp = (*s)->data;
	(*s)->data = next->data;
	next->data = temp;
}

void	sa(t_stk **a, t_cnt *count, t_cfg *config)
{
	if (!a || !*a || !(*a)->next)
		return ;
	swap(a);
	if (config->count_only == 0)
		write(1, "sa\n", 3);
	count->sa++;
}

void	sb(t_stk **b, t_cnt *count, t_cfg *config)
{
	if (!b || !*b || !(*b)->next)
		return ;
	swap(b);
	if (config->count_only == 0)
		write(1, "sb\n", 3);
	count->sb++;
}

void	ss(t_stk **a, t_stk **b, t_cnt *count, t_cfg *config)
{
	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	swap(a);
	swap(b);
	if (config->count_only == 0)
		write(1, "ss\n", 3);
	count->ss++;
}
