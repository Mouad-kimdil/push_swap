/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:01:33 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/07 16:54:38 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 33
# endif

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
t_list	*initialize_stack(int ac, char **av);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*join_args(char **av);
void	ft_putendl_fd(char *s, int fd);
int		swap_satck(t_list **stack);
int		push_stack(t_list **stack_from, t_list **stack_to);
int		rotate_stack(t_list **stack);
int		reverse_rotate(t_list **stack);
void	sort_three(t_list **stack);
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
void	sort(t_list **stack_a, t_list **stack_b);
void	push_all_save_three(t_list **stack_a, t_list **stack_b);
void	print_stack(t_list *stack, int state);
void	get_target_position(t_list **a, t_list **b);
int		calculate_target(t_list **a, int b_idx, int target_idx, int target_pos);
void	get_position(t_list **stack);
void	calculate_costs(t_list **stack_a, t_list **stack_b);
void	do_cheapest_move(t_list **stack_a, t_list **stack_b);
void	do_move(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b);
void	rotate_b(t_list **b, int *cost);
void	rotate_a(t_list **a, int *cost);
void	rotate_both(t_list **a, t_list **b, int *cost_a, int *cost_b);
void	reverse_rotate_both(t_list **a, t_list **b, int *cost_a, int *cost_b);
int		ft_abs(int n);
void	assign_index(t_list *stack_a, int stack_size);
t_list	*get_stack_bottom(t_list *stack);
void	stack_add_bottom(t_list **stack, t_list *new);
int		last_check_sort(t_list *stack);
void	shift_stack(t_list **stack_a);
int		get_lowest_index_position(t_list **stack);
void	free_stack(t_list **stack);
char	*ft_strrchr(char *str, int c);
char	*get_next_line(int fd);
char	*ft_next_line(char *buffer);
char	*ft_read_file(int fd, char *res);
char	*ft_get_line(char *buffer);
void	*ft_calloc(size_t count, size_t size);
char	*ft_join(char *buffer, char *buf);
int		ft_strncmp(char *s1, char *s2, int len);
int		checker_bonus(t_list **stack_a, t_list **stack_b);
void	do_move_bonus(t_list **stack_a, t_list **stack_b, char *tmp);
int		do_pa(t_list **stack_a, t_list **stack_b);
int		do_pb(t_list **stack_a, t_list **stack_b);
int		do_rra(t_list **stack_a);
int		do_rrb(t_list **stack_b);
int		do_rrr(t_list **stack_a, t_list **stack_b);
int		do_ra(t_list **stack_a);
int		do_rb(t_list **stack_b);
int		do_rr(t_list **stack_a, t_list **stack_b);
int		do_sa(t_list **stack_a);
int		do_sb(t_list **stack_b);
int		do_ss(t_list **stack_a, t_list **stack_b);

#endif