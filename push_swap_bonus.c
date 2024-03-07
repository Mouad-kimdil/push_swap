/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:09:14 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/07 20:22:33 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_move_bonus(t_list **stack_a, t_list **stack_b, char *tmp)
{
	if (ft_strncmp(tmp, "pa", 2) == 0)
		do_pa(stack_a, stack_b);
	else if (ft_strncmp(tmp, "pb", 2) == 0)
		do_pb(stack_a, stack_b);
	else if (ft_strncmp(tmp, "rra", 3) == 0)
		do_rra(stack_a);
	else if (ft_strncmp(tmp, "rrb", 3) == 0)
		do_rrb(stack_b);
	else if (ft_strncmp(tmp, "rrr", 3) == 0)
		do_rrr(stack_a, stack_b);
	else if (ft_strncmp(tmp, "ra", 2) == 0)
		do_ra(stack_a);
	else if (ft_strncmp(tmp, "rb", 2) == 0)
		do_rb(stack_b);
	else if (ft_strncmp(tmp, "rr", 2) == 0)
		do_rr(stack_a, stack_b);
	else if (ft_strncmp(tmp, "sa", 2) == 0)
		do_sa(stack_a);
	else if (ft_strncmp(tmp, "sb", 2) == 0)
		do_sb(stack_b);
	else
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
}

int	checker_bonus(t_list **stack_a, t_list **stack_b)
{
	char	*tmp;

	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			break ;
		do_move_bonus(stack_a, stack_b, tmp);
		free(tmp);
	}
	free(tmp);
	if (last_check_sort(*stack_a) && !*stack_b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return (0);
}

int	do_ss(t_list **stack_a, t_list **stack_b)
{
	if (lstsize(*stack_a) < 2 || lstsize(*stack_b) < 2)
		return (1);
	if (swap_satck(stack_a) || swap_satck(stack_b))
		return (1);
	return (0);
}

int	parsing_bonus(int ac, char **av)
{
	char	**str;
	int		i;

	i = 1;
	while (av[i])
	{
		if (!av[i][0])
			return (ft_putendl_fd("Error", 2), 0);
		str = ft_split(av[i], ' ');
		if (!*str)
			return (ft_putendl_fd("Error", 2), 0);
		if (!check_is_number(str))
			return (free_arr(str), ft_putendl_fd("Error", 2), 0);
		free_arr(str);
		i++;
	}
	if (!is_double(ac, av))
		return (ft_putendl_fd("Error", 2), 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac < 2 || !parsing_bonus(ac, av))
		return (0);
	stack_b = NULL;
	stack_a = initialize_stack(ac, av);
	checker_bonus(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
