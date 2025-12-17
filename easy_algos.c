#include "pushswap.h"
#include <stdio.h>

/*=========== 3 numbers =================*/
void	sort3(t_stk **stackA, t_cnt *count, t_cfg *config)
{
	int	a;
	int	b;
	int	c;

	a = (*stackA)->data;
	b = (*stackA)->next->data;
	c = (*stackA)->next->next->data;
	if (a > b && b < c && a < c)
		sa(stackA, count, config);
	else if (a > b && b > c && a > c)
	{
		sa(stackA, count, config);
		rra(stackA, count, config);
	}
	else if (a > b && b < c && a > c)
		ra(stackA, count, config);
	else if (a < b && b > c && a < c)
	{
		sa(stackA, count, config);
		ra(stackA, count, config);
	}
	else if (a < b && b > c && a > c)
		rra(stackA, count, config);
}

/*=========== 5 numbers =================*/
void	sort5(t_stk **stackA, t_stk **stackB, t_cnt *count, t_cfg *c)
{
	int	min;

	min = find_min(*stackA);
	while ((*stackA)->data != min)
		ra(stackA, count, c);
	pb(stackA, stackB, count, c);
	min = find_min(*stackA);
	while ((*stackA)->data != min)
		ra(stackA, count, c);
	pb(stackA, stackB, count, c);
	sort3(stackA, count, c);
	if ((*stackB)->data < (*stackB)->next->data)
		sb(stackB, count, c);
	while (*stackB)
		pa(stackA, stackB, count, c);
	while ((*stackA)->data != find_min(*stackA))
		ra(stackA, count, c);
}

/*=========== more than 5 numbers =================*/
void	insertion_sort(t_stk **stackA, t_stk **stackB, t_cnt *count, t_cfg *c)
{
	int	len;
	int	pos;
	int	k;

	while (*stackA)
	{
		len = ft_lstlen(*stackA);
		pos = locate_min(*stackA);
		if (pos <= len / 2)
		{
			while (pos-- > 0)
				ra(stackA, count, c);
		}
		else
		{
			k = len - pos;
			while (k-- > 0)
				rra(stackA, count, c);
		}
		pb(stackA, stackB, count, c);
	}
	while (*stackB)
		pa(stackA, stackB, count, c);
}
