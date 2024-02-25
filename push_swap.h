#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				idx;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}	t_list;

int		checker(int ac, char **av);
int		my_is_digit(char *str);
int		check_is_number(char **str);
long	ft_atoi(char *str);
int		is_double(int ac, char **av);
int		*fill_arr(char **res, int *arr, int *idx);
int		check_doubles(int *arr, int size);
void	swap(int *a, int *b);
void	bubble_sort(int *arr, int size);
int		alloc_len(char **av);
int		countword(char *s, char c);
char	*ft_strndup(char *src, int n);
void	ft_free(char **ptr, int i);
char	**ft_help(char *s, char c, int len, char **final);
char	**ft_split(char *s, char c);
t_list	*lstnew(int num);
t_list	*lstlast(t_list *lst);
void	lstadd_back(t_list **lst, t_list *new);
void	lstadd_front(t_list **lst, t_list *new);
int		lstsize(t_list	*head);
void	free_arr(char **arr);
int		check_is_sorted(char **av, int size);
int		is_sorted(int *arr, int size);
void	initialize_stack(t_list **stack, char **av);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*join_args(char **av);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		swap_satck(t_list **stack);
int		push_stack(t_list **stack_from, t_list **stack_to);
int		rotate_stack(t_list **stack);
int		reverse_rotate(t_list **stack);
int		check_min(t_list **stack);
void	sort_three(t_list **stack);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_b, t_list **stack_a);
int		pb(t_list **stack_a, t_list **stack_b);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);
void	print_stack(t_list *stack, int state);
void	sort(t_list **stack_a, t_list **stack_b);
void	handle_multiple_args(t_list **stack, char **av, int argc, int *arr);
void	handle_single_arg(t_list **stack, char **av, char **numbers, int *arr);
void	indexing(t_list **stack, char **av, int argc);
void	indexing_help(int *arr, t_list **stack, int count);
void	cost_sort(t_list **stack_a, t_list **stack_b);
int		get_min(t_list **stack);

#endif