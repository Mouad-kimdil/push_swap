/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 05:35:03 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/02 22:00:45 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_target_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*b;
	t_list	*a;
	int		next_biggest;
	int		pos;
	int		i;

	b = *stack_b;
	while (b)
	{
		a = *stack_a;
		next_biggest = 2147483647;
		pos = 0;
		i = 0;
		while (a)
		{
			if (a->data > b->data && a->data < next_biggest)
			{
				next_biggest = a->data;
				pos = i;
			}
			a = a->next;
			i++;
		}
		b->target_pos = pos;
		b = b->next;
	}
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
	t_list	*curr;

	curr = *stack_b;
	sort_three(stack_a);
	while (curr)
	{
		positioning(stack_a, stack_b);
		calculate_target_b(stack_a, stack_b);
		if (curr->target_pos > lstsize(*stack_a) / 2)
		{
			while (curr->target_pos++ < lstsize(*stack_a))
				rra(stack_a);
		}
		else
		{
			while (curr->target_pos-- > 0)
				ra(stack_a);
		}
		pa(stack_b, stack_a);
		curr = *stack_b;
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
