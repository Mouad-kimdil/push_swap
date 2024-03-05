/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 05:22:17 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/05 22:13:45 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	t_list	*curr;

	if (!*stack)
		return ;
	if (lstsize(*stack) == 2)
	{
		sa(stack);
		return ;
	}
	curr = *stack;
	if (curr->data > curr->next->data && curr->data > curr->next->next->data)
		ra(stack);
	else if (curr->next->data > curr->data
		&& curr->next->data > curr->next->next->data)
		rra(stack);
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
}

void	calculate_costs(t_list **stack_a, t_list **stack_b)
{
	t_list	*curr_a;
	t_list	*curr_b;
	int		size_a;
	int		size_b;

	curr_a = *stack_a;
	curr_b = *stack_b;
	size_a = lstsize(curr_a);
	size_b = lstsize(curr_b);
	while (curr_b)
	{
		curr_b->cost_b = curr_b->pos;
		if (curr_b->pos > size_b / 2)
			curr_b->cost_b = (size_b - curr_b->pos) * -1;
		curr_b->cost_a = curr_b->target_pos;
		if (curr_b->target_pos > size_a / 2)
			curr_b->cost_a = (size_a - curr_b->target_pos) * -1;
		curr_b = curr_b->next;
	}
}

void	do_move(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		reverse_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	rotate_a(stack_a, &cost_a);
	rotate_b(stack_b, &cost_b);
	pa(stack_b, stack_a);
}

void	do_cheapest_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b) < ft_abs(cheapest))
		{
			cheapest = ft_abs(tmp->cost_b) + ft_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}
