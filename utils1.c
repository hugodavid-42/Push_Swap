#include "pushswap.h"

/*=========== Utils algo ===============*/

int	find_max(t_stk *stackA)
{
	int	max;

	max = stackA->data;
	while (stackA)
	{
		if (stackA->data > max)
			max = stackA->data;
		stackA = stackA->next;
	}
	return (max);
}

int	find_min(t_stk *stackA)
{
	int	min;

	min = stackA->data;
	while (stackA)
	{
		if (stackA->data < min)
			min = stackA->data;
		stackA = stackA->next;
	}
	return (min);
}

int	locate_min(t_stk *stackA)
{
	int	min;
	int	i;

	min = find_min(stackA);
	i = 0;
	while (stackA)
	{
		if (stackA->data == min)
			return (i);
		i ++;
		stackA = stackA->next;
	}
	return (i);
}

/*============== Normalize =================*/

int	*build_array(t_stk *stackA)
{
	t_stk	*current;
	t_stk	*data_to_compare;
	int		i;
	int		index;
	int		*arr;

	data_to_compare = stackA;
	i = 0;
	arr = malloc(sizeof(int) * ft_lstlen(stackA));
	while (i < ft_lstlen(stackA))
	{
		index = 0;
		current = stackA;
		while (current)
		{
			if (data_to_compare->data > current->data)
				index ++;
			current = current->next;
		}
		arr[i] = index;
		data_to_compare->index = index;
		data_to_compare = data_to_compare->next;
		i ++;
	}
	return (arr);
}

/*================== Count move ==================*/

int	total_op(t_cnt *count)
{
	int	total;

	total = (count->pa + count->pb + count->ra
			+ count->rb + count->rr + count->rra + count->rrb
			+ count->rrr + count->sa + count->sb + count->ss);
	return (total);
}
