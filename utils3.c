#include "pushswap.h"

/*================ Compute disorder ===============*/

float	compute_disorder(t_stk *head)
{
	t_stk	*current;
	t_stk	*next;
	float	mistake;
	float	total_pairs;

	current = head;
	mistake = 0;
	total_pairs = 0;
	while (current->next)
	{
		next = current->next;
		while (next)
		{
			if (current->data > next->data)
			{
				mistake ++;
				break ;
			}
			next = next->next;
		}
		current = current->next;
		total_pairs ++;
	}
	if (total_pairs == 0)
		return (0);
	return (mistake / total_pairs);
}

/*============ Init stack ====================*/

t_stk	*fill_stacka(int argc, char *argv[])
{
	int		i;
	t_stk	*stack_a;
	t_stk	*new;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		if (!new)
		{
			free_stack(&stack_a);
			write(2, "Error", 6);
			return (NULL);
		}
		ft_lstadd_back(&stack_a, new);
		i++;
	}
	return (stack_a);
}

/*============ Check args ===================*/

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	has_dup(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	isargv_ok(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	if (has_dup(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
