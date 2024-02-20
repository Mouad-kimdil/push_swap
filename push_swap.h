#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				idx;
	struct  s_list	*next;
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
void	initialize_stack(t_list *stack, char **av);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*join_args(char **av);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		swap_satck(t_list *stack);
int		push_stack(t_list *stack_from, t_list *stack_to);
int		push_stack(t_list *stack_from, t_list *stack_to);
int		sa(t_list *stack_a);
int		sb(t_list *stack_b);
int		ss(t_list *stack_a, t_list *stack_b);
int		pa(t_list *stack_a, t_list *stack_b);
int		pb(t_list *stack_b, t_list *stack_a);

#endif