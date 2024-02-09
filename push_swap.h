#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				data;
	struct  s_list	*next;
}	t_list;

int		my_is_digit(char *str);
int		check_is_number(char **av);
long	ft_atoi(char *str);
int		is_double(int ac, char **av);
void	swap(int *a, int *b);
void	bubble_sort(int *arr, int size);
int		check_doubles(int *arr, int size);
int		countword(const char *s, char c);
char	*ft_strndup(const char *src, int n);
void	ft_free(char **ptr, int i);
char	**ft_help(const char *s, char c, int len, char **final);
char	**ft_split(const char *s, char c);
t_list	*lstnew(int num);
t_list	*lstlast(t_list *lst);
void	lstadd_back(t_list **lst, t_list *new);
void	lstadd_front(t_list **lst, t_list *new);
int		lstsize(t_list	*head);

#endif