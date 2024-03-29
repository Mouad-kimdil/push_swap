/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:01:44 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/07 16:44:09 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_stack_before_bottom(t_list *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

int	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;
	t_list	*before_tail;

	if (!stack || !*stack || !(*stack)->next)
		return (1);
	tail = lstlast(*stack);
	before_tail = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
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
