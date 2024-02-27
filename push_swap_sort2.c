/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 05:35:03 by mkimdil           #+#    #+#             */
/*   Updated: 2024/02/26 23:27:39 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_target_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		target_position;

	a = *stack_a;
	while (a)
	{
		b = *stack_b;
		target_position = 0;
		while (b)
		{
			if (b->data > a->data
			&& (target_position == 0 || b->pos < target_position))
				target_position = b->pos;
			b = b->next;
		}
		a->target_pos = target_position;
		a = a->next;
	}
}

void	calculate_target_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*b;
	t_list	*a;
	int		target_position;

	b = *stack_b;
	while (b)
	{
		a = *stack_a;
		target_position = 0;
		while (a)
		{
			if (a->data > b->data
			&& (target_position == 0 || a->pos < target_position))
				target_position = a->pos;
			a = a->next;
		}
		b->target_pos = target_position;
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
	sort_three(stack_a);
	positioning(stack_a, stack_b);
	calculate_target_a(stack_a, stack_b);
	calculate_target_b(stack_a, stack_b);
	// calculate_cheapest(stack_a, stack_b);
}

void	process_stack(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*curr;

	curr = *stack_a;
	while (curr)
	{
		if (curr->idx > (size - 3) && lstsize(*stack_a) > 3)
		{
			ra(stack_a);
			curr = *stack_a;
		}
		else if (lstsize(*stack_a) > 3)
		{
			pb(stack_a, stack_b);
			curr = *stack_a;
		}
		curr = curr->next;
	}
	cost_sort(stack_a, stack_b);
}

void	sort(t_list **stack_a, t_list **stack_b, int ac, char **av)
{
	int		size;
	char	**numbers;

	if (!stack_a || !*stack_a)
		return ;
	size = 0;
	if (ac < 2)
	{
		numbers = ft_split(av[1], ' ');
		while (numbers[size])
			size++;
	}
	else
		size = ac - 1;
	process_stack(stack_a, stack_b, size);
}
