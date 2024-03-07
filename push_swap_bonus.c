/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:09:14 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/07 18:41:49 by mkimdil          ###   ########.fr       */
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
	if (last_check_sort(*stack_a))
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

void	print_stack(t_list *stack, int state)
{
	if (state == 0)
		printf("stack_a: ");
	else if (state == 1)
		printf("stack_b: ");
	if (!stack)
	{
		printf("is empty\n");
		return ;
	}
	while (stack)
	{
		printf("%d ", stack->data);
		stack = stack->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac < 2 || !checker(ac, av))
		return (0);
	stack_b = NULL;
	stack_a = initialize_stack(ac, av);
	checker_bonus(&stack_a, &stack_b);
}
