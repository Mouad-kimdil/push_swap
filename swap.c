/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkimdil <mkimdil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:13:37 by mkimdil           #+#    #+#             */
/*   Updated: 2024/03/06 00:50:57 by mkimdil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_satck(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		data;
	int		idx;

	head = *stack;
	next = head->next;
	if (!head || !next)
		return (1);
	data = head->data;
	idx = head->idx;
	head->data = next->data;
	head->idx = next->idx;
	next->data = data;
	next->idx = idx;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap_satck(stack_a))
		return (1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (!swap_satck(stack_b))
		return (1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (lstsize(*stack_a) < 2 || lstsize(*stack_b) < 2)
		return (1);
	if (swap_satck(stack_a) || swap_satck(stack_b))
		return (1);
	ft_putendl_fd("ss", 1);
	return (0);
}
