/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:01:54 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/15 14:57:58 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	save_three(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;
	int	pushed;

	stack_size = lstsize(*stack_a);
	pushed = 0;
	while (stack_size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	save_three(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		calculate_costs(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!last_check_sort(*stack_a))
		shift_stack(stack_a);
}
