/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:45:48 by mkimdil           #+#    #+#             */
/*   Updated: 2024/02/23 22:25:28 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_list **stack)
{
	t_list *b_last = NULL;
	t_list *last;
	t_list *curr;

	if (lstsize(*stack) < 2)
		return (1);
	curr = *stack;
	while (curr->next)
	{
		if (curr->next->next == NULL)
			b_last = curr;
		curr = curr->next;
	}
	curr = *stack;
	last = lstlast(*stack);
	b_last->next = NULL;
	last->next = curr;
	*stack = last;
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (lstsize(*stack_a) < 2 || lstsize(*stack_b) < 2)
		return (1);
	if (rotate_stack(stack_a) || rotate_stack(stack_b))
		return (1);
	ft_putendl_fd("rr", 1);
	return (0);
}

int	rra(t_list **stack_a)
{
	if (reverse_rotate(stack_a))
		return (1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (reverse_rotate(stack_b))
		return (1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (lstsize(*stack_a) < 2 || lstsize(*stack_b) < 2)
		return (1);
	if (reverse_rotate(stack_a) || reverse_rotate(stack_b))
		return (1);
	ft_putendl_fd("rrr", 1);
	return (0);
}
