/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:29:32 by mkimdil           #+#    #+#             */
/*   Updated: 2024/02/20 13:40:29 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_stack(t_list *stack_from, t_list *stack_to)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (lstsize(stack_from) < 1)
		return (-1);
	head_from = stack_from;
	head_to = stack_to;
	tmp = head_from;
	head_from = head_from->next;
	stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		stack_to = tmp;
	}
	return (0);
}

int	pa(t_list *stack_a, t_list *stack_b)
{
	if (!push_stack(stack_a, stack_b))
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list *stack_b, t_list *stack_a)
{
	if (!push_stack(stack_b, stack_a))
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}
