/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 05:22:17 by mkimdil           #+#    #+#             */
/*   Updated: 2024/02/24 06:21:15 by mkimdil          ###   ########.fr       */
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

int	check_min(t_list **stack)
{
	t_list	*curr;
	int		min_index;
	int		current_index;
	int		min_value;

	curr = *stack;
	if (!curr)
		return (0);
	min_index = 0;
	current_index = 0;
	min_value = curr->data;
	while (curr)
	{
		if (curr->data < min_value)
		{
			min_value = curr->data;
			min_index = current_index;
		}
		current_index++;
		curr = curr->next;
	}
	return (min_index);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*curr;
	int		i;

	if (!*stack_a)
		return ;
	curr = *stack_a;
	i = check_min(stack_a);
	if (i < 2)
	{
		while (i--)
			ra(stack_a);
	}
	else if (i >= 2)
	{
		while (i < 4)
		{
			rra(stack_a);
			i++;
		}
	}
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_b, stack_a);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*curr;
	int		i;

	if (!*stack_a)
		return ;
	curr = *stack_a;
	i = check_min(stack_a);
	if (i < 2)
	{
		while (i--)
			ra(stack_a);
	}
	else if (i >= 2)
	{
		while (i < 5)
		{
			rra(stack_a);
			i++;
		}
	}
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_b, stack_a);
}
