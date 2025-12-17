#include "pushswap.h"

/*================== pa && pb ==================*/

void	pa(t_stk **stackA, t_stk **stackB, t_cnt *count, t_cfg *config)
{
	t_stk	*x;

	x = *stackB;
	if (!stackB || !*stackB)
		return ;
	*stackB = x->next;
	x->next = *stackA;
	*stackA = x;
	if (config->count_only == 0)
		write(1, "pa\n", 3);
	count->pa++;
}

void	pb(t_stk **stackA, t_stk **stackB, t_cnt *count, t_cfg *config)
{
	t_stk	*x;

	if (!stackA || !*stackA)
		return ;
	x = *stackA;
	*stackA = x->next;
	x->next = *stackB;
	*stackB = x;
	if (config->count_only == 0)
		write(1, "pb\n", 3);
	count->pb++;
}
