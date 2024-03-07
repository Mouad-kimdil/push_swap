/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:19:01 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/07 18:52:04 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_pa(t_list **stack_a, t_list **stack_b)
{
	if (push_stack(stack_b, stack_a))
		return (1);
	return (0);
}

int	do_pb(t_list **stack_a, t_list **stack_b)
{
	if (push_stack(stack_a, stack_b))
		return (1);
	return (0);
}

int	do_rra(t_list **stack_a)
{
	if (reverse_rotate(stack_a))
		return (1);
	return (0);
}

int	do_rrb(t_list **stack_b)
{
	if (reverse_rotate(stack_b))
		return (1);
	return (0);
}

int	do_rrr(t_list **stack_a, t_list **stack_b)
{
	if (lstsize(*stack_a) < 2 || lstsize(*stack_b) < 2)
		return (1);
	if (reverse_rotate(stack_a) || reverse_rotate(stack_b))
		return (1);
	return (0);
}
