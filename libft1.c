#include "pushswap.h"

/*================== Libft1 linked list ==================*/

int	ft_lstlen(t_stk *head)
{
	int	count;

	count = 0;
	while (head)
	{
		head = head->next;
		count ++;
	}
	return (count);
}

t_stk	*ft_lstlast(t_stk *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stk	*ft_lstnew(int nbr)
{
	t_stk	*new;

	new = malloc(sizeof(t_stk));
	if (!new)
		return (NULL);
	new->data = nbr;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_stk **lst, t_stk *new)
{
	t_stk	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	free_stack(t_stk **lst)
{
	t_stk	*cur;
	t_stk	*next;

	cur = *lst;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*lst = NULL;
}
