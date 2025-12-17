#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct stack
{
	struct stack	*next;
	int				data;
	int				index;
}	t_stk;

typedef struct count
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_cnt;

typedef struct s_cfg
{
	int	strat;
	int	bench;
	int	adaptative;
	int	count_only;
}	t_cfg;

typedef struct s_range
{
	int	min;
	int	max;
}	t_range;

/* Movement ( push.c / reverse_rotate.c / rotate.c / swap.c ) */

void	sa(t_stk **a, t_cnt *count, t_cfg *config);
void	sb(t_stk **b, t_cnt *count, t_cfg *config);
void	ss(t_stk **stackA, t_stk **stackB, t_cnt *count, t_cfg *config);
void	pa(t_stk **stackA, t_stk **stackB, t_cnt *count, t_cfg *config);
void	pb(t_stk **stackA, t_stk **stackB, t_cnt *count, t_cfg *config);
void	ra(t_stk **a, t_cnt *count, t_cfg *config);
void	rb(t_stk **b, t_cnt *count, t_cfg *cfg);
void	rr(t_stk **stackA, t_stk **stackB, t_cnt *count, t_cfg *config);
void	rra(t_stk **a, t_cnt *count, t_cfg *config);
void	rrb(t_stk **b, t_cnt *count, t_cfg *config);
void	rrr(t_stk **stackA, t_stk **stackB, t_cnt *count, t_cfg *config);

/* Utils ( utils1.c / utils2.c / utils3.c ) */
char	*my_revstr(char *str);
void	my_put_unnbr(unsigned int nb, int *count);
void	my_put_nbr(int nb, int *count);
int		my_compute_power_rec(int nb, int p);
int		my_nbrlen(int n);
int		find_max(t_stk *stackA);
int		find_min(t_stk *stackA);
int		locate_min(t_stk *stackA);
int		*build_array(t_stk *stackA);
int		total_op(t_cnt *count);

float	compute_disorder(t_stk *head);
t_stk	*fill_stacka(int argc, char *argv[]);
int		ft_isnumber(char *str);
int		has_dup(int argc, char *argv[]);
int		isargv_ok(int argc, char *argv[]);

/* Execution et print ( Exec.c / printf.c ) */
void	simple(t_stk **stackA, t_stk **stackB, t_cnt *count, t_cfg *config);
void	adaptative(t_stk **stackA, t_stk **stackB, t_cnt *count, t_cfg *config);
char	*formatStrategy(int strategy);
void	execute_sort(t_stk **a, t_stk **b, t_cfg *config, t_cnt *count);
void	print_benchmark(t_cnt count, t_cfg config, double disorder);
int		ft_printf(const char *str, ...);

/* Sorting algorithms ( easy_algos.c / medium_algo.c / complex_algo.c ) */
void	sort3(t_stk **stackA, t_cnt *count, t_cfg *config);
void	sort5(t_stk **stackA, t_stk **stackB, t_cnt *count, t_cfg *config);
void	insertion_sort(t_stk **stackA, t_stk **stackB, t_cnt *count, t_cfg *c);
void	chunk_sort(t_stk **stackA, t_stk **stackB, t_cnt *count, t_cfg *config);
void	radix(t_stk **stackA, t_stk **stackB, t_cnt *count, t_cfg *config);

/* Utils chunk sort */
int		size_chunk(t_stk *a);
int		is_in_range(t_stk *stack, t_range *rng);
int		steps_to_reach(t_stk *a, t_range *rng);
int		rotate_to_target(t_stk **a, int pos, t_cnt *c, t_cfg *cfg);
int		find_closest(t_stk **a, t_range *rng, t_cnt *c, t_cfg *cfg);

/* Libft ( libft1.c / libft2.c / libft3.c) */
int		ft_lstlen(t_stk *head);
t_stk	*ft_lstlast(t_stk *lst);
t_stk	*ft_lstnew(int nbr);
void	ft_lstadd_back(t_stk **lst, t_stk *new);
void	free_stack(t_stk **t_stk);
void	ft_putchar(char c, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putnbr_unsigned(unsigned int nbr, int *count);
void	print_str(const char	*arg, int *count);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
long	ft_atol(char *str);
int		ft_atoi(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* Others ( options.c / split.c / check_value.c / parsing.c)*/

void	init_config(t_cfg *conf);
int		parse_input(int argc, char **argv, t_stk **a, t_cfg *config);
int		select_option(char *argv, t_cfg *conf);
int		add_numbers(t_stk **a, char **nums, int start_index, int argc);
int		has_duplicates(t_stk *a);
char	**ft_split(char const *s, char c);
void	init_count(t_cnt *count);

#endif
