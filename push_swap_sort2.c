/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 05:35:03 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/05 22:14:41 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_target_b(t_list **a, int b_idx, int target_idx, int target_pos)
{
	t_list	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->idx > b_idx && tmp_a->idx < target_idx)
		{
			target_idx = tmp_a->idx;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->idx < target_idx)
		{
			target_idx = tmp_a->idx;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

void	positioning(t_list **stack_a, t_list **stack_b)
{
	t_list	*curr;
	int		idx;

	idx = 0;
	curr = *stack_a;
	while (curr)
	{
		curr->pos = idx++;
		curr = curr->next;
	}
	curr = *stack_b;
	idx = 0;
	while (curr)
	{
		curr->pos = idx++;
		curr = curr->next;
	}
}

void	cost_sort(t_list **stack_a, t_list **stack_b)
{
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		calculate_costs(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
}

int	find_max(t_list *stack_a)
{
	int		max;
	t_list	*curr;

	max = -2147483648;
	curr = stack_a;
	while (curr)
	{
		if (curr->data > max)
			max = curr->data;
		curr = curr->next;
	}
	return (max);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int		max;
	t_list	*curr;

	max = find_max(*stack_a);
	while (lstsize(*stack_a) > 3)
	{
		curr = *stack_a;
		if (curr->data == max)
		{
			ra(stack_a);
			continue ;
		}
		pb(stack_a, stack_b);
	}
	cost_sort(stack_a, stack_b);
}
