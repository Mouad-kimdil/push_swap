/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:01:11 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/06 05:01:15 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_target(t_list **a, int b_idx, int target_idx, int target_pos)
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

void	get_target_position(t_list **a, t_list **b)
{
	t_list	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = calculate_target(a, tmp_b->idx, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}

void	get_position(t_list **stack)
{
	t_list	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

t_list	*get_stack_bottom(t_list *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stack_add_bottom(t_list **stack, t_list *new)
{
	t_list	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = get_stack_bottom(*stack);
	tail->next = new;
}
