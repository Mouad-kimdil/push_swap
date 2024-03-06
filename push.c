/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 22:08:36 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/06 04:58:54 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_stack(t_list **stack_from, t_list **stack_to)
{
	t_list	*curr;

	if (lstsize(*stack_from) < 1)
		return (1);
	curr = *stack_from;
	*stack_from = (*stack_from)->next;
	curr->next = NULL;
	if (!*stack_to)
		*stack_to = curr;
	else
		lstadd_front(stack_to, curr);
	return (0);
}

int	pa(t_list **stack_b, t_list **stack_a)
{
	if (push_stack(stack_b, stack_a))
		return (1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push_stack(stack_a, stack_b))
		return (1);
	ft_putendl_fd("pb", 1);
	return (0);
}
