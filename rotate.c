/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:01:48 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/07 19:08:41 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return (1);
	tmp = *stack;
	*stack = (*stack)->next;
	tail = lstlast(*stack);
	tmp->next = NULL;
	tail->next = tmp;
	return (0);
}

int	ra(t_list **stack_a)
{
	if (rotate_stack(stack_a))
		return (1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_list **stack_b)
{
	if (rotate_stack(stack_b))
		return (1);
	ft_putendl_fd("rb", 1);
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
