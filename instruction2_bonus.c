/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:24:09 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/07 16:25:57 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_ra(t_list **stack_a)
{
	if (rotate_stack(stack_a))
		return (1);
	return (0);
}

int	do_rb(t_list **stack_b)
{
	if (rotate_stack(stack_b))
		return (1);
	return (0);
}

int	do_rr(t_list **stack_a, t_list **stack_b)
{
	if (lstsize(*stack_a) < 2 || lstsize(*stack_b) < 2)
		return (1);
	if (rotate_stack(stack_a) || rotate_stack(stack_b))
		return (1);
	return (0);
}

int	do_sa(t_list **stack_a)
{
	if (swap_satck(stack_a))
		return (1);
	return (0);
}

int	do_sb(t_list **stack_b)
{
	if (!swap_satck(stack_b))
		return (1);
	return (0);
}
